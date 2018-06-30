#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <QObject>
#include <QQmlApplicationEngine>

#include "mosquittoreceiver.h"

class Telemetry : public QObject
{
    Q_OBJECT
public:
    explicit Telemetry(QObject *parent = nullptr);

    Q_PROPERTY(int kph READ kph WRITE setKph NOTIFY kphChanged )
    void setKph(const int &);
    int kph() const;
    Q_PROPERTY(double percent_kph READ percent_kph NOTIFY percentKphChanged)
    float percent_kph() const;

    Q_PROPERTY(int rpm READ rpm WRITE setRpm NOTIFY rpmChanged)
    void setRpm(const int &);
    int rpm() const;
    Q_PROPERTY(double percent_rpm READ percent_rpm NOTIFY percentRpmChanged)
    float percent_rpm() const;

    Q_PROPERTY(int gear READ gear WRITE setGear NOTIFY gearChanged)
    void setGear(const int &);
    int gear() const;

    Q_PROPERTY(int fuel READ fuel WRITE setFuel NOTIFY fuelChanged)
    void setFuel(const int &);
    int fuel() const;
    Q_PROPERTY(double percent_fuel READ percent_fuel NOTIFY percentFuelChanged)
    float percent_fuel() const;

    Q_PROPERTY(int oil_temp READ oil_temp WRITE setOil_temp NOTIFY oil_tempChanged)
    void setOil_temp(const int &);
    int oil_temp() const;
    Q_PROPERTY(double percent_oil_temp READ percent_oil_temp NOTIFY percent_oil_tempChanged)
    float percent_oil_temp() const;

    Q_PROPERTY(int oil_press READ oil_press WRITE setOil_press NOTIFY oil_pressChanged)
    void setOil_press(const int &);
    int oil_press() const;
    Q_PROPERTY(double percent_oil_press READ percent_oil_press NOTIFY percent_oil_pressChanged)
    float percent_oil_press() const;

    Q_PROPERTY(int h2o READ h2o WRITE setH2o NOTIFY h2oChanged)
    void setH2o(const int &);
    int h2o() const;
    Q_PROPERTY(double percent_h2o READ percent_h2o NOTIFY percentH2oChanged)
    float percent_h2o() const;

    Q_PROPERTY(int a1x READ a1x WRITE setA1x NOTIFY valuesChanged)
    void setA1x(const int &);
    int a1x() const;

    Q_PROPERTY(int a1y READ a1y WRITE setA1y NOTIFY valuesChanged)
    void setA1y(const int &);
    int a1y() const;

    Q_PROPERTY(int steerPos READ steerPos WRITE setsteerPos NOTIFY valuesChanged)
    void setsteerPos(const int &);
    int steerPos() const;

    Q_PROPERTY(int FLdamp READ FLdamp WRITE setFLdamp NOTIFY valuesChanged)
    void setFLdamp(const int &);
    int FLdamp() const;

    Q_PROPERTY(int FRdamp READ FRdamp WRITE setFRdamp NOTIFY valuesChanged)
    void setFRdamp(const int &);
    int FRdamp() const;

    Q_PROPERTY(int RLdamp READ RLdamp WRITE setRLdamp NOTIFY valuesChanged)
    void setRLdamp(const int &);
    int RLdamp() const;

    Q_PROPERTY(int RRdamp READ RRdamp WRITE setRRdamp NOTIFY valuesChanged)
    void setRRdamp(const int &);
    int RRdamp() const;

    Q_PROPERTY(int current1 READ current1 WRITE setCurrent1 NOTIFY valuesChanged)
    void setCurrent1(const int &);
    int current1() const;

    Q_PROPERTY(int current2 READ current2 WRITE setCurrent2 NOTIFY valuesChanged)
    void setCurrent2(const int &);
    int current2() const;

    Q_PROPERTY(int slip_ok READ slip_ok WRITE setSlip_ok NOTIFY valuesChanged)
    void setSlip_ok(const int &);
    int slip_ok() const;

    Q_PROPERTY(int auto_acc_flag READ auto_acc_flag WRITE setAuto_acc_flag NOTIFY valuesChanged)
    void setAuto_acc_flag(const int &);
    int auto_acc_flag() const;

    Q_PROPERTY(int debugMode READ debugMode WRITE setDebug_mode NOTIFY valuesChanged)
    void setDebug_mode(const int &);
    int debugMode() const;

