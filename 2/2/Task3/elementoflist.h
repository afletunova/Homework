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
