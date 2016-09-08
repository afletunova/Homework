#-------------------------------------------------
#
# Project created by QtCreator 2016-08-10T08:22:12
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        clientwindow.cpp \
    client.cpp \
    ../chat.cpp

HEADERS  += clientwindow.h \
    client.h \
    ../chat.h \
    ../plaintexteditwithlimits.h

FORMS    += clientwindow.ui
