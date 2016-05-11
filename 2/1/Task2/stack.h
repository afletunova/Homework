#pragma once

template <typename T>
/*!
 * \brief The Stack class - parent class with basic methods. Template implementation.
 */
class Stack
{
public:
    virtual bool push(T value) = 0;
    virtual T pop() = 0;
    virtual int getSize() = 0;
};
