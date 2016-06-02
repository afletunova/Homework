QT += core
QT -= gui
QT += testlib

TARGET = Task3
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    listscomparator.cpp

HEADERS += \
    listpointer.h \
    sortedsettest.h \
    listscomparator.h \
    sortedset.h \
    elementoflist.h

