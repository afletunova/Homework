#pragma once

template <typename T>
class Comparator
{
public:
    Comparator(){}
    virtual bool compareLess(const T &first, const T &second) = 0;
    virtual bool compareEqual(const T &first, const T &second) = 0;
};
