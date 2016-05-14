#include "listpointer.h"

ListPointer::ListPointer()
    :size(0)
{
    head = new ElementOfList();
}

ListPointer::ElementOfList::ElementOfList()
    :next(nullptr), previous(nullptr)
{}

ListPointer::ElementOfList::ElementOfList(const QString &word)
{
    key = word;
}

bool ListPointer::add(QString $word)
{
    ElementOfList *element = head;
    if (element)
    {
        while (element->next && element->key > $word)
        {
            element = element->next;
        }
    }
    ElementOfList *auxiliary = new ElementOfList($word);
    auxiliary->next = element->next;
    auxiliary->previous = element;
    element->next = auxiliary;
    ++size;
    return true;
}

bool ListPointer::remove(const QString &word)
{
    if (head)
    {
        ElementOfList *element = head;
        if(element->next)
        {
            while(element->next && element->key != word)
            {
                element = element->next;
            }
            if(element->key != word)
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
        else if(head->key == word)
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

bool ListPointer::exist(const QString &word)
{
    ElementOfList *auxiliary = head;
    while (auxiliary)
    {
        if (auxiliary->key == word)
        {
            return true;
        }
        auxiliary = auxiliary->next;
    }
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
