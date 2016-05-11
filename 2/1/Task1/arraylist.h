#pragma once
#include "list.h"

/*!
 * \brief The ArrayList class - class that inherits from the List class. Represent list on array.
 */
class ArrayList : public List
{
public:
    ArrayList();
    bool add(int value);
    bool remove(int value);
    int getSize();
    ~ArrayList();
private:
    static int const maxArraySize = 256;
    int *array;
    int size;
};
