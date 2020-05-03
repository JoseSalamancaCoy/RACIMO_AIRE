#-------------------------------------------------
#
# Project created by QtCreator 2018-09-30T22:47:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestSensoresParticulados
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h \

FORMS    += dialog.ui

LIBS = -lcurl

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/Crpigpio/release/ -lCrpigpio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/Crpigpio/debug/ -lCrpigpio
else:unix: LIBS += -L$$PWD/../Libreria/Crpigpio/ -lCrpigpio

INCLUDEPATH += $$PWD/../Libreria/Crpigpio
DEPENDPATH += $$PWD/../Libreria/Crpigpio

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/DataParticulado/release/ -lDataParticulado
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/DataParticulado/debug/ -lDataParticulado
else:unix: LIBS += -L$$PWD/../Libreria/DataParticulado/ -lDataParticulado

INCLUDEPATH += $$PWD/../Libreria/DataParticulado
DEPENDPATH += $$PWD/../Libreria/DataParticulado

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/OPCN2/release/ -lOPCN2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/OPCN2/debug/ -lOPCN2
else:unix: LIBS += -L$$PWD/../Libreria/OPCN2/ -lOPCN2

INCLUDEPATH += $$PWD/../Libreria/OPCN2
DEPENDPATH += $$PWD/../Libreria/OPCN2

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/PMS/release/ -lPMS
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/PMS/debug/ -lPMS
else:unix: LIBS += -L$$PWD/../Libreria/PMS/ -lPMS

INCLUDEPATH += $$PWD/../Libreria/PMS
DEPENDPATH += $$PWD/../Libreria/PMS

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/LogsSystem/release/ -lLogsSystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/LogsSystem/debug/ -lLogsSystem
else:unix: LIBS += -L$$PWD/../Libreria/LogsSystem/ -lLogsSystem

INCLUDEPATH += $$PWD/../Libreria/LogsSystem
DEPENDPATH += $$PWD/../Libreria/LogsSystem

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/DataJson/release/ -lDataJson
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/DataJson/debug/ -lDataJson
else:unix: LIBS += -L$$PWD/../Libreria/DataJson/ -lDataJson

INCLUDEPATH += $$PWD/../Libreria/DataJson
DEPENDPATH += $$PWD/../Libreria/DataJson

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/CDateTimer/release/ -lCDateTimer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/CDateTimer/debug/ -lCDateTimer
else:unix: LIBS += -L$$PWD/../Libreria/CDateTimer/ -lCDateTimer

INCLUDEPATH += $$PWD/../Libreria/CDateTimer
DEPENDPATH += $$PWD/../Libreria/CDateTimer

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/DataJson2/release/ -lDataJson2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/DataJson2/debug/ -lDataJson2
else:unix: LIBS += -L$$PWD/../Libreria/DataJson2/ -lDataJson2

INCLUDEPATH += $$PWD/../Libreria/DataJson2
DEPENDPATH += $$PWD/../Libreria/DataJson2

QMAKE_CXXFLAGS += -std=gnu++14
