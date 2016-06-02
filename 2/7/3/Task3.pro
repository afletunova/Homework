#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T16:05:09
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
    tictactoe.cpp

HEADERS  += mainwindow.h \
    tictactoe.h

FORMS    += mainwindow.ui
