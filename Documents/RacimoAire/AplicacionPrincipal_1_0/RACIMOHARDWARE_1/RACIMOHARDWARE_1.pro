#-------------------------------------------------
#
# Project created by QtCreator 2018-08-10T08:31:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RACIMOHARDWARE_1
TEMPLATE = app


SOURCES += main.cpp\
        racimoaire.cpp \
    dataracimoaire.cpp

HEADERS  += racimoaire.h \
    dataracimoaire.h

FORMS    += racimoaire.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Libreria/Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Libreria/Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../../Libreria/Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../../Libreria/Crpigpio
DEPENDPATH += $$PWD/../../Libreria/Crpigpio

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Libreria/PMS/release/ -lPMS
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Libreria/PMS/debug/ -lPMS
else:unix: LIBS += -L$$PWD/../../Libreria/PMS/ -lPMS

INCLUDEPATH += $$PWD/../../Libreria/PMS
DEPENDPATH += $$PWD/../../Libreria/PMS

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Libreria/OPCN2/release/ -lOPCN2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Libreria/OPCN2/debug/ -lOPCN2
else:unix: LIBS += -L$$PWD/../../Libreria/OPCN2/ -lOPCN2

INCLUDEPATH += $$PWD/../../Libreria/OPCN2
DEPENDPATH += $$PWD/../../Libreria/OPCN2

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Libreria/GPS/release/ -lGPS
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Libreria/GPS/debug/ -lGPS
else:unix: LIBS += -L$$PWD/../../Libreria/GPS/ -lGPS

INCLUDEPATH += $$PWD/../../Libreria/GPS
DEPENDPATH += $$PWD/../../Libreria/GPS





QMAKE_CXXFLAGS += -std=gnu++14
