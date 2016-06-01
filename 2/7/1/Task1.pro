QT += core
QT -= gui
QT += testlib

TARGET = Task1
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    bag.h \
    tree.h \
    bagtest.h

