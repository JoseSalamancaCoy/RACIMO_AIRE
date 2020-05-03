QT += core gui
QT -= gui

CONFIG += c++11

TARGET = RacimoAire3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    racimo3.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
LIBS = -lcurl

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    racimo3.h
QMAKE_CXXFLAGS += -std=gnu++14


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../Libreria/Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../Libreria/Crpigpio
DEPENDPATH += $$PWD/../Libreria/Crpigpio

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/PMS/release/ -lPMS
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/PMS/debug/ -lPMS
else:unix: LIBS += -L$$PWD/../Libreria/PMS/ -lPMS

INCLUDEPATH += $$PWD/../Libreria/PMS
DEPENDPATH += $$PWD/../Libreria/PMS

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/OPCN2/release/ -lOPCN2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/OPCN2/debug/ -lOPCN2
else:unix: LIBS += -L$$PWD/../Libreria/OPCN2/ -lOPCN2

INCLUDEPATH += $$PWD/../Libreria/OPCN2
DEPENDPATH += $$PWD/../Libreria/OPCN2

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/DataParticulado/release/ -lDataParticulado
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/DataParticulado/debug/ -lDataParticulado
else:unix: LIBS += -L$$PWD/../Libreria/DataParticulado/ -lDataParticulado

INCLUDEPATH += $$PWD/../Libreria/DataParticulado
DEPENDPATH += $$PWD/../Libreria/DataParticulado

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/LogsSystem/release/ -lLogsSystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/LogsSystem/debug/ -lLogsSystem
else:unix: LIBS += -L$$PWD/../Libreria/LogsSystem/ -lLogsSystem

INCLUDEPATH += $$PWD/../Libreria/LogsSystem
DEPENDPATH += $$PWD/../Libreria/LogsSystem

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/Nextion/release/ -lNextion
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/Nextion/debug/ -lNextion
else:unix: LIBS += -L$$PWD/../Libreria/Nextion/ -lNextion

INCLUDEPATH += $$PWD/../Libreria/Nextion
DEPENDPATH += $$PWD/../Libreria/Nextion

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/NextionRaspberrypi/release/ -lNextionRaspberrypi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/NextionRaspberrypi/debug/ -lNextionRaspberrypi
else:unix: LIBS += -L$$PWD/../Libreria/NextionRaspberrypi/ -lNextionRaspberrypi

INCLUDEPATH += $$PWD/../Libreria/NextionRaspberrypi
DEPENDPATH += $$PWD/../Libreria/NextionRaspberrypi

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/DataJson2/release/ -lDataJson2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/DataJson2/debug/ -lDataJson2
else:unix: LIBS += -L$$PWD/../Libreria/DataJson2/ -lDataJson2

INCLUDEPATH += $$PWD/../Libreria/DataJson2
DEPENDPATH += $$PWD/../Libreria/DataJson2

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/CDateTimer/release/ -lCDateTimer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/CDateTimer/debug/ -lCDateTimer
else:unix: LIBS += -L$$PWD/../Libreria/CDateTimer/ -lCDateTimer

INCLUDEPATH += $$PWD/../Libreria/CDateTimer
DEPENDPATH += $$PWD/../Libreria/CDateTimer

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/Adafruit_BME280/release/ -lAdafruit_BME280
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/Adafruit_BME280/debug/ -lAdafruit_BME280
else:unix: LIBS += -L$$PWD/../Libreria/Adafruit_BME280/ -lAdafruit_BME280

INCLUDEPATH += $$PWD/../Libreria/Adafruit_BME280
DEPENDPATH += $$PWD/../Libreria/Adafruit_BME280

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/Adafruit_INA219/release/ -lAdafruit_INA219
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/Adafruit_INA219/debug/ -lAdafruit_INA219
else:unix: LIBS += -L$$PWD/../Libreria/Adafruit_INA219/ -lAdafruit_INA219

INCLUDEPATH += $$PWD/../Libreria/Adafruit_INA219
DEPENDPATH += $$PWD/../Libreria/Adafruit_INA219

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/ADS1115/release/ -lADS1115
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/ADS1115/debug/ -lADS1115
else:unix: LIBS += -L$$PWD/../Libreria/ADS1115/ -lADS1115

INCLUDEPATH += $$PWD/../Libreria/ADS1115
DEPENDPATH += $$PWD/../Libreria/ADS1115

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/GPS/release/ -lGPS
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/GPS/debug/ -lGPS
else:unix: LIBS += -L$$PWD/../Libreria/GPS/ -lGPS

INCLUDEPATH += $$PWD/../Libreria/GPS
DEPENDPATH += $$PWD/../Libreria/GPS
