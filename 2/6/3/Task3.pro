QT += core
QT -= gui
QT += testlib

TARGET = Task3
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    sharedpointer.h \
    sharedpointertest.h

