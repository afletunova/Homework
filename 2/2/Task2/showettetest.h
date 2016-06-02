#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>

#include "showetteconsoleoutput.h"

using namespace std;

class ShowetteTest : public QObject
{
    Q_OBJECT

private:
    int **array;
    ShowetteConsoleOutput showette;
    bool compare(int firstArray[], int *secondArray)
    {
        bool equal = true;
        for (int i = 0; i < 25; ++i)
        {
            if (firstArray[i] != secondArray[i])
            {
                equal = false;
                break;
            }
        }
        return equal;
    }

private slots:
    void init()
    {
        int k = 0;
        array = new int*[5];
        for (int i = 0; i < 5; ++i)
        {
            array[i] = new int[5];
        }
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                array[i][j] = ++k;
            }
        }
    }

    void cleanup()
    {
        for (int i = 0; i < 5; ++i)
        {
            delete[] array[i];
        }
        delete[] array;
    }

    void orderOfNumbersTest()
    {
        int result[25] = {13, 14, 19, 18, 17,
                          12, 7, 8, 9, 10,
                          15, 20, 25, 24, 23,
                          22, 21, 16, 11, 6,
                          1, 2, 3, 4, 5};

        QVERIFY(compare(result, showette.spiral(array, 5)));
    }

    void anotherOrderOfNumberTest()
    {
        for (int i = 0; i < 5; ++i)
        {
            array[i][2] = i;
        }

        int result[25] = {2, 14, 19, 3, 17,
                          12, 7, 1, 9, 10,
                          15, 20, 25, 24, 4,
                          22, 21, 16, 11, 6,
                          1, 2, 0, 4, 5};
        QVERIFY(compare(result, showette.spiral(array, 5)));
    }
};
