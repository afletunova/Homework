#pragma once

#include "listpointer.h"
/*!
 * \brief The ListsComparator class - compares two objects by they sizes.
 */

template <class C>
class ListsComparator
{
public:
    bool less(const C &firstList, const C &secondList) const;
    bool equal(const C &firstList, const C &secondList) const;
};

template <class C>
bool ListsComparator<C>::less(const C &firstList, const C &secondList) const
{
    return (firstList->getSize() < secondList->getSize());
}

template <class C>
bool ListsComparator<C>::equal(const C &firstList, const C &secondList) const
{
    return (firstList->getSize() == secondList->getSize());
}
