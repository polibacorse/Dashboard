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

private:
    bool debug_mode = false; // set here default debug mode

    int m_kph = 100;
    int m_rpm = 8000;
    int m_gear = 5;
    int m_fuel = 20;
    int m_oil_temp = 90;
    int m_oil_press = 50;
    int m_h2o = 80;

    QQmlApplicationEngine engine;
    MosquittoReceiver *receiver;
};

#endif // DASHBOARD_H
