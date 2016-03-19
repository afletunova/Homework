#include "quicksorter.h"
#include <algorithm>

using namespace std;

void QuickSorter::sort(int *arrayOfElements, int lengthOfArray)
{
    quickSort(arrayOfElements, 0, lengthOfArray - 1);
}

void QuickSorter::quickSort(int *&arrayOfElements, int first, int second)
{
    int left = first;
    int right = second;
    int supportElement = arrayOfElements[(left + right) / 2];

    while (left < right)
    {
        while (supportElement > arrayOfElements[left])
        {
            ++left;
        }
        while (supportElement < arrayOfElements[right])
        {
            --right;
        }
        if (left <= right)
        {
            swap(arrayOfElements[left], arrayOfElements[right]);
            ++left; --right;
        }
    }
    if (left < second)
    {
        quickSort(arrayOfElements, left, second);
    }
    if (right > first)
    {
        quickSort(arrayOfElements, first, right);
    }
}
