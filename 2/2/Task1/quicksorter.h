#pragma once
#include "sorter.h"

/*!
 * \brief The QuickSorter class - class that inherits from the class Sort, quick sorting implements.
 */
class QuickSorter : public Sorter
{
public:
    QuickSorter(){}
    void sort(int *arrayOfElements, int lengthOfArray);
private:
    void quickSort(int *&arrayOfElements, int first, int second);
};
