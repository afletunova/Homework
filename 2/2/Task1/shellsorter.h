#pragma once
#include "sorter.h"

class ShellSorter : public Sorter
{
public:
    ShellSorter(){}
    void sort(int *arrayOfElements, int lengthOfArray);
private:
    void shellSort(int *&arrayOfElements, int lengthOfArray);
};
