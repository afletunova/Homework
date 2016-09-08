#pragma once
#include "listpointer.h"

/*!
 * \brief The EmptySet class - exception for the case when sorted set is empty
 */
class EmptySet
{};

template <class T>

/*!
 * \brief The SortedSet class - class that implements Sorted Set, based on the list on pointers integrated with comparator.
 */

class SortedSet
{
public:
    SortedSet();
    bool isEmpty();
    T max();
    T min();
    bool add(const T &value);
    bool remove(const T &value);
    bool exist(const T &value);
    int getSize() const;
    ElementOfList<T> *getHead();
    ~SortedSet();

private:
    ListsComparator<T> *comparator;
    ElementOfList<T> *head;
    int size;
};

template <class T>
SortedSet<T>::SortedSet()
    :size(0)
{
    head = new ElementOfList<T>;
    comparator = new ListsComparator<T>;
}

template <class T>
bool SortedSet<T>::isEmpty()
{
    return (this->getSize() == 0);
}

template <class T>
T SortedSet<T>::max()
{
    if (this->isEmpty())
    {
        throw EmptySet();
    }

    ElementOfList<T> *auxiliary = this->getHead();
    T max = auxiliary->getKey();
    while(auxiliary->getNext())
    {
        auxiliary = auxiliary->getNext();
        if (comparator->less(max, auxiliary->getKey()))
        {
            max = auxiliary->getKey();
        }
    }
    return max;
}

template <class T>
T SortedSet<T>::min()
{
    if (this->isEmpty())
    {
        throw EmptySet();
    }

    ElementOfList<T> *auxiliary = this->getHead();
    T *min = auxiliary->getKey();
    while(auxiliary->getNext())
    {
        auxiliary = auxiliary->getNext();
        if (comparator->less(auxiliary->getKey(), min))
        {
            min = auxiliary->getKey();
        }
    }
    return min;
}

template <class T>
bool SortedSet<T>::add(const T &value)
{
    ElementOfList<T> *auxiliary = new ElementOfList<T>(value);
    if (size == 0)
    {
        head = auxiliary;
    }
    else
    {
        ElementOfList<T> *element = head;
        while (element->getNext() && element->getKey() > value)
        {
            element = element->getNext();
        }
        auxiliary->setNext(element->getNext());
        auxiliary->setPrevious(element);
        element->setNext(auxiliary);
    }
    ++size;
    return true;
}

template <class T>
bool SortedSet<T>::remove(const T &value)
{
    if (head)
    {
        ElementOfList<T> *element = head;
        if(element->getNext())
        {
            while(element->getNext() && !comparator->equal(element->getKey(),value))
            {
                element = element->getNext();
            }
            if(!comparator->equal(element->getKey(), value))
            {
                return false;
            }
            else
            {
                element->getPrevious()->setNext(nullptr);
                delete element;
                --size;
                return true;
            }
        }
        else if(comparator->equal(head->getKey(), value))
        {
            delete head;
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

template <class T>
bool SortedSet<T>::exist(const T &value)
{
    ElementOfList<T> *auxiliary = head;
    while (auxiliary)
    {
        if (auxiliary->getKey() == value)
        {
            return true;
        }
        auxiliary = auxiliary->getNext();
    }
    return false;
}

template <class T>
int SortedSet<T>::getSize() const
{
    return size;
}

template <class T>
ElementOfList<T> *SortedSet<T>::getHead()
{
    return head;
}

template <class T>
SortedSet<T>::~SortedSet()
{
    delete comparator;
    delete head;
}
