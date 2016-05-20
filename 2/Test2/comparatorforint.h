#pragma once
#include "comparator.h"

class ComparatorForInt : public Comparator<int>
{
public:
    bool compareLess(const int &first, const int &second);
    bool compareEqual(const int &first, const int &second);
};
