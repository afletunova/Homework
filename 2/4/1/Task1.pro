QT += core
QT -= gui
QT += testlib

TARGET = Task1
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += \
    choice.cpp \
    hashtable.cpp \
    listpointer.cpp \
    hashrs.cpp \
    hashfaq6.cpp \
    hashrot13.cpp \
    main.cpp

HEADERS += \
    choice.h \
    hashtable.h \
    listpointer.h \
    hashfunction.h \
    hashrs.h \
    hashfaq6.h \
    hashrot13.h \
    hashtabletest.h

