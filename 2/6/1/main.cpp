#include "someclass.h"

#include <iostream>

using namespace std;

class SomeException
{};

int main()
{
    try
    {
        SomeClass someClass;
        throw SomeException();
    }
    catch(SomeException &)
    {
        cout << "Error!" << endl;
    }

    return 0;
}
