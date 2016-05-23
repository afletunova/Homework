#include "operand.h"

#include <iostream>

using namespace std;

Operand::Operand(const int &value)
    :value(value)
{}

int Operand::compute()
{
    return value;
}

void Operand::printResult()
{
    cout << value;
}