    Q_PROPERTY(int datalog_on_off READ datalog_on_off WRITE setDatalog_on_off NOTIFY valuesChanged)
    void setDatalog_on_off(const int &);
    int datalog_on_off() const;

    Q_PROPERTY(int telemetria_on_off READ telemetria_on_off WRITE setTelemetria_on_off NOTIFY valuesChanged)
    void setTelemetria_on_off(const int &);
    int telemetria_on_off() const;

    Q_PROPERTY(int lapClose READ lapClose WRITE setLapClose NOTIFY valuesChanged)
    void setLapClose(const int &);
    int lapClose() const;

    Q_PROPERTY(int target_rpm_up READ target_rpm_up WRITE setTarget_rpm_up NOTIFY valuesChanged)
    void setTarget_rpm_up(const int &);
    int target_rpm_up() const;

    Q_PROPERTY(int shift_duration READ shift_duration WRITE setShift_duration NOTIFY valuesChanged)
    void setShift_duration(const int &);
    int shift_duration() const;

    Q_PROPERTY(int time_0_100 READ time_0_100 WRITE setTime_0_100 NOTIFY valuesChanged)
    void setTime_0_100(const int &);
    int time_0_100() const;

    Q_PROPERTY(int time_0_75 READ time_0_75 WRITE setTime_0_75 NOTIFY valuesChanged)
    void setTime_0_75(const int &);
    int time_0_75() const;

    Q_PROPERTY(int altitude READ altitude WRITE setAltitude NOTIFY valuesChanged)
    void setAltitude(const int &);
    int altitude() const;

    Q_PROPERTY(int GPS_speed READ GPS_speed WRITE setGPS_speed NOTIFY valuesChanged)
    void setGPS_speed(const int &);
    int GPS_speed() const;

    Q_PROPERTY(int satellite READ satellite WRITE setSatellite NOTIFY valuesChanged)
    void setSatellite(const int &);
    int satellite() const;

    Q_PROPERTY(int fix READ fix WRITE setFix NOTIFY valuesChanged)
    void setFix(const int &);
    int fix() const;

    Q_PROPERTY(int gps_time READ gps_time WRITE setGps_time NOTIFY valuesChanged)
    void setGps_time(const int &);
    int gps_time() const;

    Q_PROPERTY(double latitude READ latitude WRITE setLatitude NOTIFY valuesChanged)
    void setLatitude(const double &);
    double latitude() const;

    Q_PROPERTY(double longitude READ longitude WRITE setLongitude NOTIFY valuesChanged)
    void setLongitude(const double &);
    double longitude() const;

    Q_PROPERTY(double center_latitude READ center_latitude WRITE setCenterLatitude NOTIFY valuesChanged)
    void setCenterLatitude(const double &);
    double center_latitude() const;

    Q_PROPERTY(double center_longitude READ longitude WRITE setCenterLongitude NOTIFY valuesChanged)
    void setCenterLongitude(const double &);
    double center_longitude() const;

    Q_PROPERTY(int tps READ tps WRITE setTps NOTIFY valuesChanged)
    void setTps(const int &);
    int tps() const;

    Q_PROPERTY(int map READ map WRITE setMap NOTIFY valuesChanged)
    void setMap(const int &);
    int map() const;

    Q_PROPERTY(int lambda READ lambda WRITE setLambda NOTIFY valuesChanged)
    void setLambda(const int &);
    int lambda() const;

    Q_PROPERTY(int derivata_farfalla READ derivata_farfalla WRITE setDerivata_farfalla NOTIFY valuesChanged)
    void setDerivata_farfalla(const int &);
    int derivata_farfalla() const;

    Q_PROPERTY(int dmap READ dmap WRITE setDmap NOTIFY valuesChanged)
    void setDmap(const int &);
    int dmap() const;

    Q_PROPERTY(int drAxSpeed READ drAxSpeed WRITE setDrAxSpeed NOTIFY valuesChanged)
    void setDrAxSpeed(const int &);
    int drAxSpeed() const;

    Q_PROPERTY(int slip_Calc READ slip_Calc WRITE setSlip_Calc NOTIFY valuesChanged)
    void setSlip_Calc(const int &);
    int slip_Calc() const;

    Q_PROPERTY(int OSASlip READ OSASlip WRITE setOSASlip NOTIFY valuesChanged)
    void setOSASlip(const int &);
    int OSASlip() const;

