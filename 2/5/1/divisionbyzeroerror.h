#pragma once

#include <iostream>

using namespace std;

/*!
 * \brief The DivisionByZeroError class - class for exception then detected tried to divide by zero
 */

class DivisionByZeroError
{
public:
    DivisionByZeroError()
    {
        cout << "Division by zero!" << endl;
    }
};
