#include "stackcalculator.h"
#include "stack.h"
#include "pointerstack.h"
#include "arraystack.h"

#include <cctype>

int length = 100;

using namespace std;

int calculation(char operation, int firstVariable, int secondVariable)
{
    switch (operation)
    {
    case '+': return firstVariable + secondVariable;
    case '-': return firstVariable - secondVariable;
    case '/': return firstVariable / secondVariable;
    case '*': return firstVariable * secondVariable;
    }
}

int priority(char c)
{
    switch (c)
    {
    case '*':
    case '/':
        return 3;

    case '-':
    case '+':
        return 2;
    case '(':
        return 1;
    }
}

string FromInfixToPostfix(string entered)
{
    int length = entered.length();
    string returned;
    PointerStack<char> *operations = new PointerStack<char>;
    for (int i = 0; i < entered.length(); ++i)
    {
        if (entered.compare(i,1," "))
        {
            if (entered.compare(i,1,")") == 0)
            {
                char symbol = operations->pop();
                while (symbol != '(')
                {
                    returned += symbol;
                    symbol = operations->pop();
                }
            }
            else if (isdigit(entered[i]))
            {
                returned += entered[i];
            }
            else if (entered.compare(i,1,"(") == 0)
            {
                operations->push('(');
            }
            else if ((entered[i] == '+') || (entered[i] == '*') || (entered[i] == '/') || (entered[i] == '-'))
            {
                if (operations->getSize() == 0)
                {
                    operations->push(entered[i]);
                }
                else if (priority(operations->top->returnKey()) < priority(entered[i]))
                {
                    operations->push(entered[i]);
                }
                else
                {
                    while ((operations->getSize() != 0) && (priority(operations->top->returnKey()) >= priority(entered[i])))
                    {
                        returned += operations->pop();
                    }
                    operations->push(entered[i]);
                }
            }
        }
    }
    while (operations->getSize() != 0)
    {
        returned += operations->pop();
    }
    return returned;
}

int PostfixCalculator(string entered)
{
    ArrayStack *numbers = new ArrayStack;
    int length = entered.length();
    for (int i = 0; i < length; ++i)
    {
        if (isdigit(entered[i]))
        {
           char symbol = entered[i];
           numbers->push(symbol - '0');
        }
        else
        {
            if ((entered[i] == '+') || (entered[i] == '*') || (entered[i] == '/') || (entered[i] == '-'))
            {
                if (numbers->getSize() > 1)
                {
                    int firstNumber = numbers->pop();
                    int secondNumber = numbers->pop();
                    numbers->push(calculation(entered[i], secondNumber, firstNumber));
                }
            }
        }
    }
    return numbers->pop();
}

int calculator(string entered)
{
    return PostfixCalculator(FromInfixToPostfix(entered));
}
