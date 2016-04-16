#pragma once
#include "showette.h"

/*!
 * \brief The ShowetteConsoleOutput class - output array to console
 */
class ShowetteConsoleOutput : public Showette
{
public:
    ShowetteConsoleOutput(){}
    /*!
     * \brief outputSpiralArray - output array to console
     * \param array - an input array
     * \param size - size of an input array
     */
    void outputSpiralArray(int **array, int size);
    ~ShowetteConsoleOutput(){}
};
