#-------------------------------------------------
#
# Project created by QtCreator 2018-09-20T06:16:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestNextion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui






win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Libreria/Nextion/release/ -lNextion
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Libreria/Nextion/debug/ -lNextion
else:unix: LIBS += -L$$PWD/../../Libreria/Nextion/ -lNextion

INCLUDEPATH += $$PWD/../../Libreria/Nextion
DEPENDPATH += $$PWD/../../Libreria/Nextion



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Libreria/NextionRaspberrypi/release/ -lNextionRaspberrypi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Libreria/NextionRaspberrypi/debug/ -lNextionRaspberrypi
else:unix: LIBS += -L$$PWD/../../Libreria/NextionRaspberrypi/ -lNextionRaspberrypi

INCLUDEPATH += $$PWD/../../Libreria/NextionRaspberrypi
DEPENDPATH += $$PWD/../../Libreria/NextionRaspberrypi

QMAKE_CXXFLAGS += -std=gnu++14


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Libreria/Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Libreria/Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../../Libreria/Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../../Libreria/Crpigpio
DEPENDPATH += $$PWD/../../Libreria/Crpigpio