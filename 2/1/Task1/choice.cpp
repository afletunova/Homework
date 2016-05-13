#include <iostream>
#include "choice.h"

using namespace std;

enum {toExit, addElement, removeElement, getSizeOfArray};
bool choice(int answer, List *list)
{
    switch(answer)
    {
    case toExit: return true;
    case addElement:
    {
        int value = 0;
        cout << "Enter a value to add: " << endl;
        cin >> value;
        if (list->add(value))
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
        if (list->remove(value))
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
        cout << list->getSize() << endl;
        return false;
    }
    }
    return false;
}
