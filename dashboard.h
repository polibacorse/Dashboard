#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QObject>
#include <QQmlApplicationEngine>

#include "mosquittoreceiver.h"

class Dashboard : public QObject
{
    Q_OBJECT
public:
    explicit Dashboard(QObject *parent = nullptr);

    Q_PROPERTY(quint32 resolutionWidth READ resolutionWidth)
    quint32 resolutionWidth() const;

    Q_PROPERTY(quint32 resolutionHeight READ resolutionHeight)
    quint32 resolutionHeight() const;

    Q_PROPERTY(int kph READ kph WRITE setKph NOTIFY kphChanged)
    void setKph(const int &);
    int kph() const;

    Q_PROPERTY(int rpm READ rpm WRITE setRpm NOTIFY rpmChanged)
    void setRpm(const int &);
    int rpm() const;

    Q_PROPERTY(int gear READ gear WRITE setGear NOTIFY gearChanged)
    void setGear(const int &);
    int gear() const;

    Q_PROPERTY(int fuel READ fuel WRITE setFuel NOTIFY fuelChanged)
    void setFuel(const int &);
    int fuel() const;

    Q_PROPERTY(int oil_temp READ oil_temp WRITE setOil_temp NOTIFY oil_tempChanged)
    void setOil_temp(const int &);
    int oil_temp() const;

    Q_PROPERTY(int oil_press READ oil_press WRITE setOil_press NOTIFY oil_pressChanged)
    void setOil_press(const int &);
    int oil_press() const;

    Q_PROPERTY(int h2o READ h2o WRITE setH2o NOTIFY h2oChanged)
    void setH2o(const int &);
    int h2o() const;

signals:
    void kphChanged();
    void rpmChanged();
    void gearChanged();
    void fuelChanged();
    void oil_tempChanged();
    void oil_pressChanged();
    void h2oChanged();

public slots:
    void update(QString topic, QJsonObject data);
    void mosquitto_connected();
    void mosquitto_disconnected();

private:
    QString kph_topic = "data/formatted/vhspeed";
    QString rpm_topic = "data/formatted/rpm";
    QString gear_topic = "data/formatted/gear";
    QString fuel_topic = "data/formatted/pfuel";
    QString oil_temp_topic = "data/formatted/toil";
    QString oil_press_topic = "data/formatted/poil";
    QString h2o_topic = "data/formatted/th2o";

    bool debug_mode = false; // set here default debug mode

    const quint32 mResolutionWidth = 1024;
    const quint32 mResolutionHeight = 600;
    int m_kph = 0;
    int m_rpm = 0;
    int m_gear = 0;
    int m_fuel = 0;
    int m_oil_temp = 0;
    int m_oil_press = 0;
    int m_h2o = 0;

    QQmlApplicationEngine engine;
    MosquittoReceiver *receiver;
};

#endif // DASHBOARD_H
