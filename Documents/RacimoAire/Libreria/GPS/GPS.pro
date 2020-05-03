#-------------------------------------------------
#
# Project created by QtCreator 2018-08-10T08:24:21
#
#-------------------------------------------------

QT       -= gui

TARGET = GPS
TEMPLATE = lib

DEFINES += GPS_LIBRARY

SOURCES += gps.cpp

HEADERS += gps.h\
        gps_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../Crpigpio
DEPENDPATH += $$PWD/../Crpigpio
QMAKE_CXXFLAGS += -std=gnu++14
