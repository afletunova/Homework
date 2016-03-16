#pragma once
#include "stack.h"

class ArrayStack : public Stack<int>
{
public:
    ArrayStack();
    bool push(int value);
    int pop();
    int getSize()
    {
        return size;
    }
    ~ArrayStack();
private:
    static int const maxArraySize = 256;
    int *array;
    int size;
};
