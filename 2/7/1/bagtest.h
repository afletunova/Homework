#pragma once

#include <QtTest/QtTest>
#include <QtCore/QObject>

#include "bag.h"

class BagTest : public QObject
{
    Q_OBJECT

private:
    Bag<int> *bag;

private slots:
    void init()
    {
        bag = new Bag<int>();
    }

    void cleanup()
    {
        delete bag;
    }

    void addElementTest()
    {
        bag->add(1);
        QVERIFY(bag->exist(1));
    }

    void addAndRemoveElementTest()
    {
        bag->add(1);
        bag->remove(1);
        QVERIFY(!bag->exist(1));
    }

    void removeNonExistenElementTest()
    {
        try
        {
            bag->remove(2);
            QVERIFY2(false, "Error was not thrown.");
        }
        catch (NonexistenElement &)
        {
            QVERIFY(true);
        }
    }

    void addMoreElementsTest()
    {
        int array[10];
        for (int i = 0; i < 10; ++i)
        {
            array[i] = rand();
        }

        for (int i = 0; i < 10; ++i)
        {
            bag->add(array[i]);
        }

        for (int i = 0; i < 10; ++i)
        {
            QVERIFY(bag->exist(array[i]));
        }
    }

    void addAndRemoveMoreElementsTest()
    {
        int array[10];
        for (int i = 0; i < 10; ++i)
        {
            array[i] = rand();
        }

        for (int i = 0; i < 10; ++i)
        {
            bag->add(array[i]);
        }

        for (int i = 0; i < 10; ++i)
        {
            bag->remove(array[i]);
        }

        for (int i = 0; i < 10; ++i)
        {
            QVERIFY(!bag->exist(array[i]));
        }
    }

    void copyConstructorTest()
    {
        int array[10];
        for (int i = 0; i < 10; ++i)
        {
            array[i] = rand();
        }

        for (int i = 0; i < 10; ++i)
        {
            bag->add(array[i]);
        }

        Bag<int> *secondBag(bag);

        QCOMPARE(bag, secondBag);
    }
};
