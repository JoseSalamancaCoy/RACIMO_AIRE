#-------------------------------------------------
#
# Project created by QtCreator 2018-09-20T05:07:06
#
#-------------------------------------------------

QT       -= gui

TARGET = NexVariable
TEMPLATE = lib

DEFINES += NEXVARIABLE_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += nexvariable.cpp

HEADERS += nexvariable.h\
        nexvariable_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../Crpigpio
DEPENDPATH += $$PWD/../Crpigpio

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../NexConfig/release/ -lNexConfig
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../NexConfig/debug/ -lNexConfig
else:unix: LIBS += -L$$PWD/../NexConfig/ -lNexConfig

INCLUDEPATH += $$PWD/../NexConfig
DEPENDPATH += $$PWD/../NexConfig



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../NexTouch/release/ -lNexTouch
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../NexTouch/debug/ -lNexTouch
else:unix: LIBS += -L$$PWD/../NexTouch/ -lNexTouch

INCLUDEPATH += $$PWD/../NexTouch
DEPENDPATH += $$PWD/../NexTouch



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../NextionRaspberrypi/release/ -lNextionRaspberrypi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../NextionRaspberrypi/debug/ -lNextionRaspberrypi
else:unix: LIBS += -L$$PWD/../../NextionRaspberrypi/ -lNextionRaspberrypi

INCLUDEPATH += $$PWD/../../NextionRaspberrypi
DEPENDPATH += $$PWD/../../NextionRaspberrypi



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../../Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../../Crpigpio
DEPENDPATH += $$PWD/../../Crpigpio


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../NexObject/release/ -lNexObject
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../NexObject/debug/ -lNexObject
else:unix: LIBS += -L$$PWD/../NexObject/ -lNexObject

INCLUDEPATH += $$PWD/../NexObject
DEPENDPATH += $$PWD/../NexObject



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../NexHardware/release/ -lNexHardware
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../NexHardware/debug/ -lNexHardware
else:unix: LIBS += -L$$PWD/../NexHardware/ -lNexHardware

INCLUDEPATH += $$PWD/../NexHardware
DEPENDPATH += $$PWD/../NexHardware

QMAKE_CXXFLAGS += -std=gnu++14
