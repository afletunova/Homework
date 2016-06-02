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
 * Inherited from class Pointer List.
 */
class UniqueList : public ListPointer<T>
{
public:
    UniqueList();
    void add(const T &value);
    void remove(const T &value);
    ~UniqueList(){}
};

template <typename T>
UniqueList<T>::UniqueList()
    :ListPointer<T>()
{}

template <typename T>
void UniqueList<T>::add(const T &value)
{
    if (this->exist(value))
    {
        throw TryingToAddExistentElement();
    }
    this->ListPointer<T>::add(value);
}

template <typename T>
void UniqueList<T>::remove(const T &value)
{
    if (!this->exist(value))
    {
        throw TryingToRemoveNonExistentElement();
    }
    this->ListPointer<T>::remove(value);
}
