#-------------------------------------------------
#
# Project created by QtCreator 2018-09-19T18:12:36
#
#-------------------------------------------------

QT       -= gui

TARGET = NextionRaspberrypi
TEMPLATE = lib

DEFINES += NEXTIONRASPBERRYPI_LIBRARY

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
        nextionraspberrypi.cpp \

    nexconfig.cpp

HEADERS += \
        nextionraspberrypi.h \
        nextionraspberrypi_global.h \

    NexWaveform.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SUBDIRS += \
    NextionRaspberrypi.pro

DISTFILES += \
    NextionRaspberrypi.pro.user

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Libreria/Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Libreria/Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../../Libreria/Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../../Libreria/Crpigpio
DEPENDPATH += $$PWD/../../Libreria/Crpigpio


QMAKE_CXXFLAGS += -std=gnu++11
