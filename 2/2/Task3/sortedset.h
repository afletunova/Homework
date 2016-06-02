#pragma once
#include "listpointer.h"

/*!
 * \brief The EmptySet class - exception for the case when sorted set is empty
 */
class EmptySet
{};

template <typename T>

/*!
 * \brief The SortedSet class - class that implements Sorted Set, based on the list on pointers integrated with comparator.
 */

class SortedSet : public ListPointer<ListPointer<T> *>
{
public:
    SortedSet(){}
    bool isEmpty();
    ListPointer<T> *MAX();
    ListPointer<T> *MIN();
    ~SortedSet(){}
};

template <typename T>
bool SortedSet<T>::isEmpty()
{
    return (this->getSize() == 0);
}

template <typename T>
ListPointer<T> *SortedSet<T>::MAX()
{
    if (this->isEmpty())
    {
        throw EmptySet();
    }

    ElementOfList<ListPointer<T> *> *auxiliary = this->getHead();
    ListPointer<T> *max = auxiliary->key;
    while(auxiliary->next)
    {
        auxiliary = auxiliary->next;
        if (auxiliary->key > max)
        {
            max = auxiliary->key;
        }
    }
    return max;
}

template <typename T>
ListPointer<T> *SortedSet<T>::MIN()
{
    if (this->isEmpty())
    {
        throw EmptySet();
    }

    ElementOfList<ListPointer<T> *> *auxiliary = this->getHead();
    ListPointer<T> *min = auxiliary->key;
    while(auxiliary->next)
    {
        auxiliary = auxiliary->next;
        if (auxiliary->key < min)
        {
            min = auxiliary->key;
        }
    }
    return min;
}
