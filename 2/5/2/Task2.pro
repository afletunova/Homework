QT += core
QT -= gui
QT += testlib

TARGET = Task2
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    set.h \
    tree.h \
    settest.h

