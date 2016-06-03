#pragma once

#include "sortedset.h"

#include <QtCore/QObject>
#include <QtTest/QtTest>

class SortedSetTest : public QObject
{
    Q_OBJECT
private:
    SortedSet<int> *set;
    ListPointer<int> *firstList;
    ListPointer<int> *secondList;

private slots:
    void init()
    {
        set = new SortedSet<int>;
        firstList = new ListPointer<int>;
        secondList = new ListPointer<int>;
    }

    void cleanup()
    {
        delete firstList;
        delete secondList;
        delete set;
    }

    void addEmptyList()
    {
        set->add(firstList);
        QVERIFY(set->exist(firstList));
    }

    void addListAndCheckAnother()
    {
        firstList->add(1);
        set->add(firstList);
        QVERIFY(!set->exist(secondList));
    }

    void addAndRemoveList()
    {
        firstList->add(2);
        secondList->add(1);
        secondList->add(3);
        set->add(firstList);
        set->add(secondList);
        set->remove(secondList);
        QVERIFY(!set->exist(secondList));
    }

    void EmptySetTest()
    {
        try
        {
            set->max();
        }
        catch(EmptySet &)
        {
            QVERIFY(true);
        }
        QVERIFY_EXCEPTION_THROWN(set->max(), EmptySet);
    }

    void findMaxTest()
    {
        firstList->add(1);
        firstList->add(2);
        secondList->add(1);
        secondList->add(2);
        secondList->add(3);
        set->add(firstList);
        set->add(secondList);
        QCOMPARE(set->max(), secondList);
    }
};
