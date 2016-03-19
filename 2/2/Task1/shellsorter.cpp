#include "shellsorter.h"
#include <algorithm>

using namespace std;

void ShellSorter::sort(int *arrayOfElements, int lengthOfArray)
{
    shellSort(arrayOfElements, lengthOfArray);
}

void ShellSorter::shellSort(int *&arrayOfElements, int lengthOfArray)
{
    int step = lengthOfArray;

    while (step > 0)
    {
        for (int i = 0; i < lengthOfArray - step; ++i)
        {
            int j = i;
            while ((j >= 0) && (arrayOfElements[j] > arrayOfElements[j + step]))
            {
                swap(arrayOfElements[j], arrayOfElements[j + step]);
                --j;
            }
        }
        step /= 2;
    }
}
