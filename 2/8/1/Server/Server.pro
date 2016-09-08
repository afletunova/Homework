#-------------------------------------------------
#
# Project created by QtCreator 2016-08-01T20:00:48
#
#-------------------------------------------------

QT       += core gui network
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
    server.cpp \
    ../chat.cpp \
    serverwindow.cpp

HEADERS  += \
    server.h \
    ../chat.h \
    serverwindow.h \
    ../plaintexteditwithlimits.h

FORMS    += serverwindow.ui
