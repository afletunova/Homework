#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <cstdlib>

#include "set.h"

class SetTest : public QObject
{
    Q_OBJECT

private:
    Set<int> *set;

private slots:
    void init()
    {
        set = new Set<int>();
    }

    void cleanup()
    {
        delete set;
    }

    void AddElementTest()
    {
        set->add(1);
        QVERIFY(set->exist(1));
    }

    void AddAndRemoveElementTest()
    {
        set->add(1);
        set->remove(1);
        QVERIFY(!set->exist(1));
    }

    void RemoveNonExistenElementTest()
    {
        try
        {
            set->remove(1);
            QVERIFY2(false, "Error was not thrown.");
        }
        catch (NonexistenElement &)
        {
            QVERIFY(true);
        }
    }

    void AddOneElementTwiceTest()
    {
        try
        {
            set->add(1);
            set->add(1);
            QVERIFY2(false, "Error was not thrown.");
        }
        catch (AlreadyExistingElement &)
        {
            QVERIFY(true);
        }
    }

    void AddMoreElementsTest()
    {
        int array[10];
        for (int i = 0; i < 10; ++i)
        {
            array[i] = rand();
        }

        for (int i = 0; i < 10; ++i)
        {
            set->add(array[i]);
        }

        for (int i = 0; i < 10; ++i)
        {
            QVERIFY(set->exist(array[i]));
        }
    }

    void AddAndRemoveMoreElementsTest()
    {
        int array[10];
        for (int i = 0; i < 10; ++i)
        {
            array[i] = rand();
        }

        for (int i = 0; i < 10; ++i)
        {
            set->add(array[i]);
        }

        for (int i = 0; i < 10; ++i)
        {
            set->remove(array[i]);
        }

        for (int i = 0; i < 10; ++i)
        {
            QVERIFY(!set->exist(array[i]));
        }
    }
};
