#include <iostream>
#include "choice.h"

using namespace std;

enum {toExit, addElement, removeElement, getSizeOfArray};
bool choice(int answer, HashTable *hashTable)
{
    switch(answer)
    {
    case toExit: return true;
    case addElement:
    {
        int value = 0;
        cout << "Enter a value to add: " << endl;
        cin >> value;
        if (hashTable->addElementToList(value))
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
        int value = 0;
        cout << "Enter a value to add: " << endl;
        cin >> value;
        if (hashTable->removeElementFromList(value))
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
