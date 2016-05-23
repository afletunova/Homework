#include "operator.h"
#include "divisionbyzeroerror.h"

#include <iostream>

using namespace std;

Operator::Operator()
    :operation('\0')
{}

int Operator::compute()
{
    int leftValue = left->compute();
    int rightValue = right->compute();

    switch(operation)
    {
    case '+':
    {
        return leftValue + rightValue;
    }
    case '-':
    {
        return leftValue - rightValue;
    }
    case '*':
    {
        return leftValue * rightValue;
    }
    case '/':
    {
        try
        {
            if (rightValue == 0)
            {
                throw DivisionByZeroError();
            }
            else
            {
                return leftValue / rightValue;
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
}

void Operator::printResult()
{
    cout << "(" << operation << " ";
    left->printResult();
    cout << " ";
    right->printResult();
    cout << ")";
}

void Operator::changeOperation(const &operation)
{
    this->operation = operation;
}



