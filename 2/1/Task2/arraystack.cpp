#include "arraystack.h"

ArrayStack::ArrayStack()
    :size(0), array(new int[maxArraySize])
{}

bool ArrayStack::push(const int &value)
{
    if (size < maxArraySize)
    {
        array[++size] = value;
        return true;
    }
    else
    {
        return false;
    }
}

int ArrayStack::pop()
{
    if (size > 0)
    {
        int outputValue = array[size];
        array[size] = 0;
        --size;
        return outputValue;
    }
    else
    {
        return 0;
    }
}

ArrayStack::~ArrayStack()
{
    delete[] array;
}
