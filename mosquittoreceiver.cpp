/*
 * Copyright (c) 2018 Poliba Corse
 * Authors: Giovanni Grieco <giovanni.grc96@gmail.com>
 *
 * Part of this code was inspired by
 *  - Alessandro Pezzato (https://github.com/alepez/MosQtitto)
 */

#include "mosquittoreceiver.h"
#include <mosquitto.h>

#include <QDebug>
#include <QJsonDocument>

namespace {

void on_connect_wrapper(struct mosquitto *, void *that, int rc) {
    MosquittoReceiver *m = reinterpret_cast<MosquittoReceiver *>(that);
    m->_onConnect(rc);
}

void on_disconnect_wrapper(struct mosquitto *, void *that, int rc) {
    MosquittoReceiver *m = reinterpret_cast<MosquittoReceiver *>(that);
    m->_onDisconnect(rc);
}

void on_message_wrapper(struct mosquitto*, void* that, const struct mosquitto_message* message) {
    MosquittoReceiver *m = reinterpret_cast<MosquittoReceiver *>(that);
    m->_onMessage(message);
}

std::string generateRandomClientId() {
    std::string id;

    id.resize(32);
    for (auto& c : id) {
        c = (::rand() % 25) + 'a';
    }

    return id;
}

} /* namespace */



MosquittoReceiver::MosquittoReceiver(QObject *parent) : QThread{parent}, isConnected_{false}
{
    mosquitto_lib_init();

    /* functions to forward signal with queued connection */
    auto onConnected = [this]() {
        isConnected_ = true;
        emit connected();
        emit isConnectedChanged();
    };

    auto onDisconnected = [this]() {
        isConnected_ = false;
        emit disconnected();
        emit isConnectedChanged();
    };

    auto onMessage = [this](QString topic, QJsonObject payload) {
        /* emit with queued connection */
        emit message(topic, payload);
    };

    /* QueuedConnection is needed, so allbacks are handled outside mosquitto thread */
    QObject::connect(this, &MosquittoReceiver::_connected, this, onConnected, Qt::QueuedConnection);
    QObject::connect(this, &MosquittoReceiver::_disconnected, this, onDisconnected, Qt::QueuedConnection);
    QObject::connect(this, &MosquittoReceiver::_message, this, onMessage, Qt::QueuedConnection);

    qInfo("Mosquitto receiver initialised.");
}

MosquittoReceiver::~MosquittoReceiver()
{
    /* Force disconnection and stop the thread */
    this->disconnect();

    mosquitto_lib_cleanup();
}

void MosquittoReceiver::connect()
{
    this->QThread::start();
}

void MosquittoReceiver::disconnect()
{
    continueRunning_ = false;

    if (!this->wait(2000)) {
        qWarning() << "Timeout while waiting for mosquitto disconnection.";
    }
}

void MosquittoReceiver::run()
{
    const std::string clientid = generateRandomClientId();

    int rc = 0;
    auto mosq = mosquitto_new(clientid.c_str(), true, this);

    if (!mosq) {
        std::runtime_error{"MosquittoReceiver: cannot instantiate mosquitto client."};
    }

    mosquitto_connect_callback_set(mosq, on_connect_wrapper);
    mosquitto_disconnect_callback_set(mosq, on_disconnect_wrapper);
    mosquitto_message_callback_set(mosq, on_message_wrapper);

    continueRunning_ = true;

    rc = mosquitto_connect(mosq, "localhost", 1883, 60);
    if (rc != MOSQ_ERR_SUCCESS) {
        qCritical() << "MosquittoReceiver: cannot connect!";
        mosquitto_destroy(mosq);

        return;
    }

    qInfo("MosquittoReceiver: connected. Start looping...");

    while (continueRunning_) {
        rc = mosquitto_loop(mosq, 500, 1); // we need high performance and quasi-realtime data elaboration

        if (continueRunning_ && rc) {
            qWarning() << "Mosquitto connection error. Thread will sleep.";
            QThread::sleep(1);
            mosquitto_reconnect(mosq);
        }

        mutex_.lock();

        while (!subscribeQueue_.isEmpty()) {
            const auto &topic = subscribeQueue_.dequeue();

            rc = mosquitto_subscribe(mosq, nullptr, topic.toStdString().c_str(), 0); // QoS 0: just stream it

            if (rc != MOSQ_ERR_SUCCESS) {
                //qCritical("MosquittoReceiver: cannot subscribe to topic");

            }
        }

        mutex_.unlock();
    }

    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
}

void MosquittoReceiver::_onConnect(int rc)
{
    if (rc != MOSQ_ERR_SUCCESS) {
        qWarning() << "Mosquitto connection failed!";
        return;
    }

    emit _connected();
}

void MosquittoReceiver::_onDisconnect(int rc)
{
    if (rc != MOSQ_ERR_SUCCESS) {
        qWarning() << "Mosquitto disconnected unexpectedly!";
    }

    emit _disconnected();
}

void MosquittoReceiver::subscribe(QString topic)
{
    qInfo() << "Subscribing to " << topic;

    mutex_.lock();
    subscribeQueue_.enqueue(topic);
    mutex_.unlock();
}

void MosquittoReceiver::_onMessage(const mosquitto_message *message)
{
    QString topic{message->topic};
    QByteArray payload{reinterpret_cast<const char *>(message->payload), message->payloadlen};

    try {
        qInfo() << "Message arrived from " << topic;
        QString message{payload};
        qInfo() << "Message arrived " << message;
        auto jdoc = QJsonDocument::fromJson(payload);
        auto jpayload = jdoc.object();

        // qInfo() << "Message arrived from " << topic;

        emit _message(topic, jpayload);
    } catch (...) {
        qWarning("Something happened during json message parsing.");
    }
}