    Q_PROPERTY(int terog_piano_quotato READ terog_piano_quotato WRITE setTerog_piano_quotato NOTIFY valuesChanged)
    void setTerog_piano_quotato(const int &);
    int terog_piano_quotato() const;

    Q_PROPERTY(int terog READ terog WRITE setTerog NOTIFY valuesChanged)
    void setTerog(const int &);
    int terog() const;

    Q_PROPERTY(int SABase READ SABase WRITE setSABase NOTIFY valuesChanged)
    void setSABase(const int &);
    int SABase() const;

    Q_PROPERTY(int SA READ SA WRITE setSA NOTIFY valuesChanged)
    void setSA(const int &);
    int SA() const;

    Q_PROPERTY(int gearShiftTimeRemaine READ gearShiftTimeRemaine WRITE setGearShiftTimeRemaine NOTIFY valuesChanged)
    void setGearShiftTimeRemaine(const int &);
    int gearShiftTimeRemaine() const;

    Q_PROPERTY(int baro READ baro WRITE setBaro NOTIFY valuesChanged)
    void setBaro(const int &);
    int baro() const;

    Q_PROPERTY(int vBattDir READ vBattDir WRITE setVBattDir NOTIFY valuesChanged)
    void setVBattDir(const int &);
    int vBattDir() const;

    Q_PROPERTY(int vBattKey READ vBattKey WRITE setVBattKey NOTIFY valuesChanged)
    void setVBattKey(const int &);
    int vBattKey() const;

    Q_PROPERTY(int LNR1I READ LNR1I WRITE setLNR1I NOTIFY valuesChanged)
    void setLNR1I(const int &);
    int LNR1I() const;

    Q_PROPERTY(int LNR2I READ LNR2I WRITE setLatitude NOTIFY valuesChanged)
    void setLNR2I(const int &);
    int LNR2I() const;

    Q_PROPERTY(int LNR7I READ LNR7I WRITE setLNR7I NOTIFY valuesChanged)
    void setLNR7I(const int &);
    int LNR7I() const;

    Q_PROPERTY(int LNR8I READ LNR8I WRITE setLNR8I NOTIFY valuesChanged)
    void setLNR8I(const int &);
    int LNR8I() const;

    Q_PROPERTY(int LNR5I READ LNR5I WRITE setLNR5I NOTIFY valuesChanged)
    void setLNR5I(const int &);
    int LNR5I() const;

    Q_PROPERTY(int LNR6I READ LNR6I WRITE setLNR6I NOTIFY valuesChanged)
    void setLNR6I(const int &);
    int LNR6I() const;

    Q_PROPERTY(int LNR3I READ LNR3I WRITE setLNR3I NOTIFY valuesChanged)
    void setLNR3I(const int &);
    int LNR3I() const;

    Q_PROPERTY(int LNR4I READ LNR4I WRITE setLNR4I NOTIFY valuesChanged)
    void setLNR4I(const int &);
    int LNR4I() const;

    Q_PROPERTY(int TMP READ TMP WRITE setTMP NOTIFY valuesChanged)
    void setTMP(const int &);
    int TMP() const;

    Q_PROPERTY(int tair READ tair WRITE setTair NOTIFY valuesChanged)
    void setTair(const int &);
    int tair() const;




signals:
    void kphChanged();
    void percentKphChanged();
    void rpmChanged();
    void percentRpmChanged();
    void gearChanged();
    void fuelChanged();
    void percentFuelChanged();
    void oil_tempChanged();
    void percent_oil_tempChanged();
    void oil_pressChanged();
    void percent_oil_pressChanged();
    void h2oChanged();
    void percentH2oChanged();
    void valuesChanged();

public slots:
    void update(QString topic, QJsonObject data);
    void updateSensorsGUI();
    void mosquitto_connected();
    void mosquitto_disconnected();

private:

