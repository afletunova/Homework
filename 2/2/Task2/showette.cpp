#include "showette.h"
#include "twodimensionalarray.h"

int *Showette::spiral(int **numberArray, int size)
{
    int center = size / 2;
    int first = 1;
    int second = 2;
    int line = center;
    int column = center;
    int *outputArray = new int[size * size];
    int l = 0;
    outputArray[l] = numberArray[center][center];
    while (second < size)
    {
        for (int i = 0; i < first; ++i)
        {
            ++column;
            outputArray[++l] = numberArray[line][column];
        }
        for (int i = 0; i < first; ++i)
        {
            ++line;
            outputArray[++l] = numberArray[line][column];
        }
        first += 2;
        for (int i = 0; i < second; ++i)
        {
            --column;
            outputArray[++l] = numberArray[line][column];
        }
        for (int i = 0; i < second; ++i)
        {
            --line;
            outputArray[++l] = numberArray[line][column];
        }
        second += 2;
    }
    --first;
    for (int i = 0; i < first; ++i)
    {
        ++column;
        outputArray[++l] = numberArray[line][column];
    }
    return outputArray;
}
