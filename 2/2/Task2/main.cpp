#include <iostream>

#include "twodimensionalarray.h"
#include "showetteconsoleoutput.h"
#include "showettefileoutput.h"

using namespace std;

int main()
{
    char inputAnswer = '\0';
    char outputAnswer = '\0';
    int size = 0;
    cout << "This programm will allow you to see two-dimensional array, passing it along a spiral starting from center." << endl;
    cout << "Please, select an input method: <<a>> or <<m>>, where a - automatic, and m - manual. Enter (a/m):" << endl;
    cin >> inputAnswer;

    cout << "Please, enter an array size:" << endl;
    cin >> size;

    cout << "If you want to get result in console, enter <<c>> or <<f>> if you want to get result in file." << endl;
    cin >> outputAnswer;

    int **array;
    createTwoDimensionalArray(array, size);

    bool correctInputAnswer = false;

    while (!correctInputAnswer)
    {
        if (inputAnswer == 'a')
        {
            correctInputAnswer = twoDimensionalArrayRandom(array, size);
        }
        else if (inputAnswer == 'm')
        {
            correctInputAnswer = twoDimensionalArrayUser(array, size);
        }
        else if (size > 0)
        {
            cout << "Something went wrong. Probably, wrong symbol. Try again:" << endl;
            cin >> inputAnswer;
        }
        else
        {
            if (size < 0)
            {
                cout << "Something went wrong. Probably, wrong size. Try again:" << endl;
                cin >> size;
            }
        }
    }

    printTwoDimensionalArray(array, size);

    bool correctOutputAnswer = false;
    while (!correctOutputAnswer)
    {
        if (outputAnswer == 'c')
        {
            Showette *showette = new ShowetteConsoleOutput;
            showette->outputSpiralArray(array, size);
            delete showette;
            correctOutputAnswer = true;
        }
        else if (outputAnswer == 'f')
        {
            Showette *showette = new ShowetteFileOutput;
            showette->outputSpiralArray(array, size);
            delete showette;
            correctOutputAnswer = true;
        }
        else
        {
            cout << "Something went wrong. Probably, wrong answer. Try again:" << endl;
            cin >> outputAnswer;
        }
    }

    deleteArray(array, size);
    return 0;
}
