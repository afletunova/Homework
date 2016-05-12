QT += core
QT -= gui

TARGET = Task1
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    choice.cpp \
    hashtable.cpp \
    listpointer.cpp \
    hashrs.cpp \
    hashfaq6.cpp \
    hashrot13.cpp

HEADERS += \
    choice.h \
    hashtable.h \
    listpointer.h \
    hashfunction.h \
    hashrs.h \
    hashfaq6.h \
    hashrot13.h

