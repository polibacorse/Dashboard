QT += quick
CONFIG += c++17

QMAKE_CXXFLAGS += -std=c++17

# emit Deprected warnings
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    mosquittoreceiver.cpp \
    mosquittoreceiversingleton.cpp \
    dashboard.cpp

#RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    mosquittoreceiver.h \
    mosquittoreceiversingleton.h \
    dashboard.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib64/release/ -lmosquitto
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib64/debug/ -lmosquitto
else:unix: LIBS += -L$$PWD/../../../../usr/lib64/ -lmosquitto

DISTFILES += \
    dashboard.qml \
    DashboardGaugeStyle.qml \
    main.qml \
    text_dashboard.qml
