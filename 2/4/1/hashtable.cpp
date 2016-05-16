#include "hashtable.h"

#include <iostream>

using namespace std;

HashTable::HashTable(int size)
    :hashSize(size), numberOfCells(0), numberOfConflicts(0), usingHashFunction(nullptr)
{
    hashTable = new ListPointer *[hashSize];
    for (int i = 0; i < hashSize; ++i)
    {
        hashTable[i] = new ListPointer;
    }
}

bool HashTable::add(const QString &word)
{
    unsigned int hashIndex = usingHashFunction->useHashFunction(word, hashSize);
    hashTable[hashIndex]->add(word);
    ++numberOfCells;
    int listSize = hashTable[hashIndex]->getSize();
    if (listSize > 1)
    {
        ++numberOfConflicts;
    }
}

bool HashTable::remove(const QString &word)
{
    unsigned int hashIndex = usingHashFunction->useHashFunction(word, hashSize);
    hashTable[hashIndex]->remove(word);
    --numberOfCells;
    int listSize = hashTable[hashIndex]->getSize();
    if (listSize = 1)
    {
        --numberOfConflicts;
    }
}

bool HashTable::find(const QString &word) const
{
    unsigned int hashIndex = usingHashFunction->useHashFunction(word, hashSize);
    return hashTable[hashIndex]->exist(word);
}

void HashTable::getStatistics() const
{
    cout << "Statictics on the hash table: " << endl
         << "Total number of cells: " << numberOfCells << endl
         << "Load factor: " << (double) numberOfCells / hashSize << endl
         << "Number of collision: " << numberOfConflicts << endl
         << "Maximum length of list in a conflict(collision) cells: " << getMaximalLengthOfList() << endl;
}

int HashTable::getMaximalLengthOfList() const
{
    if (numberOfConflicts == 0)
    {
        return 0;
    }

    int maxLengthOfList = 0;
    for (int i = 0; i < hashSize; ++i)
    {
        int size = hashTable[i]->getSize();
        if (size > maxLengthOfList)
        {
            maxLengthOfList = size;
        }
    }
    return maxLengthOfList;
}

void HashTable::chooseHashFunction(int number)
{
    switch(number)
    {
    case faq6:
    {
        usingHashFunction = new HashFAQ6;
        break;
    }
    case rot13:
    {
        usingHashFunction = new HashRot13;
        break;
    }
    case rs:
    {
        usingHashFunction = new HashRs;
        break;
    }
    }
}



int HashTable::getSize()
{
    return hashSize;
}

HashTable::~HashTable()
{
    delete hashTable;
    delete usingHashFunction;
}

