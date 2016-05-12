#include "hashtable.h"

HashTable::HashTable(int size)
    :hashSize(size), numberOfCells(0), loadFactor(0.0), numberOfConflicts(0), maxLengthOfList(0), usingHashFunction(nullptr)
{
    hashTable = new ListPointer *[hashSize];
    for (int i = 0; i < hashSize; ++i)
    {
        hashTable[i] = new ListPointer;
    }
}

void HashTable::chooseHashFunction(numberOfHashFunction number)
{
    if (number == faq6)
    {
        usingHashFunction = new HashFAQ6;
    }
    else if (number == rot13)
    {
        usingHashFunction = new HashRot13;
    }
    else
    {
        usingHashFunction = new HashRs;
    }
}



int HashTable::getSize()
{
    return hashSize;
}

