#include "hashtable.h"

HashTable::HashTable(int size)
    :hashSize(size), numberOfCells(0), numberOfConflicts(0), maxLengthOfList(0), usingHashFunction(nullptr)
{
    hashTable = new ListPointer *[hashSize];
    for (int i = 0; i < hashSize; ++i)
    {
        hashTable[i] = new ListPointer;
    }
}

bool HashTable::add(const QString &word)
{
    unsigned int hashIndex = usingHashFunction->useHashFunction(word);
    hashTable[hashIndex]->add(word);
    ++numberOfCells;
    int listSize = hashTable[hashIndex]->getSize();
    if (listSize > 1)
    {
        ++numberOfConflicts;
    }
    if (listSize > maxLengthOfList)
    {
        maxLengthOfList = listSize;
    }
}

void HashTable::chooseHashFunction(numberOfHashFunction number)
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

