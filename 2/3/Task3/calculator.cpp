#include "calculator.h"
#include <iostream>
#include <QString>
#include <cctype>

using namespace std;

Calculator::Calculator(const QString &expression)
    :expression(expression)
{}

float Calculator::calculate()
{
    parser();

    int sign = 1;
    int count = 0;
    float coefficient = 0.1;
    bool afterPoint = false;
    char previousSymbol = '\0';
    float currentNumber = 0.0;
    QByteArray array = expression.toLocal8Bit();
    int length = expression.size();
    for (int i = 0; i < length; ++i)
    {
        char symbol = array.data()[i];
        if (isdigit(symbol) || (symbol == '.'))
        {
            if (previousSymbol == '-')
            {
                sign = -1;
            }
            if (afterPoint)
            {
                currentNumber = currentNumber * coefficient + (symbol - '0');
                coefficient /= 10;
            }
            else
            {
                currentNumber = currentNumber * 10 + (symbol - '0');
            }
        }
        else if (symbol == ' ' && isdigit(previousSymbol))
        {
            stack.push(sign * currentNumber);
            ++count;
            sign = 1;
            coefficient = 0.1;
            currentNumber = 0.0;
            afterPoint = false;
        }
        else if (isOperation(symbol))
        {
            if (isdigit(previousSymbol))
            {
                stack.push(currentNumber);
                ++count;
                sign = 1;
                coefficient = 0.1;
                currentNumber = 0.0;
                afterPoint = false;
            }
            if (count >= 2)
            {
                stack.push(calculation(symbol));
                --count;
            }
        }
        previousSymbol = symbol;
    }
    return stack.pop();
}

void Calculator::parser()
{
    int length = expression.size();
    char *result = new char[length * 2]();
    char previousSymbol = '\0';
    bool afterOperation = false;
    bool minusWaitingOfOperand = false;
    int j = -1;
    QByteArray array = expression.toLocal8Bit();
    QStack<char> operations;

    for (int i = 0; i < length; ++i)
    {
        char symbol = array.data()[i];
        if (!isdigit(symbol) && isdigit(previousSymbol))
        {
            result[++j] = ' ';
        }
        if (isdigit(symbol) || symbol == '.')
        {
            if (minusWaitingOfOperand)
            {
                result[++j] = '-';
                minusWaitingOfOperand = false;
            }
            result[++j] = symbol;
        }
        else if (symbol == '(')
        {
            operations.push('(');
        }
        else if (symbol == ')')
        {
            while (operations.top() != '(')
            {
                result[++j] = operations.pop();
            }
            if (operations.top() == '(')
            {
                operations.pop();
            }
            else
            {
                throw EnteredExpressionIsIncorrect();
            }
        }
        else if (isOperation(symbol))
        {
            if ((symbol == '-') && afterOperation)
            {
                minusWaitingOfOperand = true;
            }
            if (operations.empty())
            {
                operations.push(symbol);
            }
            else if (priority(operations.top()) < priority(symbol))
            {
                operations.push(symbol);
            }
            else
            {
                while (!operations.empty()
                       && (priority(operations.top()) >= priority(symbol)))
                {
                    result[++j] = operations.pop();
                }
                operations.push(symbol);
            }
        }
        if (!isOperation(symbol) && afterOperation)
        {
            afterOperation = false;
        }
        if (!isdigit(symbol) && !((symbol == '-') && minusWaitingOfOperand))
        {
            result[++j] = ' ';
        }
    }
    while (!operations.empty())
    {
        result[++j] = operations.pop();
    }

    result[++j] = '\0';
    expression = QString(result);
    delete[] result;
}

bool Calculator::isOperation(const char &symbol)
{
    return ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/') || (symbol == '-'));
}

int Calculator::priority(const char &operation) const
{
    switch(operation)
    {
    case '*':
    case '/': return 2;
    case '-':
    case '+': return 1;
    default: return 0;
    }
}

float Calculator::calculation(const char &operation)
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
