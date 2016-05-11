#include "listpointer.h"

ListPointer::ListPointer()
    :size(0)
{
    head = new ElementOfList();
}

ListPointer::ElementOfList::ElementOfList()
    :next(nullptr), previous(nullptr)
{}

ListPointer::ElementOfList::ElementOfList(int value)
    :next(nullptr), previous(nullptr)
{
    key = value;
}

ListPointer::ElementOfList::~ElementOfList()
{
    delete next;
    delete previous;
}

bool ListPointer::add(int value)
{
    ElementOfList *element = head;
    if (element)
    {
        while (element->next && element->key > value)
        {
            element = element->next;
        }
    }
    ElementOfList *auxiliary = new ElementOfList(value);
    auxiliary->next = element->next;
    auxiliary->previous = element;
    element->next = auxiliary;
    ++size;
    return true;
}

bool ListPointer::remove(int value)
{
    if (head)
    {
        ElementOfList *element = head;
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

int ListPointer::getSize()
{
    return size;
}

bool ListPointer::removeList(ElementOfList *head)
{
    while (head)
    {
        ElementOfList *nextHead = head->next;
        delete head;
        head = nextHead;
    }
    return true;
}

ListPointer::~ListPointer()
{
    removeList(head);
}
