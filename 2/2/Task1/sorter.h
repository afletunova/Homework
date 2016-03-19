#pragma once

class Sorter
{
public:
    virtual void sort(int *arrayOfElements, int lengthOfArray) = 0;
    ~Sorter();
};
