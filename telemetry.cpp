#include "telemetry.h"
#include "QQmlContext"
#include "QTimer"
#include <QDebug>

Telemetry::Telemetry(QObject *parent) : QObject(parent)
{    
    qInfo("Initialising Mosquitto receiver.");
    this->receiver = new MosquittoReceiver(this);
    receiver->connect();
    connect(receiver, SIGNAL(message(QString, QJsonObject)), this, SLOT(update(QString,QJsonObject)));
    connect(receiver, SIGNAL(connected()), this, SLOT(mosquitto_connected()));
    connect(receiver, SIGNAL(disconnected()), this, SLOT(mosquitto_disconnected()));

    //receiver->subscribe();
    int len = sizeof(topics)/sizeof(*topics);

    for(int i = 0; i < len; i++){
        if(topics[26] != "" && topics[i] != NULL)
            receiver->subscribe(topics[i]);
    }

    qInfo("Initialising GUI Engine.");
    engine.rootContext()->setContextProperty("dashboardValues", this);
    engine.load(QUrl(QStringLiteral("qrc:/text_telemetry.qml")));
    if (engine.rootObjects().isEmpty())
        qCritical("GUI Engine not initialised correctly!");

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateSensorsGUI()));
    timer->start(1000);

}

void Telemetry::mosquitto_connected(){
    qInfo("Mosquitto receiver connected.");
}

void Telemetry::mosquitto_disconnected(){
    qCritical("Mosquitto receiver disconnected");
}

void Telemetry::updateSensorsGUI(){
    emit valuesChanged();
}

void Telemetry::update(QString topic, QJsonObject data)
{
    //qInfo() << data.toString();

    if(QString::compare(topic, topics[32], Qt::CaseSensitive) == 0){
        setKph(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[26], Qt::CaseSensitive) == 0){
        setRpm(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[40], Qt::CaseSensitive) == 0){
        setGear(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[43], Qt::CaseSensitive) == 0){
        setFuel(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[56], Qt::CaseSensitive) == 0){
        setOil_temp(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[42], Qt::CaseSensitive) == 0){
        setOil_press(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[55], Qt::CaseSensitive) == 0){
        setH2o(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[0], Qt::CaseSensitive) == 0){
        setA1x(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[1], Qt::CaseSensitive) == 0){
        setA1y(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[2], Qt::CaseSensitive) == 0){
        setsteerPos(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[3], Qt::CaseSensitive) == 0){
        setFLdamp(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[4], Qt::CaseSensitive) == 0){
        setFRdamp(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[5], Qt::CaseSensitive) == 0){
        setRLdamp(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[6], Qt::CaseSensitive) == 0){
        setRRdamp(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[7], Qt::CaseSensitive) == 0){
        setCurrent1(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[8], Qt::CaseSensitive) == 0){
        setCurrent2(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[9], Qt::CaseSensitive) == 0){
        setSlip_ok(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[10], Qt::CaseSensitive) == 0){
        setAuto_acc_flag(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[11], Qt::CaseSensitive) == 0){
        setDebug_mode(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[12], Qt::CaseSensitive) == 0){
        setDatalog_on_off(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[13], Qt::CaseSensitive) == 0){
        setTelemetria_on_off(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[14], Qt::CaseSensitive) == 0){
        setLapClose(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[15], Qt::CaseSensitive) == 0){
        setTarget_rpm_up(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[16], Qt::CaseSensitive) == 0){
        setShift_duration(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[17], Qt::CaseSensitive) == 0){
        setTime_0_100(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[18], Qt::CaseSensitive) == 0){
        setTime_0_75(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[19], Qt::CaseSensitive) == 0){
        setAltitude(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[20], Qt::CaseSensitive) == 0){
        setGPS_speed(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[21], Qt::CaseSensitive) == 0){
        setSatellite(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[22], Qt::CaseSensitive) == 0){
        setFix(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[23], Qt::CaseSensitive) == 0){
        setGps_time(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[24], Qt::CaseSensitive) == 0){
        setLatitude(data["value"].toDouble());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[25], Qt::CaseSensitive) == 0){
        setLongitude(data["value"].toDouble());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[27], Qt::CaseSensitive) == 0){
        setTps(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[28], Qt::CaseSensitive) == 0){
        setMap(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[29], Qt::CaseSensitive) == 0){
        setLambda(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[30], Qt::CaseSensitive) == 0){
        setDerivata_farfalla(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[31], Qt::CaseSensitive) == 0){
        setDmap(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[33], Qt::CaseSensitive) == 0){
        setDrAxSpeed(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[34], Qt::CaseSensitive) == 0){
        setSlip_Calc(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[35], Qt::CaseSensitive) == 0){
        setOSASlip(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[36], Qt::CaseSensitive) == 0){
        setTerog_piano_quotato(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[37], Qt::CaseSensitive) == 0){
        setTerog(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[38], Qt::CaseSensitive) == 0){
        setSABase(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[39], Qt::CaseSensitive) == 0){
        setSA(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[41], Qt::CaseSensitive) == 0){
        setGearShiftTimeRemaine(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[44], Qt::CaseSensitive) == 0){
        setBaro(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[45], Qt::CaseSensitive) == 0){
        setVBattDir(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[46], Qt::CaseSensitive) == 0){
        setVBattKey(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[47], Qt::CaseSensitive) == 0){
        setLNR1I(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[48], Qt::CaseSensitive) == 0){
        setLNR2I(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[49], Qt::CaseSensitive) == 0){
        setLNR7I(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[50], Qt::CaseSensitive) == 0){
        setLNR8I(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[51], Qt::CaseSensitive) == 0){
        setLNR5I(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[52], Qt::CaseSensitive) == 0){
        setLNR6I(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[53], Qt::CaseSensitive) == 0){
        setLNR3I(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[54], Qt::CaseSensitive) == 0){
        setLNR4I(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[57], Qt::CaseSensitive) == 0){
        setTMP(data["value"].toInt());
        //qInfo() << data["value"];

    }else if(QString::compare(topic, topics[58], Qt::CaseSensitive) == 0){
        setTair(data["value"].toInt());
        //qInfo() << data["value"];

    }

}


