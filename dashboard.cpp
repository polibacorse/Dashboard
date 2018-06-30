#include "dashboard.h"
#include "QQmlContext"
#include <QDebug>

Dashboard::Dashboard(QObject *parent) : QObject(parent)
{    
    qInfo("Initialising Mosquitto receiver.");
    this->receiver = new MosquittoReceiver(this);
    receiver->connect();
    connect(receiver, SIGNAL(message(QString, QJsonObject)), this, SLOT(update(QString,QJsonObject)));
    connect(receiver, SIGNAL(connected()), this, SLOT(mosquitto_connected()));
    connect(receiver, SIGNAL(disconnected()), this, SLOT(mosquitto_disconnected()));

    receiver->subscribe(kph_topic);
    receiver->subscribe(rpm_topic);
    receiver->subscribe(fuel_topic);
    receiver->subscribe(gear_topic);
    receiver->subscribe(oil_press_topic);
    receiver->subscribe(oil_temp_topic);
    receiver->subscribe(h2o_topic);

    qInfo("Initialising GUI Engine.");
    engine.rootContext()->setContextProperty("dashboardValues", this);
    engine.load(QUrl(QStringLiteral("qrc:/text_dashboard.qml")));
    if (engine.rootObjects().isEmpty())
        qCritical("GUI Engine not initialised correctly!");
}

void Dashboard::mosquitto_connected(){
    qInfo("Mosquitto receiver connected.");
}

void Dashboard::mosquitto_disconnected(){
    qCritical("Mosquitto receiver disconnected");
}

void Dashboard::update(QString topic, QJsonObject data)
{
    //qInfo() << data.toString();
    // Topics
    QString kph = "kph";
    QString rpm = "rpm";
    QString gear = "gear";
    QString fuel = "fuel";
    QString oil_temp = "oil_temp";
    QString oil_press = "oil_press";
    QString h2o = "h2o";

    if(QString::compare(topic, kph_topic, Qt::CaseSensitive) == 0){
        setKph(data["value"].toInt());
        qInfo() << data["value"];

    }else if(QString::compare(topic, rpm_topic, Qt::CaseSensitive) == 0){
        setRpm(data["value"].toInt());
        qInfo() << data["value"];

    }else if(QString::compare(topic, gear_topic, Qt::CaseSensitive) == 0){
        setGear(data["value"].toInt());
        qInfo() << data["value"];

    }else if(QString::compare(topic, fuel_topic, Qt::CaseSensitive) == 0){
        setFuel(data["value"].toInt());
        qInfo() << data["value"];

    }else if(QString::compare(topic, oil_temp_topic, Qt::CaseSensitive) == 0){
        setOil_temp(data["value"].toInt());
        qInfo() << data["value"];

    }else if(QString::compare(topic, oil_press_topic, Qt::CaseSensitive) == 0){
        setOil_press(data["value"].toInt());
        qInfo() << data["value"];

    }else if(QString::compare(topic, h2o_topic, Qt::CaseSensitive) == 0){
        setH2o(data["value"].toInt());
        qInfo() << data["value"];
    }
}

quint32 Dashboard::resolutionWidth() const {
    return mResolutionWidth;
}

quint32 Dashboard::resolutionHeight() const {
    return mResolutionHeight;
}

void Dashboard::setKph(const int &newValue)
{
    if (newValue != m_kph) {
        m_kph = newValue;
        emit kphChanged();
    }
}

int Dashboard::kph() const {
    return m_kph;
}

void Dashboard::setRpm(const int &newValue)
{
    if (newValue != m_rpm) {
        m_rpm = newValue;
        emit rpmChanged();
    }
}

int Dashboard::rpm() const {
    return m_rpm;
}

void Dashboard::setGear(const int &newValue)
{
    if (newValue != m_rpm) {
        m_gear = newValue;
        emit gearChanged();
    }
}

int Dashboard::gear() const {
    return m_gear;
}

void Dashboard::setFuel(const int &newValue)
{
    if (newValue != m_fuel) {
        m_fuel = newValue;
        emit fuelChanged();
    }
}

int Dashboard::fuel() const {
    return m_fuel;
}

void Dashboard::setOil_press(const int &newValue)
{
    if (newValue != m_oil_press) {
        m_oil_press = newValue;
        emit oil_pressChanged();
    }
}

int Dashboard::oil_press() const {
    return m_oil_press;
}

void Dashboard::setOil_temp(const int &newValue)
{
    if (newValue != m_oil_temp) {
        m_oil_temp = newValue;
        emit oil_tempChanged();
    }
}

int Dashboard::oil_temp() const {
    return m_oil_temp;
}

void Dashboard::setH2o(const int &newValue)
{
    if (newValue != m_h2o) {
        m_h2o = newValue;
        emit h2oChanged();
    }
}

int Dashboard::h2o() const {
    return m_h2o;
}

