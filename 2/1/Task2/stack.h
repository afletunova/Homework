#pragma once

template <typename T>
class Stack
{
public:
    virtual bool push(T value) = 0;
    virtual T pop() = 0;
    virtual int getSize() = 0;
};