void Telemetry::setKph(const int &newValue)
{
    if (newValue != m_kph) {
        m_kph = newValue;
        float range = (float) (max_kph - min_kph);
        float val = m_kph;
        p_kph = val/range;
        if(p_kph > 1){
            p_kph= 1.0;
        }
        emit kphChanged();
        emit percentKphChanged();
    }
}

int Telemetry::kph() const {
    return m_kph;
}

float Telemetry::percent_kph() const {
    return p_kph;
}

void Telemetry::setRpm(const int &newValue)
{
    if (newValue != m_rpm) {
        m_rpm = newValue;
        float range = (float) (max_rpm - min_rpm);
        float val = m_rpm;
        p_rpm = val/range;
        if(p_rpm > 1){
            p_rpm = 1.0;
        }
        emit rpmChanged();
        emit percentRpmChanged();
    }
}

int Telemetry::rpm() const {
    return m_rpm;
}

float Telemetry::percent_rpm() const {
    return p_rpm;
}

void Telemetry::setGear(const int &newValue)
{
    if (newValue != m_rpm) {
        m_gear = newValue;
        emit gearChanged();
    }
}

int Telemetry::gear() const {
    return m_gear;
}

void Telemetry::setFuel(const int &newValue)
{
    if (newValue != m_fuel) {
        m_fuel = newValue;
        float range = (float) (max_fuel - min_fuel);
        float val = m_fuel;
        p_fuel = val/range;
        if(p_fuel > 1){
            p_fuel = 1.0;
        }
        emit fuelChanged();
        emit percentFuelChanged();
    }
}

int Telemetry::fuel() const {
    return m_fuel;
}

float Telemetry::percent_fuel() const {
    return p_fuel;
}

void Telemetry::setOil_press(const int &newValue)
{
    if (newValue != m_oil_press) {
        m_oil_press = newValue;
        float range = (float) (max_oil_press - min_oil_press);
        float val = m_oil_press;
        p_oil_press = val/range;
        if(p_oil_press > 1){
            p_oil_press = 1.0;
        }
        emit oil_pressChanged();
        emit percent_oil_pressChanged();
    }
}

int Telemetry::oil_press() const {
    return m_oil_press;
}

float Telemetry::percent_oil_press() const {
    return p_oil_press;
}

void Telemetry::setOil_temp(const int &newValue)
{
    if (newValue != m_oil_temp) {
        m_oil_temp = newValue;
        float range = (float) (max_oil_temp - min_oil_temp);
        float val = m_oil_temp;
        p_oil_temp = val/range;
        if(p_oil_temp > 1){
            p_oil_temp = 1.0;
        }
        emit oil_tempChanged();
        emit percent_oil_tempChanged();
    }
}

int Telemetry::oil_temp() const {
    return m_oil_temp;
}

float Telemetry::percent_oil_temp() const {
    return p_oil_temp;
}

void Telemetry::setH2o(const int &newValue)
{
    if (newValue != m_h2o) {
        m_h2o = newValue;
        float range = (float) (max_h2o - min_h2o);
        float val = m_h2o;
        p_h2o = val/range;
        if(p_h2o > 1){
            p_h2o = 1.0;
        }
        emit h2oChanged();
        emit percentH2oChanged();
    }
}

