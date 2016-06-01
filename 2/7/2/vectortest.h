#pragma once

#include <QtTest/QTest>
#include <QtCore/QObject>

#include "vector.h"

class VectorTest : public QObject
{
    Q_OBJECT

private:
    int *array;

private slots:
    void init()
    {
        array = new int[5];
        for (int i = 0; i < 5; ++i)
        {
            array[i] = i;
        }
    }

    void cleanup()
    {
        delete[] array;
    }

    void copyConstructorTest()
    {
        Vector<5> vector(array);
        Vector<5> newVector(vector);
        QCOMPARE(vector, newVector);
    }

    void additionOperatorTest()
    {
        Vector<5> vector(array);
        for (int i = 0; i < 5; ++i)
        {
            array[i] = i * 2;
        }
        Vector<5> result(array);
        QCOMPARE(result, vector + vector);
    }

    void multiplicativeOperatorTest()
    {
        Vector<5> vector(array);
        QCOMPARE(30, vector * vector);
    }

    void equalOperatorTest()
    {
        Vector<5> vector(array);
        Vector<5> newVector(vector);
        QCOMPARE(true, vector == newVector);
    }

    void nullVectorTest()
    {
        for (int i = 0; i < 5; ++i)
        {
            array[i] = 0;
        }
        Vector<5> vector(array);
        QVERIFY(vector.isNull());
    }
};
