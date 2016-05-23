QT += core
QT -= gui

TARGET = Task1
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    operand.cpp \
    operator.cpp \
    treenode.cpp \
    tree.cpp

HEADERS += \
    divisionbyzeroerror.h \
    operand.h \
    operator.h \
    treenode.h \
    tree.h