int Telemetry::h2o() const {
    return m_h2o;
}

float Telemetry::percent_h2o() const {
    return p_h2o;
}

void Telemetry::setA1x(const int &newValue)
{
     m_a1x = newValue;
}

int Telemetry::a1x() const {
    return m_a1x;
}

void Telemetry::setA1y(const int &newValue)
{
    m_a1y = newValue;
}

int Telemetry::a1y() const {
    return m_a1y;
}

void Telemetry::setsteerPos(const int &newValue)
{
    m_steerPos = newValue;
}

int Telemetry::steerPos() const {
    return m_steerPos;
}

void Telemetry::setFLdamp(const int &newValue)
{
    m_FLdamp = newValue;
}

int Telemetry::FLdamp() const {
    return m_FLdamp;
}

void Telemetry::setFRdamp(const int &newValue)
{
    m_FRdamp = newValue;
}

int Telemetry::FRdamp() const {
    return m_FRdamp;
}

void Telemetry::setRLdamp(const int &newValue)
{
    m_RLdamp = newValue;
}

int Telemetry::RLdamp() const {
    return m_RLdamp;
}

void Telemetry::setRRdamp(const int &newValue)
{
    m_RRdamp = newValue;
}

int Telemetry::RRdamp() const {
    return m_RRdamp;
}

void Telemetry::setCurrent1(const int &newValue)
{
    m_current1 = newValue;
}

int Telemetry::current1() const {
    return m_current1;
}

void Telemetry::setCurrent2(const int &newValue)
{
    m_current2 = newValue;
}

int Telemetry::current2() const {
    return m_current2;
}

void Telemetry::setSlip_ok(const int &newValue)
{
    m_slip_ok = newValue;
}

int Telemetry::slip_ok() const {
    return m_slip_ok;
}

void Telemetry::setAuto_acc_flag(const int &newValue)
{
    m_auto_acc_flag = newValue;
}

int Telemetry::auto_acc_flag() const {
    return m_auto_acc_flag;
}

void Telemetry::setDebug_mode(const int &newValue)
{
    m_debug_mode = newValue;
}

int Telemetry::debugMode() const {
    return m_debug_mode;
}

void Telemetry::setDatalog_on_off(const int &newValue)
{
    m_datalog_on_off = newValue;
}

int Telemetry::datalog_on_off() const {
    return m_datalog_on_off;
}

void Telemetry::setTelemetria_on_off(const int &newValue)
{
    m_telemetria_on_off = newValue;
}

int Telemetry::telemetria_on_off() const {
    return m_telemetria_on_off;
}

void Telemetry::setLapClose(const int &newValue)
{
    m_lapClose = newValue;
}

int Telemetry::lapClose() const {
    return m_lapClose;
}

void Telemetry::setTarget_rpm_up(const int &newValue)
{
    m_target_rpm_up = newValue;
}

int Telemetry::target_rpm_up() const {
    return m_target_rpm_up;
}

void Telemetry::setShift_duration(const int &newValue)
{
    m_shift_duration = newValue;
}

int Telemetry::shift_duration() const {
    return m_shift_duration;
}

void Telemetry::setTime_0_100(const int &newValue)
{
    m_time_0_100 = newValue;
}

int Telemetry::time_0_100() const {
    return m_time_0_100;
}

void Telemetry::setTime_0_75(const int &newValue)
{
    m_time_0_75 = newValue;
}

int Telemetry::time_0_75() const {
    return m_time_0_75;
}

void Telemetry::setAltitude(const int &newValue)
{
    m_altitude = newValue;
}

int Telemetry::altitude() const {
    return m_altitude;
}

void Telemetry::setGPS_speed(const int &newValue)
{
    m_GPS_speed = newValue;
}

int Telemetry::GPS_speed() const {
    return m_GPS_speed;
}

void Telemetry::setSatellite(const int &newValue)
{
    m_satellite = newValue;
}

int Telemetry::satellite() const {
    return m_satellite;
}

void Telemetry::setFix(const int &newValue)
{
    m_fix = newValue;
}

int Telemetry::fix() const {
    return m_fix;
}

void Telemetry::setGps_time(const int &newValue)
{
    m_gps_time = newValue;
}

int Telemetry::gps_time() const {
    return m_gps_time;
}

void Telemetry::setLatitude(const double &newValue)
{
    m_latitude = newValue;
}

double Telemetry::latitude() const {
    return m_latitude;
}

void Telemetry::setLongitude(const double &newValue)
{
    m_longitude = newValue;
}

double Telemetry::longitude() const {
    return m_longitude;
}

void Telemetry::setCenterLatitude(const double &newValue)
{
    m_center_latitude = newValue;
}

