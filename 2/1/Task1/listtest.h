#pragma once

#include "list.h"
#include "listpointer.h"
#include "arraylist.h"

#include <QtCore/QObject>
#include <QtTest/QtTest>

class ListTest : public QObject
{
    Q_OBJECT

private:
    List *list = nullptr;

private slots:
    void testEmptyArrayList()
    {
        list = new ArrayList;
        QVERIFY(list->getSize() == 0);
    }

    void testEmptyPointerList()
    {
        list = new ListPointer;
        QVERIFY(list->getSize() == 0);
    }

    void testAddSingleElementToArrayList()
    {
        list = new ArrayList;
        list->addElementToList(5);
    }

    void testAddSingleElementToPointerList()
    {
        list = new ListPointer;
        list->addElementToList(5);
    }

    void testChangeSizeByAddSingleElementToArrayList()
    {
        list = new ArrayList;
        list->addElementToList(5);
        QVERIFY(list->getSize() == 1);
    }

    void testChangeSizeByAddSingleElementToPointerList()
    {
       list = new ListPointer;
       list->addElementToList(5);
       QVERIFY(list->getSize() == 1);
    }

    void testAddMoreThanOneElementToArrayList()
    {
        list = new ArrayList;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            list->addElementToList(i);
        }
        QVERIFY(list->getSize() == n);
    }

    void testAddMoreThanOneElementToPointerList()
    {
        list = new ListPointer;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            list->addElementToList(i);
        }
        QVERIFY(list->getSize() == n);
    }

    void testRemoveElementFromEmptyArrayList()
    {
        list = new ArrayList;
        list->removeElementFromList(5);
        QVERIFY(list->getSize() == 0);
    }

    void testRemoveElementFromEmptyPointerList()
    {
        list = new ListPointer;
        list->removeElementFromList(5);
        QVERIFY(list->getSize() == 0);
    }

    void testRemoveRandomElementFromArrayList()
    {
        list = new ArrayList;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            list->addElementToList(i);
        }
        list->removeElementFromList(n/2);
        QVERIFY(list->getSize() == (n-1));
    }

    void testRemoveRandomElementFromPointerList()
    {
        list = new ListPointer;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            list->addElementToList(i);
        }
        list->removeElementFromList(n/2);
        QVERIFY(list->getSize() == (n-1));
    }

    void testRemoveFirstElementFromArrayList()
    {
        list = new ArrayList;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            list->addElementToList(i);
        }
        list->removeElementFromList(0);
        QVERIFY(list->getSize() == (n-1));
    }

    void testRemoveFirstElementFromPointerList()
    {
        list = new ListPointer;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            list->addElementToList(i);
        }
        list->removeElementFromList(0);
        QVERIFY(list->getSize() == (n-1));
    }

    void testRemoveLastElementFromArrayList()
    {
        list = new ArrayList;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            list->addElementToList(i);
        }
        list->removeElementFromList(n-1);
        QVERIFY(list->getSize() == (n-1));
    }

    void testRemoveLastElementFromPointerList()
    {
        list = new ListPointer;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            list->addElementToList(i);
        }
        list->removeElementFromList(n-1);
        QVERIFY(list->getSize() == (n-1));
    }

    void testRemoveElementThatDoesNotExistFromArrayList()
    {
        list = new ArrayList;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            list->addElementToList(i);
        }
        list->removeElementFromList(n);
        QVERIFY(list->getSize() == (n));
    }

    void testRemoveElementThatDoesNotExistFromPointerList()
    {
        list = new ListPointer;
        int n = 5;
        for (int i = 0; i < n; ++i)
        {
            list->addElementToList(i);
        }
        list->removeElementFromList(n);
        QVERIFY(list->getSize() == (n));
    }
};

QTEST_MAIN(ListTest)
