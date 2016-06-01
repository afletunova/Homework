#-------------------------------------------------
#
# Project created by QtCreator 2016-04-17 T23:20:14
#
#-------------------------------------------------

QT += core gui
QT += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Task3
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp

HEADERS  += mainwindow.h \
    calculatortest.h \
    calculator.h

FORMS    += mainwindow.ui
