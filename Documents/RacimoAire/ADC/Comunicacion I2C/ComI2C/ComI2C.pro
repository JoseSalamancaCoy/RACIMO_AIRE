#-------------------------------------------------
#
# Project created by QtCreator 2018-08-21T18:16:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ComI2C
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
        mainwindow.cpp# \
    #ADS1115.cpp

HEADERS  += mainwindow.h #\
    #ADS1115.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Libreria/Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Libreria/Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../../../Libreria/Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../../../Libreria/Crpigpio
DEPENDPATH += $$PWD/../../../Libreria/Crpigpio

QMAKE_CXXFLAGS += -std=gnu++14


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Libreria/ADS1115/release/ -lADS1115
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Libreria/ADS1115/debug/ -lADS1115
else:unix: LIBS += -L$$PWD/../../../Libreria/ADS1115/ -lADS1115

INCLUDEPATH += $$PWD/../../../Libreria/ADS1115
DEPENDPATH += $$PWD/../../../Libreria/ADS1115
