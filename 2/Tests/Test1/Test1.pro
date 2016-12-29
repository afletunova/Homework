QT += core
QT -= gui
QT += testlib

TARGET = Test1
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += \
    main.cpp

HEADERS += \
    priorityqueue.h \
    queuetest.h

