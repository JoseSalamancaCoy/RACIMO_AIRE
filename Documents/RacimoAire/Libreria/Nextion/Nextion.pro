#-------------------------------------------------
#
# Project created by QtCreator 2018-09-20T04:48:35
#
#-------------------------------------------------

QT       -= gui

TARGET = Nextion
TEMPLATE = lib

DEFINES += NEXTION_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += nextion.cpp \
    NexCheckbox.cpp \
    NexCrop.cpp \
    NexDualStateButton.cpp \
    NexGauge.cpp \
    NexGpio.cpp \
    NexHotspot.cpp \
    NexNumber.cpp \
    NexPage.cpp \
    NexPicture.cpp \
    NexRadio.cpp \
    NexRtc.cpp \
    NexScrolltext.cpp \
    NexSlider.cpp \
    NexTimer.cpp \
    NexWaveform.cpp \
    NexButton.cpp \
    nexconfig.cpp \
    NexHardware.cpp \
    NexObject.cpp \
    NexProgressBar.cpp \
    NexText.cpp \
    NexTouch.cpp \
    NexVariable.cpp


HEADERS += nextion.h\
        nextion_global.h \
    NexCheckbox.h \
    NexCrop.h \
    NexDualStateButton.h \
    NexGauge.h \
    NexGpio.h \
    NexHotspot.h \
    NexNumber.h \
    NexPage.h \
    NexPicture.h \
    NexRadio.h \
    NexRtc.h \
    NexScrolltext.h \
    NexSlider.h \
    NexTimer.h \
    NexWaveform.h \
    NexButton.h \
    NexConfig.h \
    NexHardware.h \
    NexObject.h \
    NexProgressBar.h \
    NexText.h \
    NexTouch.h \
    NexVariable.h


unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../Crpigpio
DEPENDPATH += $$PWD/../Crpigpio

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../NextionRaspberrypi/release/ -lNextionRaspberrypi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../NextionRaspberrypi/debug/ -lNextionRaspberrypi
else:unix: LIBS += -L$$PWD/../NextionRaspberrypi/ -lNextionRaspberrypi

INCLUDEPATH += $$PWD/../NextionRaspberrypi
DEPENDPATH += $$PWD/../NextionRaspberrypi

QMAKE_CXXFLAGS += -std=gnu++14


