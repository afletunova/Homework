#include "listscomparator.h"

bool ListsComparator::operator <(const ListsComparator &list) const
{
    return this->getSize() < list.getSize();
}

bool ListsComparator::operator >(const ListsComparator &list) const
{
    return (this->getSize() > list.getSize());
}

bool ListsComparator::operator !=(const ListsComparator &list) const
{
    return (this->getSize() != list.getSize());
}

bool ListsComparator::operator ==(const ListsComparator &list) const
{
    return (this->getSize() == list.getSize());
}
