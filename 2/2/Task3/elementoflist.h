#pragma once

template <typename T>
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
    T getKey();
    ElementOfList<T> *getNext();
    void setNext(ElementOfList<T> *element);
    ElementOfList<T> *getPrevious();
    void setPrevious(ElementOfList<T> *element);

private:
    T key;
    ElementOfList *next;
    ElementOfList *previous;
};

template <typename T>
ElementOfList<T>::ElementOfList()
    :next(nullptr), previous(nullptr)
{}

template <typename T>
ElementOfList<T>::ElementOfList(const T &value)
    :next(nullptr), previous(nullptr)
{
    key = value;
}

template <typename T>
T ElementOfList<T>::getKey()
{
    return key;
}

template <typename T>
ElementOfList<T> *ElementOfList<T>::getNext()
{
    if (!next)
    {
        return nullptr;
    }
    return next;
}

template <typename T>
void ElementOfList<T>::setNext(ElementOfList<T> *element)
{
    next = element;
}

template <typename T>
ElementOfList<T> *ElementOfList<T>::getPrevious()
{
    if (!previous)
    {
        return nullptr;
    }
    return previous;
}

template <typename T>
void ElementOfList<T>::setPrevious(ElementOfList<T> *element)
{
    previous = element;
}
