#-------------------------------------------------
#
# Project created by QtCreator 2018-07-22T00:34:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Prueba3PMS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


QMAKE_CXXFLAGS += -std=gnu++14


unix|win32: LIBS += -lPMS

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
