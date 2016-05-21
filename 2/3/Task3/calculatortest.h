#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <cstring>

#include "calculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT
private:
    Calculator *calculator;
    QString result;
    char *expression;

private slots:
    void init()
    {
        calculator = new Calculator();
    }

    void cleanup()
    {
        delete calculator;
        delete expression;
    }

    void testAddition()
    {
        expression = "5+16";
        result = "21";
        calculator->read(expression, strlen(expression));
        QCOMPARE(calculator->calculate(), result);
    }

    void testSubtraction()
    {
        expression = "5-5";
        result = "0";
        calculator->read(expression, strlen(expression));
        QCOMPARE(calculator->calculate(), result);
    }

    void testMultiplication()
    {
        expression = "5*5";
        result = "25";
        calculator->read(expression, strlen(expression));
        QCOMPARE(calculator->calculate(), result);
    }

    void testDivision()
    {
        expression = "5/5";
        result = "1";
        calculator->read(expression, strlen(expression));
        QCOMPARE(calculator->calculate(), result);
    }

    void testThreeSummands()
    {
        expression = "5+6-8";
        result = "3";
        calculator->read(expression, strlen(expression));
        QCOMPARE(calculator->calculate(), result);
    }
};
