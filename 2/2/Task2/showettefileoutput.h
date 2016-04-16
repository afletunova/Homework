#pragma once
#include "showette.h"

/*!
 * \brief The ShowetteConsoleOutput class - output array to file
 */
class ShowetteFileOutput : public Showette
{
public:
    ShowetteFileOutput(){}
    /*!
     * \brief outputSpiralArray - output array to file
     * \param array - an input array
     * \param size - size of an input array
     */
    void outputSpiralArray(int **array, int size);
    ~ShowetteFileOutput(){}
};
