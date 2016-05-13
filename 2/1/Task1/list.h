#pragma once

/*!
 * \brief The List class - parent class with basic methods
 */
class List
{
public:
    virtual bool add(int value) = 0;
    virtual bool remove(int value) = 0;
    virtual int getSize() = 0;
    virtual ~List(){}
};
