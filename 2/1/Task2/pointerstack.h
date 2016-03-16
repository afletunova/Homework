#pragma once
#include <iostream>

template <typename T>
class PointerStack : public Stack <T>
{
public:
    PointerStack();
    bool push(T value);
    T pop();
    int getSize()
    {
        return size;
    }
    class ElementOfStack
    {
    public:
        ElementOfStack();
        ElementOfStack(T value)
        {
            key = value;
        }

        T returnKey()
        {
            return key;
        }
        T key;
        ElementOfStack *next;
    };
    ~PointerStack();
    ElementOfStack *top;
private:
    int size;
};

template <typename T>
PointerStack<T>::PointerStack()
    :size(0)
{
    top = new ElementOfStack();
}

template <typename T>
PointerStack<T>::ElementOfStack::ElementOfStack()
    :next(nullptr)
{}

template <typename T>
bool PointerStack<T>::push(T value)
{
    ElementOfStack *element = top;
    if(element)
    {
        ElementOfStack *auxiliary = new ElementOfStack(value);
        auxiliary->next = element;
        top = auxiliary;
    }
    else
    {
        element->key = value;
    }
    ++size;
    return true;
}

template <typename T>
T PointerStack<T>::pop()
{
    if(size > 0)
    {
        T outputValue = top->key;
        ElementOfStack *newTop = top->next;
        delete top;
        top = newTop;
        --size;
        return outputValue;
    }
}
