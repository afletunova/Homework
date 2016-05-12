#pragma once

#include <QString>
#include "listpointer.h"
#include "hashfunction.h"

class HashTable
{
public:
    HashTable();
    int hashFunction(const QString &word);
    bool add(const QString &word);
    bool remove(const QString &word);
    bool find(const QString &word) const;
    void getStatistics() const;
    void chooseHashFunction();
    int getSize();
    ~HashTable();

private:
    ListPointer **hashTable;
    HashFunction *usingHashFunction;

    int hashSize;
};
