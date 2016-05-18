#include <iostream>

#include "hashtable.h"
#include "hashtabletest.h"
#include "choice.h"

using namespace std;

const int size = 1000;

int main()
{
    HashTable *table = new HashTable(size);

    int answer = 0;
    bool exit = false;

    cout << "Choose hash function: \n"
         << "0 to choose FAG6 hash function; \n"
         << "1 to choose Rot13 hash function; \n"
         << "2 to choose Rs hash function; \n";
    cin >> answer;
    table->chooseHashFunction(answer);

    while (!exit)
    {
        cout << "Enter: \n"
             << "0 to exit; \n"
             << "1 to add element; \n"
             << "2 to remove element; \n"
             << "3 to get size of hash table; \n"
             << "4 to find element; \n"
             << "5 to show statistics; \n"
             << "6 to choose hash function: \n";

        cin >> answer;
        exit = choice(answer, table);
    }

    HashTableTest tester;
    QTest::qExec(&tester);

    return 0;
}
