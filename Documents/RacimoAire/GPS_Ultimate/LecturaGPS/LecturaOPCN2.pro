#-------------------------------------------------
#
# Project created by QtCreator 2018-07-09T10:16:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LecturaOPCN2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        lecturaopcn2.cpp \
        crpigpio.cpp \
        opcn2.cpp \
        opcn2_data.cpp

INCLUDEPATH+=../llibCpigpio/rpigpio

LIBS+=-lpigpio -lpthread
HEADERS += \
        lecturaopcn2.h \
        crpigpio.h \
        opcn2.h \
        opcn2_data.h \
        opcn2_ids.h \
        opcn2_param.h \
        rpigpio_global.h

target.path =/home/pi/
INSTALLS += target

FORMS += lecturaopcn2.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

QMAKE_CXXFLAGS += -std=gnu++14
