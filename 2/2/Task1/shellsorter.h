#pragma once
#include "sorter.h"

/*!
 * \brief The ShellSorter class - class that inherits from the class Sort. Shell sorting implements.
 */

class ShellSorter : public Sorter
{
public:
    ShellSorter(){}
    void sort(int *arrayOfElements, int lengthOfArray);
private:
    void shellSort(int *&arrayOfElements, int lengthOfArray);
};
