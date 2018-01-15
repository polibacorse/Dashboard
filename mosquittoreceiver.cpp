#include "mosquittoreceiver.h"
#include <iostream> // For debug purposes

/*
 * Mosquitto Concstructor
 * Place here all actions that should be automated.
 */
MosquittoReceiver::MosquittoReceiver(QObject *parent) : QObject(parent), mosqpp::mosquittopp()
{
    this->mosquittopp::connect("127.0.0.1");
}

/*
 * on_connect callback
 * called when receiver has connected to mosquitto successfully.
 */
void MosquittoReceiver::on_connect(int return_code)
{
    if (!return_code)
        this->subscribe(NULL, "data/formatted/#");
}

/*
 * on_message callback
 * called when there is a new message incoming.
 */
void MosquittoReceiver::on_message(const struct mosquitto_message *message)
{
    std::cout << "Received message: " << (char *) message->payload << std::endl;
}
