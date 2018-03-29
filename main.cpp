#include <QGuiApplication>

#include "dashboard.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    Dashboard *dashboard = new Dashboard();

    return app.exec();
}
