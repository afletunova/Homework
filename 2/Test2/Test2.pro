QT += core
QT -= gui
QT += testlib

TARGET = Test2
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += \
    comparatorforint.cpp \
    main.cpp

HEADERS += \
    bubblesort.h \
    comparator.h \
    comparatorforint.h

