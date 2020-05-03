#-------------------------------------------------
#
# Project created by QtCreator 2018-07-17T23:47:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LecturaGPS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Adafruit_GPS.cpp \
    crpigpio.cpp


INCLUDEPATH+=../llibCpigpio/rpigpio

LIBS+=-lpigpio -lpthread

HEADERS  += mainwindow.h \
    Adafruit_GPS.h \
    rpigpio_global.h \
    crpigpio.h


target.path =/home/pi/
INSTALLS += target

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=gnu++14
