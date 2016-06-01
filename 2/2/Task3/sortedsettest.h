#pragma once

#include "sortedset.h"

#include <QtCore/QObject>
#include <QtTest/QtTest>

class SortedSetTest : public QObject
{
    Q_OBJECT
private:
    SortedSet<int> set;
    ListPointer<int> *firstList;
    ListPointer<int> *secondList;
    ListPointer<int> *thirdList;

private slots:
    void init()
    {
        firstList = new ListPointer<int>;
        secondList = new ListPointer<int>;
    }

    void cleanup()
    {
        delete firstList;
        delete secondList;
    }

    void addEmptyList()
    {
        set.add(firstList);
        QVERIFY(set.exist(firstList));
    }

    void addListAndCheckAnother()
    {
        firstList->add(1);
        set.add(firstList);
        QVERIFY(!set.exist(secondList));
    }

    void addAndRemoveList()
    {
        firstList->add(2);
        secondList->add(1);
        secondList->add(3);
        set.add(firstList);
        set.add(secondList);
        set.remove(secondList);
        QVERIFY(!set.exist(secondList));
    }
};
