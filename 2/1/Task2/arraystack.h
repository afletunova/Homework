#pragma once
#include "stack.h"

/*!
 * \brief The ArrayStack class - class that inherits from the Stack class. Represent s on array with an integer elements.
 */

class ArrayStack : public Stack<int>
{
public:
    ArrayStack();
    bool push(const int &value);
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
