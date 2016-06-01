#pragma once

#include <QtTest/QTest>
#include <QtCore/QObject>

#include "vector.h"

class VectorTest : public QObject
{
    Q_OBJECT

private slots:

    void checkEquivalenceOfElementsTest()
    {
        int *array = new int[5];
        for (int i = 0; i < 5; ++i)
        {
            array[i] = i;
        }
        Vector<5> vector(array);
        Vector<5> newVector(vector);
        QVERIFY(vector == newVector);
    }
};
