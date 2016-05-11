#include "arraylist.h"
#include <iostream>

using namespace std;

ArrayList::ArrayList()
    :size(0), array(new int[maxArraySize])
{}

bool ArrayList::addElementToList(int value)
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

bool ArrayList::removeElementFromList(int value)
{
    if (size > 0)
    {
        int i = 1;
        while ((i <= size) && (array[i] != value))
        {
            ++i;
        }
        if (array[i] == value)
        {
            for (int j = 0; j < size; ++j)
            {
                array[i] = array[i + 1];
            }
            --size;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int ArrayList::getSize()
{
    return size;
}

ArrayList::~ArrayList()
{
    delete[] array;
}
