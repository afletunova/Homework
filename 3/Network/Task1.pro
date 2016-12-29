QT += core
QT -= gui
QT += testlib

TARGET = Task1
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    Computer/computer.cpp \
    Network/network.cpp \
    Random/random.cpp \
    Random/fakerandom.cpp

HEADERS += \
    Computer/computer.h \
    Network/network.h \
    networktest.h \
    Random/random.h \
    Random/fakerandom.h

DISTFILES +=
