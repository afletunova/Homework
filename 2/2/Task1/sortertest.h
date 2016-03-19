#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>

#include "sorter.h"
#include "heapsorter.h"
#include "quicksorter.h"
#include "shellsorter.h"

class SorterTest : public QObject
{
    Q_OBJECT
private:
    const int length = 100;
    Sorter *sort = nullptr;
    int *arrayOfNumbers = new int[length];

private slots:
    void testEmptyArrayHeapSort()
    {
        arrayOfNumbers = new int[0];
        sort = new HeapSorter();
        sort->sort(arrayOfNumbers, 0);
        QCOMPARE(arrayOfNumbers, arrayOfNumbers);
    }
    void testEmptyArrayQuickSort()
    {
        arrayOfNumbers = new int[0];
        sort = new QuickSorter();
        sort->sort(arrayOfNumbers, 0);
        QCOMPARE(arrayOfNumbers, arrayOfNumbers);
    }
    void testEmptyArrayShellSort()
    {
        arrayOfNumbers = new int[0];
        sort = new ShellSorter();
        sort->sort(arrayOfNumbers, 0);
        QCOMPARE(arrayOfNumbers, arrayOfNumbers);
    }
    void testArrayOfOneElementHeapSort()
    {
        arrayOfNumbers = new int[1];
        sort = new HeapSorter();
        sort->sort(arrayOfNumbers, 1);
        QCOMPARE(arrayOfNumbers, arrayOfNumbers);
    }
    void testArrayOfOneElementQuickSort()
    {
        arrayOfNumbers = new int[1];
        sort = new QuickSorter();
        sort->sort(arrayOfNumbers, 1);
        QCOMPARE(arrayOfNumbers, arrayOfNumbers);
    }
    void testArrayOfOneElementShellSort()
    {
        arrayOfNumbers = new int[1];
        sort = new ShellSorter();
        sort->sort(arrayOfNumbers, 1);
        QCOMPARE(arrayOfNumbers, arrayOfNumbers);
    }
    void testArrayOfTwoElementsHeapSort()
    {
        arrayOfNumbers = new int[2];
        arrayOfNumbers[0] = 2; arrayOfNumbers[1] = 1;
        sort = new HeapSorter();
        int *result = new int[2];
        result[0] = 1; result[1] = 2;
        sort->sort(arrayOfNumbers, 2);
        bool check = ((arrayOfNumbers[0] == result[0]) && (arrayOfNumbers[1] == result[1]));
        QVERIFY(check);
        delete[] result;
    }
    void testArrayOfTwoElementsQuickSort()
    {
        arrayOfNumbers = new int[2];
        arrayOfNumbers[0] = 2; arrayOfNumbers[1] = 1;
        sort = new QuickSorter();
        int *result = new int[2];
        result[0] = 1; result[1] = 2;
        sort->sort(arrayOfNumbers, 2);
        bool check = ((arrayOfNumbers[0] == result[0]) && (arrayOfNumbers[1] == result[1]));
        QVERIFY(check);
        delete[] result;
    }
    void testArrayOfTwoElementsShellSort()
    {
        arrayOfNumbers = new int[2];
        arrayOfNumbers[0] = 2; arrayOfNumbers[1] = 1;
        sort = new ShellSorter();
        int *result = new int[2];
        result[0] = 1; result[1] = 2;
        sort->sort(arrayOfNumbers, 2);
        bool check = ((arrayOfNumbers[0] == result[0]) && (arrayOfNumbers[1] == result[1]));
        QVERIFY(check);
        delete[] result;
    }
    void testArrayOfManyElementsHeapSort()
    {
        arrayOfNumbers = new int[100];
        for (int i = 0; i < 100; ++i)
        {
            arrayOfNumbers[i] = 100 - (i + 1);
        }
        sort = new HeapSorter();
        sort->sort(arrayOfNumbers, 100);
        int *result = new int[100];
        bool check = true;
        for (int i = 1; i < 100; ++i)
        {
            result[i] = i;
            if (result[i] != arrayOfNumbers[i])
            {
                check = false;
            }
        }
        QVERIFY(check);
    }
    void testArrayOfManyElementsQuickSort()
    {
        arrayOfNumbers = new int[100];
        for (int i = 0; i < 100; ++i)
        {
            arrayOfNumbers[i] = 100 - (i + 1);
        }
        sort = new QuickSorter();
        sort->sort(arrayOfNumbers, 100);
        int *result = new int[100];
        bool check = true;
        for (int i = 1; i < 100; ++i)
        {
            result[i] = i;
            if (result[i] != arrayOfNumbers[i])
            {
                check = false;
            }
        }
        QVERIFY(check);
    }
    void testArrayOfManyElementsShellSort()
    {
        arrayOfNumbers = new int[100];
        for (int i = 0; i < 100; ++i)
        {
            arrayOfNumbers[i] = 100 - (i + 1);
        }
        sort = new ShellSorter();
        sort->sort(arrayOfNumbers, 100);
        int *result = new int[100];
        bool check = true;
        for (int i = 1; i < 100; ++i)
        {
            result[i] = i;
            if (result[i] != arrayOfNumbers[i])
            {
                check = false;
            }
        }
        QVERIFY(check);
    }
};

QTEST_MAIN(SorterTest)
