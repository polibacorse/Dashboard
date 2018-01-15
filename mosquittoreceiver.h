#ifndef MOSQUITTORECEIVER_H
#define MOSQUITTORECEIVER_H

#include <QObject>
#include <mosquittopp.h>

class MosquittoReceiver : public QObject, mosqpp::mosquittopp
{
    Q_OBJECT
public:
    explicit MosquittoReceiver(QObject *parent = nullptr);

signals:
    // TODO: message arrived?

public slots:
    // TODO: change subscription between data/formatted/# and data/formatted/(specific topics)

private:
    void on_connect(int return_code);
    void on_message(const struct mosquitto_message*);
};

#endif // MOSQUITTORECEIVER_H
