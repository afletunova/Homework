#pragma once

#include <QTCore/QObject>
#include <QtTest/QtTest>
#include <list>
#include <iostream>

#include "bubblesort.h"
#include "comparatorforint.h"

const int size = 10;

class BubbleSortTest : public QObject
{
    Q_OBJECT
private:
    Comparator<int> *comparator;
    BubbleSort<int> *sort;

private slots:
    void init()
    {
        comparator = new ComparatorForInt;
    }

    void testListWithEqualElements()
    {
        std::list<int> list(size);
        sort = new BubbleSort<int>(list, comparator);
        for (int i = 0; i < size; ++i)
        {
            list.push_back(0);
        }
        std::list<int> result = sort->Sort();
        QCOMPARE(list, result);
    }

    void cleanup()
    {
        delete comparator;
        delete sort;
    }
};
