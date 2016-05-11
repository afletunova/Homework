#include <iostream>
#include "list.h"
#include "listpointer.h"
#include "arraylist.h"
#include "choice.h"

using namespace std;

int main()
{
    List *pointerList = new ListPointer();
    List *listArray = new ArrayList();

    int answer = 0;
    bool exit = false;
    cout << "Class <<ListPointer>> options:" << endl;
    while (!exit)
    {
        cout << "Enter:\n"
             << "0 to exit;\n"
             << "1 to add a value to list;\n"
             << "2 to remove an elemenet from list;\n"
             << "3 to get size of list;\n";

        cin >> answer;
        exit = choice(answer, pointerList);
    }

    exit = false;
    cout << "Class <<ArrayList>> options:" << endl;
    while (!exit)
    {
        cout << "Enter:\n"
             << "0 to exit;\n"
             << "1 to add a value to list;\n"
             << "2 to remove an elemenet from list;\n"
             << "3 to get size of list;\n";

        cin >> answer;
        exit = choice(answer, listArray);
    }

    return 0;
}
