#-------------------------------------------------
#
# Project created by QtCreator 2018-08-22T14:04:38
#
#-------------------------------------------------

QT       -= gui

TARGET = Adafruit_INA219
TEMPLATE = lib

DEFINES += ADAFRUIT_INA219_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += adafruit_ina219.cpp

HEADERS += adafruit_ina219.h\
        adafruit_ina219_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../Crpigpio
DEPENDPATH += $$PWD/../Crpigpio
