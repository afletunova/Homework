#pragma once

#include <QString>

/*!
 * \brief The ListPointer class - class that implements ADT "List" on pointers
 */

class ListPointer
{
public:
    ListPointer();
    bool add(const QString $word);
    bool remove(const QString &word);
    int getSize();
    bool exist(const QString &word);
    class ElementOfList
    {
    public:
        ElementOfList();
        ElementOfList(const QString &word);
        QString key;
        ElementOfList *next;
        ElementOfList *previous;
    };
    ~ListPointer();
    bool removeList(ElementOfList *head);
private:
    ElementOfList *head;
    int size;
};
