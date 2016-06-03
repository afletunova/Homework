#-------------------------------------------------
#
# Project created by QtCreator 2016-06-02T01:54:34
#
#-------------------------------------------------

QT += core gui network webkitwidgets
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Task2
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    bash.cpp

HEADERS  += mainwindow.h \
    bash.h \
    quote.h

FORMS    += mainwindow.ui
