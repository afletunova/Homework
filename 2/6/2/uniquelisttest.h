#pragma once

#include "uniquelist.h"

#include <QtTest/QtTest>
#include <QtCore/QObject>

class UniqueListTest : public QObject
{
    Q_OBJECT

private:
    UniqueList<int> *list;

private slots:
    void init()
    {
        list = new UniqueList<int>();
    }

    void cleanup()
    {
        delete list;
    }

    void emptyUniqueListTest()
    {
        QCOMPARE(list->getSize(), 0);
    }

    void AddElementTest()
    {
        list->add(1);
        QVERIFY(list->exist(1));
    }

    void AddAndRemoveTest()
    {
        list->add(1);
        list->remove(1);
        QVERIFY(!list->exist(1));
    }

    void AddOneElementTwiceTest()
    {
        list->add(1);
        try
        {
            list->add(1);
        }
        catch (TryingToAddExistentElement &)
        {
            QVERIFY(true);
        }
        QVERIFY_EXCEPTION_THROWN(list->add(1), TryingToAddExistentElement);
    }

    void RemoveNonExistentElementTest()
    {
        try
        {
            list->remove(1);
        }
        catch (TryingToRemoveNonExistentElement &)
        {
            QVERIFY(true);
        }
        QVERIFY_EXCEPTION_THROWN(list->remove(1), TryingToRemoveNonExistentElement);
    }
};
