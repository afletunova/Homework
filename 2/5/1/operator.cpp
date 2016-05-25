#include "operator.h"
#include "divisionbyzeroerror.h"

#include <iostream>

using namespace std;

Operator::Operator()
    :operation('\0')
{}

int Operator::compute()
{
    int firstNumber = left->compute();
    int secondNumber = right->compute();
    switch (operation)
    {
    case '+':
    {
        return (firstNumber + secondNumber);
    }
    case '-':
    {
        return (firstNumber - secondNumber);
    }
    case '*':
    {
        return  (firstNumber * secondNumber);
    }
    case '/':
    {
        try
        {
            if (secondNumber == 0)
            {
                throw DivisionByZeroError();
            }
            else
            {
                return (float)(firstNumber / secondNumber);
            }
        }
        catch (const DivisionByZeroError &error)
        {
            cout << "Division by zero!" << endl;
        }
    }
    default:
    {
        break;
    }
    }
    return 0;
}

void Operator::print()
{
    cout << "(" << operation << " ";
    left->print();
    cout << " ";
    right->print();
    cout << ")";
}

void Operator::changeOperation(const &operation)
{
    this->operation = operation;
}