    QString topics[57] = {"data/formatted/a1x",
                        "data/formatted/a1y",
                        "data/formatted/steer_pos",
                        "data/formatted/fldamp",
                        "data/formatted/frdamp",
                        "data/formatted/rldamp",
                        "data/formatted/rrdamp",
                        "data/formatted/current1",
                        "data/formatted/current2",
                        "data/formatted/slip_ok",
                        "data/formatted/auto_acc_flag",
                        "data/formatted/debug_mode",
                        "data/formatted/datalog_on-off",
                        "data/formatted/telemetria_on-off",
                        "data/formatted/lap_close",
                        "data/formatted/target_rpm_up",
                        "data/formatted/shift_duration",
                        "data/formatted/time_0-100",
                        "data/formatted/time_0-75",
                        "data/formatted/altitude",
                        "data/formatted/gps_speed",
                        "data/formatted/satellite",
                        "data/formatted/fix",
                        "data/formatted/gps_time",
                        "data/formatted/latitude",
                        "data/formatted/longitude",
                        "data/formatted/rpm",
                        "data/formatted/tps",
                        "data/formatted/map",
                        "data/formatted/lambda",
                        "data/formatted/derivata_farfalla",
                        "data/formatted/dmap",
                        "data/formatted/vhspeed",
                        "data/formatted/draxspeed",
                        "data/formatted/slip_calc",
                        "data/formatted/osaslip",
                        "data/formatted/terogpianoquotato",
                        "data/formatted/terog",
                        "data/formatted/sabase",
                        "data/formatted/sa",
                        "data/formatted/gear",
                        "data/formatted/gear_shift_time_remain",
                        "data/formatted/poil",
                        "data/formatted/pfuel",
                        "data/formatted/baro",
                        "data/formatted/vbattdir",
                        "data/formatted/vbattkey",
                        "data/formatted/tc1",
                        "data/formatted/tc2",
                        "data/formatted/tc_pot",
                        "data/formatted/gear_pot",
                        "data/formatted/pbrake_front",
                        "data/formatted/pbrake_rear",
                        "data/formatted/th2o",
                        "data/formatted/toil",
                        "data/formatted/tmp",
                        "data/formatted/tair"};

    bool debug_mode = false; // set here default debug mode

    int m_kph = 100;
    int m_rpm = 8000;
    int m_gear = 5;
    int m_fuel = 20;
    int m_oil_temp = 90;
    int m_oil_press = 50;
    int m_h2o = 80;

    int min_kph = 0;
    int min_rpm = 500;
    int min_fuel = 0;
    int min_oil_temp = 0;
    int min_oil_press = 0;
    int min_h2o = 0;

    int max_kph = 150;
    int max_rpm = 10000;
    int max_fuel = 100;
    int max_oil_temp = 100;
    int max_oil_press = 100;
    int max_h2o = 100;

    float p_kph = 0.5;
    float p_rpm = 0.3;
    float p_fuel = 0.4;
    float p_oil_temp = 0.7;
    float p_oil_press = 0.7;
    float p_h2o = 0.8;

    int m_a1x = 0;
    int m_a1y = 0;
    int m_steerPos = 0;
    int m_FLdamp = 0;
    int m_FRdamp = 0;
    int m_RLdamp = 0;
    int m_RRdamp = 0;
    int m_current1 = 0;
    int m_current2 = 0;
    int m_slip_ok = 0;
    int m_auto_acc_flag = 0;
    int m_debug_mode = 0;
    int m_datalog_on_off = 0;
    int m_telemetria_on_off = 0;
    int m_lapClose = 0;
    int m_target_rpm_up = 0;
    int m_shift_duration = 0;
    int m_time_0_100 = 0;
    int m_time_0_75 = 0;
    int m_altitude = 0;
    int m_GPS_speed = 0;
    int m_satellite = 0;
    int m_fix = 0;
    int m_gps_time = 0;
    double m_latitude = 41.1171432;
    double m_longitude = 16.871871499999997;
    double m_center_latitude = 41.1171432;
    double m_center_longitude = 16.871871499999997;
    int m_tps = 0;
    int m_map = 0;
    int m_lambda = 0;
    int m_derivata_farfalla = 0;
    int m_dmap = 0;
    int m_drAxSpeed = 0;
    int m_slip_Calc = 0;
    int m_OSASlip = 0;
    int m_terog_piano_quotato = 0;
    int m_terog = 0;
    int m_SABase = 0;
    int m_SA = 0;
    int m_gearShiftTimeRemaine = 0;
    int m_baro = 0;
    int m_vBattKey = 0;
    int m_vBattDir = 0;
    int m_LNR1I = 0;
    int m_LNR2I = 0;
    int m_LNR3I = 0;
    int m_LNR4I = 0;
    int m_LNR5I = 0;
    int m_LNR6I = 0;
    int m_LNR7I = 0;
    int m_LNR8I = 0;
    int m_TMP = 0;
    int m_tair = 0;


    QQmlApplicationEngine engine;
    MosquittoReceiver *receiver;
};

#endif // DASHBOARD_H
