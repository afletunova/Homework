#include "showetteconsoleoutput.h"
#include "showette.h"

#include <iostream>

void ShowetteConsoleOutput::outputSpiralArray(int **array, int size)
{
    int *outputArray = Showette::spiral(array, size);
    
    for (int i = 0; i < size * size; ++i)
    {
        std::cout << outputArray[i] << ' ';
    }

    delete[] outputArray;
}
