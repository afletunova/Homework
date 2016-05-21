#include "calculator.h"
#include "divisionbyzeroerror.h"

#include <iostream>
#include <cctype>

using namespace std;

Calculator::Calculator()
    :lineSize(lineSize), countNumbers(1), numberOfDigits(0)
{
    arrayOfBits = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arrayOfBits[i] = 0;
    }
}

QString Calculator::calculate()
{
    int sign = 1;
    if (*input == '-')
    {
        sign = -1;
    }
    QByteArray array = this->transform().toLocal8Bit();
    input = array.data();

    int *currentNumbers = new int[countNumbers];
    for (int i = 0; i < countNumbers; ++i)
    {
        currentNumbers[i] = 0;
    }

    int count = 0;
    int i = 0; int j = 0; int k = 0;
    while (*input && k < lineSize)
    {
        char currentSymbol = *input;
        if (isdigit(currentSymbol))
        {
            if (j < arrayOfBits[i + 1])
            {
                ++j;
            }
            else
            {
                stack.push(sign * currentNumbers[i]);
                sign = 1; j = 0;
                ++count; ++i;
            }
            currentNumbers[i] = currentNumbers[i] * 10 + (currentSymbol - '0');
        }
        else if (isOperation(currentSymbol))
        {
            stack.push(sign * currentNumbers[i]);
            j = 0;
            ++count; ++i;
            if (count >= 2)
            {
                stack.push(calculation(currentSymbol));
                --count;
            }
        }
        *input++; ++k;
    }
    return QString::number(stack.pop());
}

void Calculator::read(char *text, const int &size)
{
    input = text;
    lineSize = size;
}

Calculator::~Calculator()
{
    delete[] arrayOfBits;
}

QString Calculator::transform()
{
    char transformed[lineSize];
    int i = -1;
    QStack<char> operations;

    if (*input == '-')
    {
        *input++;
        --lineSize;
    }
    while(*input)
    {
        char symbol = *input;
        if (isdigit(symbol))
        {
            transformed[++i] = symbol;
            ++arrayOfBits[countNumbers];
            ++numberOfDigits;
        }
        else
        {
            if (isOperation(symbol))
            {
                ++countNumbers;
                if (operations.empty() || (priority(operations.top()) < priority(symbol)))
                {
                    operations.push(symbol);
                }
                else
                {
                    while (!operations.empty() && (priority(operations.top()) >= priority(symbol)))
                    {
                        transformed[++i] = operations.pop();
                    }
                    operations.push(symbol);
                }
            }
        }
        *input++;
    }
    while (!operations.empty())
    {
        transformed[++i] = operations.pop();
    }

    return QString(transformed);
}

int Calculator::priority(const char &operation)
{
    switch(operation)
    {
    case '*':
    case '/': return 2;
    case '-':
    case '+': return 1;
    }
}

bool Calculator::isOperation(const char &symbol)
{
    return ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/'));
}

double Calculator::calculation(const char &operation)
{
    int secondNumber = stack.pop();
    int firstNumber = stack.pop();

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
    }
}
