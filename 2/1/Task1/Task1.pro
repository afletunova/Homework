QT += core
QT += testlib
QT -= gui

CONFIG += c++11

TARGET = Task1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    arraylist.cpp \
    listpointer.cpp

HEADERS += \
    list.h \
    listpointer.h \
    arraylist.h \
    listtest.h
