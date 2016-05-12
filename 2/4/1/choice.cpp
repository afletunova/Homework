#include <iostream>
#include "choice.h"

using namespace std;

const int length = 32;

enum {toExit, addElement, removeElement, getSizeOfArray};
bool choice(int answer, HashTable *hashTable)
{
    char *word = new char[length];
    word = "\0";
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
        cout << "Enter a value to remove: " << endl;
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
    case getSizeOfArray:
    {
        cout << hashTable->getSize() << endl;
        return false;
    }
    }
    return false;
}
