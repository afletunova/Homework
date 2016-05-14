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

void HashTable::getStatistics() const
{
    cout << "Statictics on the hash table: " << endl
         << "Total number of cells: " << numberOfCells << endl
         << "Load factor: " << numberOfCells / hashSize << endl
         << "Number of collision: " << numberOfConflicts << endl
         << "Maximum length of list in a conflict(collision) cells: " << maxLengthOfList << endl;
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

