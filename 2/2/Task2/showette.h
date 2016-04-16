#pragma once

/*!
 *@class Showette
 */
/*!
 * \brief The showette class It contains a function that displays the array in a spiral, starting from the center.
 */
class Showette
{
public:
    Showette(){}
    /*!
     * \brief outputSpiralArray - output an array in spiral form
     * \param array - input array
     * \param size - size of an input array
     */
    virtual void outputSpiralArray(int **array, int size) = 0;
    /*!
     * \brief spiral - return an array in spiral form
     * \param array - input array
     * \param size - size of an input array
     * \return one-dimensional array
     */
    int *spiral(int **array, int size);
    virtual ~Showette(){}
};
