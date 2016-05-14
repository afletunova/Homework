#pragma once

#include <QString>
#include "listpointer.h"
#include "hashfaq6.h"
#include "hashrot13.h"
#include "hashrs.h"

enum {
    faq6,
    rot13,
    rs
};

/*!
 * \brief The HashTable class - class that implements a hash table.
 */

class HashTable
{
public:
    HashTable(int size);
    int hashFunction(const QString &word, const int &hashSize);
    bool add(const QString &word);
    bool remove(const QString &word);
    /*!
     * \brief find - function that determines whether there is such a word in the hash table
     * \param word - takes word
     * \return true, if word is in the hash table; false, if there is no word
     */
    bool find(const QString &word) const;
    void getStatistics() const;
    void chooseHashFunction(int number);
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
