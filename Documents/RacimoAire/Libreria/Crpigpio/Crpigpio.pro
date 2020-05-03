#-------------------------------------------------
#
# Project created by QtCreator 2018-07-21T22:29:11
#
#-------------------------------------------------

QT       -= gui

TARGET = Crpigpio
TEMPLATE = lib

DEFINES += CRPIGPIO_LIBRARY

SOURCES += crpigpio.cpp

HEADERS += crpigpio.h\
        crpigpio_global.h

INCLUDEPATH+=../llibCpigpio/rpigpio

LIBS+=-lpigpio -lpthread


unix {
    target.path = /usr/lib
    INSTALLS += target
}
QMAKE_CXXFLAGS += -std=gnu++14

