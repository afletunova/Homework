#pragma once

/*!
 * \brief The ListsComparator class - compares two objects by they sizes.
 */
class ListsComparator
{
public:
    ListsComparator(){}
    bool operator <(const ListsComparator &list) const;
    bool operator >(const ListsComparator &list) const;
    bool operator !=(const ListsComparator &list) const;
    bool operator ==(const ListsComparator &list) const;
    virtual int getSize() const = 0;
    virtual ~ListsComparator(){}
};
