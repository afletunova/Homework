#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <cstring>

#include "calculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT
private:
    float result;
    QString expression;

private slots:

    void testAddition()
    {
        expression = "5+16";
        result = 21;
        Calculator calculator(expression);
        QCOMPARE(calculator.calculate(), result);
    }

    void testSubtraction()
    {
        expression = "5-5";
        result = 0;
        Calculator calculator(expression);
        QCOMPARE(calculator.calculate(), result);
    }

    void testMultiplication()
    {
        expression = "5*5";
        result = 25;
        Calculator calculator(expression);
        QCOMPARE(calculator.calculate(), result);
    }

    void testDivision()
    {
        expression = "5/5";
        result = 1;
        Calculator calculator(expression);
        QCOMPARE(calculator.calculate(), result);
    }

    void testThreeSummands()
    {
        expression = "5+6-8";
        result = 3;
        Calculator calculator(expression);
        QCOMPARE(calculator.calculate(), result);
    }

    void testAnotherThreeSummands()
    {
        expression = "1+3*6";
        result = 19;
        Calculator calculator(expression);
        QCOMPARE(calculator.calculate(), result);
    }
};
