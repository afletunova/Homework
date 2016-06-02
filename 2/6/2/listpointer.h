#pragma once

template <typename T>
/*!
 * \brief The ListPointer class - class that inherits from the List class. Represent list on pointers.
 */
class ListPointer
{
public:
    ListPointer();
    bool add(const T &value);
    bool remove(const T &value);
    bool exist(const T &value);
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
        ElementOfList(const T &value);
        T key;
        ElementOfList *next;
        ElementOfList *previous;
    };

    ~ListPointer();
    bool removeList(ElementOfList *head);
private:
    ElementOfList *head;
    int size;
};

template <typename T>
ListPointer<T>::ListPointer()
    :size(0)
{
    head = new ElementOfList();
}

template <typename T>
ListPointer<T>::ElementOfList::ElementOfList()
    :next(nullptr), previous(nullptr)
{}

template <typename T>
ListPointer<T>::ElementOfList::ElementOfList(const T &value)
    :next(nullptr), previous(nullptr)
{
    key = value;
}

template <typename T>
bool ListPointer<T>::add(const T &value)
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

template <typename T>
bool ListPointer<T>::remove(const T &value)
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

template <typename T>
bool ListPointer<T>::exist(const T &value)
{
    ElementOfList *auxiliary = head;
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
int ListPointer<T>::getSize()
{
    return size;
}

template <typename T>
bool ListPointer<T>::removeList(ElementOfList *head)
{
    while (head)
    {
        ElementOfList *nextHead = head->next;
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
