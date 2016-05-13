#pragma once
#include "list.h"

/*!
 * \brief The ListPointer class - class that inherits from the List class. Represent list on pointers.
 */

class ListPointer : public List
{
public:
    ListPointer();
    bool add(int value);
    bool remove(int value);
    int getSize();
    /*!
     * \brief The ElementOfList class - convenience class, which is a class field.
     */
    class ElementOfList
    {
    public:
        ElementOfList();
        /*!
         * \brief ElementOfList - constructor to the case where value is known.
         * \param value
         */
        ElementOfList(int value);
        int key;
        ElementOfList *next;
        ElementOfList *previous;
        ~ElementOfList();
    };
    ~ListPointer();
    bool removeList(ElementOfList *head);
private:
    ElementOfList *head;
    int size;
};
