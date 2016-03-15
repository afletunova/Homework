#pragma once
#include "list.h"

class ArrayList : public List
{
public:
    ArrayList();
    bool addElementToList(int value);
    bool removeElementFromList(int value);
    int getSize();
    ~ArrayList();
private:
    static int const maxArraySize = 256;
    int *array;
    int size;
};
