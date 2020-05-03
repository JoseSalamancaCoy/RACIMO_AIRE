#-------------------------------------------------
#
# Project created by QtCreator 2018-09-13T15:32:56
#
#-------------------------------------------------

QT       -= gui

TARGET = DataParticulado
TEMPLATE = lib

DEFINES += DATAPARTICULADO_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += dataparticulado.cpp

HEADERS += dataparticulado.h\
        dataparticulado_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../OPCN2/release/ -lOPCN2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../OPCN2/debug/ -lOPCN2
else:unix: LIBS += -L$$PWD/../OPCN2/ -lOPCN2

INCLUDEPATH += $$PWD/../OPCN2
DEPENDPATH += $$PWD/../OPCN2

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../PMS/release/ -lPMS
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../PMS/debug/ -lPMS
else:unix: LIBS += -L$$PWD/../PMS/ -lPMS

INCLUDEPATH += $$PWD/../PMS
DEPENDPATH += $$PWD/../PMS



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../Crpigpio
DEPENDPATH += $$PWD/../Crpigpio

QMAKE_CXXFLAGS += -std=gnu++14
