#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <string>

#include "stackcalculator.h"

using namespace std;

class StackCalculatorTest : public QObject
{
    Q_OBJECT

private slots:
    void testInputOneNumber()
    {
        string entered = "5";
        QCOMPARE(calculator(entered), 5);
    }

    void testInputExpressionOfTwoTerms()
    {
        string entered = "6 + 4";
        QCOMPARE(calculator(entered), 10);
    }

    void testInputExpressionOfTwoFactorsComplexAndSimpleWithBrackets()
    {
        string entered = "(1 + 2) * 3";
        QCOMPARE(calculator(entered), 9);
    }

    void testInputExpressionWithSignificantOrderOfNumber()
    {
        string entered = "(1 - 4) / 3";
        QCOMPARE(calculator(entered), -1);
    }
    void testInputExpressionWithSagnificantOrderOfNumberMultiplicative()
    {
        string entered = "6 * 8 / 4 * 3 / 2";
        QCOMPARE(calculator(entered), 18);
    }

    void testInputExpressionWithSagnificantOrderOfNumberAdditive()
    {
        string entered = "((6 + 8) - (4 + (3 - 2))";
        QCOMPARE(calculator(entered), 9);
    }
};

QTEST_MAIN(StackCalculatorTest)
