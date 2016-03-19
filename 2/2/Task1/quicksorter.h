#pragma once
#include "sorter.h"

class QuickSorter : public Sorter
{
public:
    QuickSorter(){}
    void sort(int *arrayOfElements, int lengthOfArray);
private:
    void quickSort(int *&arrayOfElements, int first, int second);
};
