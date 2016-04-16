#include "showettefileoutput.h"
#include "showette.h"

#include <fstream>
#include <iostream>

using namespace std;

void ShowetteFileOutput::outputSpiralArray(int **array, int size)
{
    int *outputArray = spiral(array, size);
    ofstream file("output.txt");

    if (file)
    {
        for (int i = 0; i < size * size; ++i)
        {
            file << outputArray[i] << ' ';
        }
    }
    else
    {
        cout << "Can't open file." << endl;
    }

    file.close();

    delete[] outputArray;
}
