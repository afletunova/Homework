#pragma once
#include <list>
#include "comparator.h"

template <typename T>
class BubbleSort
{
public:
    BubbleSort(std::list<T> &list, Comparator<T> *&comaparator);
    std::list<T> Sort();

private:
    Comparator<T> &comparator;
    std::list<T> list;
};

template <typename T>
BubbleSort<T>::BubbleSort(std::list<T> &list, Comparator<T> *&comaparator)
    :list(list), comparator(comparator)
{}

template <typename T>
std::list<T> BubbleSort<T>::Sort()
{
    for (auto i = list.begin(); i != list.end(); ++i)
    {
        bool swapped = false;
        for (auto j = list.begin(); j != i; ++j)
        {
            if (comparator.compareLess(*i, *j))
            {
                T swaper = *i;
                *i = *j;
                *j = swaper;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    return list;
}
