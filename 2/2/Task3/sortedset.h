#pragma once
#include "listpointer.h"

template <typename T>

/*!
 * \brief The SortedSet class - class that implements Sorted Set, based on the list on pointers integrated with comparator.
 */

class SortedSet : public ListPointer<ListPointer<T> *>
{
public:
    SortedSet(){}
    ~SortedSet(){}
};
