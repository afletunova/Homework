#include "twodimensionalarray.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

void createTwoDimensionalArray(int **&array, int size)
{
    array = new int*[size];
    for (int i = 0; i < size; ++i)
    {
        array[i] = new int[size];
    }
}

bool twoDimensionalArrayRandom(int **&array, int size)
{
    if (size <= 0)
    {
        return false;
    }
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            array[i][j] = 1 + rand() % size;
        }
    }
    return true;
}

bool twoDimensionalArrayUser(int **&array, int size)
{
    if (size <= 0)
    {
        return false;
    }

    cout << "Enter elements separating them with space:" << endl;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cin >> array[i][j];
        }
    }
    return true;
}

bool printTwoDimensionalArray(int **array, int size)
{
    if (size <= 0)
    {
        return false;
    }

    cout << "Array: " << endl;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << setw(4) << array[i][j];
        }
        cout << endl;
    }
    return true;
}

bool deleteArray(int **&array, int size)
{
    if (size <= 0)
    {
      return false;
    }

    for (int i = 0; i < size; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
    return true;
}
