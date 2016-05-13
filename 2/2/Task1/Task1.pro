QT += core
QT -= gui
QT += testlib

TARGET = Task1
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += \
    quicksorter.cpp \
    shellsorter.cpp \
    heapsorter.cpp

HEADERS += \
    sorter.h \
    quicksorter.h \
    shellsorter.h \
    heapsorter.h \
    sortertest.h