double Telemetry::center_latitude() const {
    return m_center_latitude;
}

void Telemetry::setCenterLongitude(const double &newValue)
{
    m_center_longitude = newValue;
}

double Telemetry::center_longitude() const {
    return m_center_longitude;
}

void Telemetry::setTps(const int &newValue)
{
    m_tps = newValue;
}

int Telemetry::tps() const {
    return m_tps;
}

void Telemetry::setMap(const int &newValue)
{
    m_map = newValue;
}

int Telemetry::map() const {
    return m_map;
}

void Telemetry::setLambda(const int &newValue)
{
    m_lambda = newValue;
}

int Telemetry::lambda() const {
    return m_lambda;
}

void Telemetry::setDerivata_farfalla(const int &newValue)
{
    m_derivata_farfalla = newValue;
}

int Telemetry::derivata_farfalla() const {
    return m_derivata_farfalla;
}

void Telemetry::setDmap(const int &newValue)
{
    m_dmap = newValue;
}

int Telemetry::dmap() const {
    return m_dmap;
}

void Telemetry::setDrAxSpeed(const int &newValue)
{
    m_drAxSpeed = newValue;
}

int Telemetry::drAxSpeed() const {
    return m_drAxSpeed;
}

void Telemetry::setSlip_Calc(const int &newValue)
{
    m_slip_Calc = newValue;
}

int Telemetry::slip_Calc() const {
    return m_slip_Calc;
}

void Telemetry::setOSASlip(const int &newValue)
{
    m_OSASlip = newValue;
}

int Telemetry::OSASlip() const {
    return m_OSASlip;
}

void Telemetry::setTerog_piano_quotato(const int &newValue)
{
    m_terog_piano_quotato = newValue;
}

int Telemetry::terog_piano_quotato() const {
    return m_terog_piano_quotato;
}

void Telemetry::setTerog(const int &newValue)
{
    m_terog = newValue;
}

int Telemetry::terog() const {
    return m_terog;
}

void Telemetry::setSABase(const int &newValue)
{
    m_SABase = newValue;
}

int Telemetry::SABase() const {
    return m_SABase;
}

void Telemetry::setSA(const int &newValue)
{
    m_SA = newValue;
}

int Telemetry::SA() const {
    return m_SA;
}

void Telemetry::setGearShiftTimeRemaine(const int &newValue)
{
    m_gearShiftTimeRemaine = newValue;
}

int Telemetry::gearShiftTimeRemaine() const {
    return m_gearShiftTimeRemaine;
}

void Telemetry::setBaro(const int &newValue)
{
    m_baro = newValue;
}

int Telemetry::baro() const {
    return m_baro;
}

void Telemetry::setVBattKey(const int &newValue)
{
    m_vBattKey = newValue;
}

int Telemetry::vBattKey() const {
    return m_vBattKey;
}

void Telemetry::setVBattDir(const int &newValue)
{
    m_vBattDir = newValue;
}

int Telemetry::vBattDir() const {
    return m_vBattDir;
}

void Telemetry::setLNR1I(const int &newValue)
{
    m_LNR1I = newValue;
}

int Telemetry::LNR1I() const {
    return m_LNR1I;
}

void Telemetry::setLNR2I(const int &newValue)
{
    m_LNR2I = newValue;
}

int Telemetry::LNR2I() const {
    return m_LNR2I;
}

void Telemetry::setLNR7I(const int &newValue)
{
    m_LNR7I = newValue;
}

int Telemetry::LNR7I() const {
    return m_LNR7I;
}

void Telemetry::setLNR8I(const int &newValue)
{
    m_LNR8I = newValue;
}

int Telemetry::LNR8I() const {
    return m_LNR8I;
}

void Telemetry::setLNR5I(const int &newValue)
{
    m_LNR5I = newValue;
}

int Telemetry::LNR5I() const {
    return m_LNR5I;
}

void Telemetry::setLNR6I(const int &newValue)
{
    m_LNR6I = newValue;
}

int Telemetry::LNR6I() const {
    return m_LNR6I;
}

void Telemetry::setLNR3I(const int &newValue)
{
    m_LNR3I = newValue;
}

int Telemetry::LNR3I() const {
    return m_LNR3I;
}

void Telemetry::setLNR4I(const int &newValue)
{
    m_LNR4I = newValue;
}

int Telemetry::LNR4I() const {
    return m_LNR4I;
}

void Telemetry::setTMP(const int &newValue)
{
    m_TMP = newValue;
}

int Telemetry::TMP() const {
    return m_TMP;
}

void Telemetry::setTair(const int &newValue)
{
    m_tair = newValue;
}

int Telemetry::tair() const {
    return m_tair;
}



