QT += core
QT -= gui
QT += testlib


TARGET = Task2
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += \
    stackcalculator.cpp \
    arraystack.cpp

HEADERS += \
    stack.h \
    stackcalculator.h \
    pointerstack.h \
    arraystack.h \
    stackcalculatortest.h

