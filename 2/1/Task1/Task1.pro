QT += core
QT -= gui

CONFIG += c++11

TARGET = Task1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    arraylist.cpp \
    choice.cpp \
    listpointer.cpp

HEADERS += \
    arraylist.h \
    choice.h \
    list.h \
    listpointer.h

