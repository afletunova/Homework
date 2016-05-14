#include <iostream>
#include "choice.h"

using namespace std;

const int length = 32;

enum {
    toExit,
    addElement,
    removeElement,
    getSizeOfHashTable,
    findElement,
    getStatisticsOfHashTable,
    toChooseHashFunction
};

bool choice(int answer, HashTable *hashTable)
{
    char *word = new char[length];
    switch(answer)
    {
    case toExit: return true;
    case addElement:
    {
        cout << "Enter word to add: " << endl;
        cin >> word;
        QString qstringWord(word);
        if (hashTable->add(qstringWord))
        {
            cout << "\n Completed successfully." << endl;
        }
        else
        {
            cout << "Something went wrong. Try again." << endl;
        }
        return false;
    }
    case removeElement:
    {
        cout << "Enter a word to remove: " << endl;
        cin >> word;
        QString qstringWord(word);
        if (hashTable->remove(qstringWord))
        {
            cout << "\n Completed successfully." << endl;
        }
        else
        {
            cout << "Something went wrong. Try again." << endl;
        }
        return false;
    }
    case getSizeOfHashTable:
    {
        cout << hashTable->getSize() << endl;
        return false;
    }
    case findElement:
    {
        cout << "Enter a word to find: " << endl;
        cin >> word;
        QString qstringWord(word);
        if (hashTable->find(word))
        {
            cout << "This word is in the table." << endl;
        }
        else
        {
            cout << "There is no such word in the table." << endl;
        }
        return false;
    }
    case getStatisticsOfHashTable:
    {
        hashTable->getStatistics();
        return false;
    }
    case toChooseHashFunction:
    {
        int choose = 0;
        cout << "Enter: \n"
             << "0 to choose FAG6 hash function; \n"
             << "1 to choose Rot13 hash function; \n"
             << "2 to choose Rs hash function; \n";

        cin >> choose;
        hashTable->chooseHashFunction(choose);
        return false;
    }
    }
    return false;
}
