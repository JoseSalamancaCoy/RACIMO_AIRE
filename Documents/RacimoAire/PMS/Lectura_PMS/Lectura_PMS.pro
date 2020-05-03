#-------------------------------------------------
#
# Project created by QtCreator 2018-07-19T15:39:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lectura_PMS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h


target.path =/home/pi/
INSTALLS += target

FORMS    += mainwindow.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Libreria/PMS/release/ -lPMS
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Libreria/PMS/debug/ -lPMS
else:unix: LIBS += -L$$PWD/../../Libreria/PMS/ -lPMS

INCLUDEPATH += $$PWD/../../Libreria/PMS
DEPENDPATH += $$PWD/../../Libreria/PMS

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Libreria/Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Libreria/Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../../Libreria/Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../../Libreria/Crpigpio
DEPENDPATH += $$PWD/../../Libreria/Crpigpio

QMAKE_CXXFLAGS += -std=gnu++14

