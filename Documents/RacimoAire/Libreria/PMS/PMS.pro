#-------------------------------------------------
#
# Project created by QtCreator 2018-07-21T22:09:25
#
#-------------------------------------------------

QT       -= gui

TARGET = PMS
TEMPLATE = lib

DEFINES += PMS_LIBRARY

SOURCES += pms.cpp

HEADERS += pms.h\
        pms_global.h

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

