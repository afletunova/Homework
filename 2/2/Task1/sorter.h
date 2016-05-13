#pragma once

/*!
 * \brief The Sorter class - parent class that implements sorting.
 */
class Sorter
{
public:
    /*!
     * \brief sort - function of sorting
     * \param arrayOfElements
     * \param lengthOfArray
     */
    virtual void sort(int *arrayOfElements, int lengthOfArray) = 0;
};
