#include <QGuiApplication>

#include "dashboard.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Dashboard *dashboard = new Dashboard();

    return app.exec();
}
