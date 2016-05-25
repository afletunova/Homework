#pragma once

#include "listpointer.h"

/*!
 * \brief The TryingToRemoveNonExistentElement class - error class.
 * For an exception, which throws when detected an attempt to delete an element that was not there.
 */
class TryingToRemoveNonExistentElement
{};

/*!
 * \brief The TryingToAddExistentElement class - error class.
 * For an exception, which throws when detected an attempt to add an element that is already in the list.
 */
class TryingToAddExistentElement
{};

template <typename T>
/*!
 * \brief The UniqueList class - class that implements list that containing no duplicate elements.
 */
class UniqueList
{
public:
    UniqueList();
    void add(const T &value);
    void remove(const T &value);
    bool exist(const T &value) const;
    int getSize() const;
    ~UniqueList();

private:
    ListPointer<T> *list;
};

template <typename T>
UniqueList<T>::UniqueList()
{
    list = new ListPointer<T>();
}

template <typename T>
void UniqueList<T>::add(const T &value)
{
    if (list->exist(value))
    {
        throw TryingToAddExistentElement();
    }
    list->add(value);
}

template <typename T>
void UniqueList<T>::remove(const T &value)
{
    if (!list->exist(value))
    {
        throw TryingToRemoveNonExistentElement();
    }
    list->remove(value);
}

template <typename T>
bool UniqueList<T>::exist(const T &value) const
{
    return list->exist(value);
}

template <typename T>
int UniqueList<T>::getSize() const
{
    return list->getSize();
}

template <typename T>
UniqueList<T>::~UniqueList()
{
    delete list;
}
