#pragma once
#include "sorter.h"

class HeapSorter : public Sorter
{
public:
    HeapSorter(){}
    void sort(int *arrayOfElements, int lengthOfArray);
private:
    void heapify(int *&arrayOfElements, int position, int length);
    void heapSort(int *&arrayOfElements, int lengthOfArray);
};

