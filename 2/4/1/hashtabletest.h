#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>

#include "hashtable.h"

const int hashSize = 100;

class HashTableTest : public QObject
{
    Q_OBJECT

private:
    HashTable *table;
    QString word;

private slots:
    void init()
    {
        table = new HashTable(hashSize);
        table->chooseHashFunction(0);
        word = "String";
    }

    void testAddElementInHashTable()
    {
        table->add(word);
        QCOMPARE(table->getNumberOfCells(), 1);
    }

    void testAddSameElementsInHashTable()
    {
        table->add(word);
        table->add(word);
        QCOMPARE(table->getMaximalLengthOfList(), 2);
    }

    void testAddAndRemoveElement()
    {
        table->add(word);
        table->remove(word);
        QCOMPARE(table->getNumberOfCells(), 0);
    }

    void cleanup()
    {
        delete table;
    }
};

