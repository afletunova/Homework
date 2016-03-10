#pragma once
#include "list.h"

class ListPointer : public List
{
public:
    ListPointer();
    bool addElementToList(int value);
    bool removeElementFromList(int value);
    int getSize();
    class ElementOfList
    {
    public:
        ElementOfList();
        ElementOfList(int value);
        int key;
        ElementOfList *next;
        ElementOfList *previous;
    };
    ~ListPointer();
    bool removeList(ElementOfList *head);
private:
    ElementOfList *head;
    int size;
};
