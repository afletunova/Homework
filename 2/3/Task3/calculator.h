#pragma once

#include <QString>
#include <QStack>

class EnteredExpressionIsIncorrect
{};

class DivisionByZeroError
{};

class Calculator
{
public:
    Calculator(const QString &expression);
    float calculate();
    ~Calculator(){}

private:
     void parser();
     bool isOperation(const char &symbol);
     int priority(const char &operation) const;
     float calculation(const char &symbol);

     QString expression;
     QStack<float> stack;
};
