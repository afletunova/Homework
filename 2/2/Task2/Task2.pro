QT += core
QT -= gui

TARGET = Task2
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    showette.cpp \
    twodimensionalarray.cpp \
    showettefileoutput.cpp \
    showetteconsoleoutput.cpp

HEADERS += \
    showette.h \
    twodimensionalarray.h \
    showettefileoutput.h \
    showetteconsoleoutput.h

