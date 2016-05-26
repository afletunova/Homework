#pragma once

#include <iostream>

using namespace std;

class SomeClass
{
public:
    SomeClass()
    {
        cout << "Created object of SomeClass." << endl;
    }

    ~SomeClass()
    {
        cout << "Removed object of SomeClass." << endl;
    }
};
