#include "heapsorter.h"
#include <algorithm>

using namespace std;

void HeapSorter::sort(int *arrayOfElements, int lengthOfArray)
{
    heapSort(arrayOfElements, lengthOfArray);
}

void HeapSorter::heapify(int *&arrayOfElements, int position, int length)
{
    while (2 * position + 1 < length)
    {
        int i = 2 * position + 1;
        if ((2 * position + 2 < length) && arrayOfElements[2 * position + 2] >= arrayOfElements[i])
        {
            i = 2 * position + 2;
        }
        if (arrayOfElements[position] < arrayOfElements[i])
        {
            swap(arrayOfElements[position], arrayOfElements[i]);
            position = i;
        }
        else
        {
            break;
        }
    }
}

void HeapSorter::heapSort(int *&arrayOfElements, int lengthOfArray)
{
    for (int i = lengthOfArray - 1; i >= 0; --i)
    {
        heapify(arrayOfElements, i, lengthOfArray);
    }
    while (lengthOfArray > 0)
    {
        swap(arrayOfElements[0], arrayOfElements[lengthOfArray - 1]);
        --lengthOfArray;
        heapify(arrayOfElements, 0, lengthOfArray);
    }
}

