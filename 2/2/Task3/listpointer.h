#pragma once

#include "listscomparator.h"
#include "elementoflist.h"

template <typename T>
/*!
 * \brief The ListPointer class - class that inherits from the List class. Represent list on pointers.
 */
class ListPointer : public ListsComparator
{
public:
    ListPointer();
    bool add(const T &value);
    bool remove(const T &value);
    bool exist(const T &value);
    int getSize() const;

    ElementOfList<T> *getHead();
    ~ListPointer();

private:
    bool removeList(ElementOfList<T> *head) const;
    ElementOfList<T> *head;
    int size;
};

template <typename T>
ListPointer<T>::ListPointer()
    :size(0)
{
    head = new ElementOfList<T>();
}

template <typename T>
bool ListPointer<T>::add(const T &value)
{
    ElementOfList<T> *element = head;
    if (element)
    {
        while (element->next && element->key > value)
        {
            element = element->next;
        }
    }
    ElementOfList<T> *auxiliary = new ElementOfList<T>(value);
    auxiliary->next = element->next;
    auxiliary->previous = element;
    element->next = auxiliary;
    ++size;
    return true;
}

template <typename T>
bool ListPointer<T>::remove(const T &value)
{
    if (head)
    {
        ElementOfList<T> *element = head;
        if(element->next)
        {
            while(element->next && element->key != value)
            {
                element = element->next;
            }
            if(element->key != value)
            {
                return false;
            }
            else
            {
                element->previous->next = nullptr;
                delete element;
                --size;
                return true;
            }
        }
        else if(head->key == value)
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

template <typename T>
bool ListPointer<T>::exist(const T &value)
{
    ElementOfList<T> *auxiliary = head;
    while (auxiliary)
    {
        if (auxiliary->key == value)
        {
            return true;
        }
        auxiliary = auxiliary->next;
    }
    return false;
}

template <typename T>
int ListPointer<T>::getSize() const
{
    return size;
}

template <typename T>
ElementOfList<T> *ListPointer<T>::getHead()
{
    return head;
}

template <typename T>
bool ListPointer<T>::removeList(ElementOfList<T> *head) const
{
    while (head)
    {
        ElementOfList<T> *nextHead = head->next;
        delete head;
        head = nextHead;
    }
    return true;
}

template <typename T>
ListPointer<T>::~ListPointer()
{
    removeList(head);
}
