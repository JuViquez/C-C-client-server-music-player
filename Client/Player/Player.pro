#-------------------------------------------------
#
# Project created by QtCreator 2015-01-14T19:18:43
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyPlayer
TEMPLATE = app


SOURCES += main.cpp \
    dialog.cpp \
    playlistcontroller.cpp \
    loginform.cpp

HEADERS  += dialog.h \
    playlistcontroller.h \
    loginform.h

FORMS    += dialog.ui \
    loginform.ui
