#-------------------------------------------------
#
# Project created by QtCreator 2018-08-15T17:45:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Json_1_0
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

LIBS = -lcurl

SOURCES += \
        main.cpp \
        mainwindow.cpp \

HEADERS += \
        mainwindow.h \

FORMS += \
        mainwindow.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/RacimoHttp/release/ -lRacimoHttp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/RacimoHttp/debug/ -lRacimoHttp
else:unix: LIBS += -L$$PWD/../Libreria/RacimoHttp/ -lRacimoHttp

INCLUDEPATH += $$PWD/../Libreria/RacimoHttp
DEPENDPATH += $$PWD/../Libreria/RacimoHttp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libreria/DataJson/release/ -lDataJson
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libreria/DataJson/debug/ -lDataJson
else:unix: LIBS += -L$$PWD/../Libreria/DataJson/ -lDataJson

INCLUDEPATH += $$PWD/../Libreria/DataJson
DEPENDPATH += $$PWD/../Libreria/DataJson

QMAKE_CXXFLAGS += -std=gnu++14

