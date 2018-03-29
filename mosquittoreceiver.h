/*
 * Copyright (c) 2018 Poliba Corse
 * Authors: Giovanni Grieco <giovanni.grc96@gmail.com>
 *
 * Part of this code have been inspired by
 *  - Alessandro Pezzato (https://github.com/alepez/MosQtitto)
 */

#ifndef MOSQUITTORECEIVER_H
#define MOSQUITTORECEIVER_H

#include <QJsonObject>
#include <QMutex>
#include <QQueue>
#include <QString>
#include <QThread>

struct mosquitto_message;

class MosquittoReceiver : public QThread
{
    Q_OBJECT
    Q_PROPERTY(bool isConnected MEMBER isConnected_ NOTIFY isConnectedChanged)

public:
    explicit MosquittoReceiver(QObject *parent = nullptr);
    virtual ~MosquittoReceiver();

    Q_INVOKABLE void connect();
    Q_INVOKABLE void disconnect();
    Q_INVOKABLE void subscribe(QString topic);

signals:
    void connected();
    void disconnected();
    void message(QString topic, QJsonObject payload);

    void isConnectedChanged();

    /* internal */
    void _connected();
    void _disconnected();
    void _message(QString topic, QJsonObject payload);

public: /* internal */
    void _onConnect(int);
    void _onDisconnect(int);
    void _onMessage(const struct mosquitto_message*);

public slots:
    // TODO: change subscription between data/formatted/# and data/formatted/(specific topics)

private:
    void run();

    QMutex mutex_;
    QQueue<QString> subscribeQueue_;
    bool isConnected_;
    bool continueRunning_;
};

#endif // MOSQUITTORECEIVER_H
