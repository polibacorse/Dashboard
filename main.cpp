#include <QGuiApplication>

#include <QQmlApplicationEngine>

#include "telemetry.h"
#include "dashboard.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    if(argv[1] == NULL){
        qInfo("\n Usage: Dashboard --arg  \n\n arg: \n\t --telemetry \n\t --dashboard \n\n Running default: dashboard...\n");
        //exit(0);
        Dashboard *dashboard = new Dashboard();
    }else if (strcmp(argv[1], "--telemetry") == 0){
        Telemetry *telemetry = new Telemetry();
    }else if(strcmp(argv[1], "--dashboard") == 0){
        Dashboard *dashboard = new Dashboard();
    }else if(strcmp(argv[1], "--help") == 0){
        qInfo("\n Usage: Dashboard --arg  \n\n arg: \n\t --telemetry \n\t --dashboard");
        exit(0);
    }



    return app.exec();
}
