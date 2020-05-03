#-------------------------------------------------
#
# Project created by QtCreator 2018-08-10T00:50:11
#
#-------------------------------------------------

QT       -= gui

TARGET = OPCN2
TEMPLATE = lib

DEFINES += OPCN2_LIBRARY

SOURCES += opcn2.cpp \
    opcn2_data.cpp

HEADERS += opcn2.h\
        opcn2_global.h \
    opcn2_data.h \
    opcn2_ids.h

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
