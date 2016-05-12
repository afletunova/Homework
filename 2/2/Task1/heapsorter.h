#pragma once
#include "sorter.h"

/*!
 * \brief The HeapSorter class - class that inherits from the class Sort. Heap sorting implements.
 */
class HeapSorter : public Sorter
{
public:
    HeapSorter(){}
    void sort(int *arrayOfElements, int lengthOfArray);
private:
    /*!
     * \brief heapify - function, building a sorting tree on the array.
     * \param arrayOfElements
     * \param position - current position in the array.
     * \param length
     */
    void heapify(int *&arrayOfElements, int position, int length);
    void heapSort(int *&arrayOfElements, int lengthOfArray);
};

