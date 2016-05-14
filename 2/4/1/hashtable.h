#pragma once

#include <QString>
#include "listpointer.h"
#include "hashfaq6.h"
#include "hashrot13.h"
#include "hashrs.h"

enum numberOfHashFunction
{
    faq6,
    rot13,
    rs
};

class HashTable
{
public:
    HashTable(int size);
    int hashFunction(const QString &word);
    bool add(const QString &word);
    bool remove(const QString &word);
    bool find(const QString &word) const;
    void getStatistics() const;
    void chooseHashFunction(numberOfHashFunction number);
    int getMaximalLengthOfList() const;
    int getSize();
    ~HashTable();

private:
    ListPointer **hashTable;
    HashFunction *usingHashFunction;

    int hashSize;
    int numberOfCells;
    int numberOfConflicts;
};
