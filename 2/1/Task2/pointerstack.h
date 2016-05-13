#pragma once
#include <iostream>

template <typename T>
/*!
 * \brief The PointerStack class - class that inherits from the Stack class. Represent stack on pointers with template implementation.
 */
class PointerStack : public Stack <T>
{
public:
    PointerStack();
    bool push(const T &value);
    T pop();
    int getSize()
    {
        return size;
    }
    /*!
     * \brief The ElementOfStack class - convenience class, which is a class field.
     */
    class ElementOfStack
    {
    public:
        ElementOfStack();
        /*!
         * \brief ElementOfStack - constructor to the case where value is known.
         * \param value
         */
        ElementOfStack(const T &value);
        T returnKey();

        T key;
        ElementOfStack *next;
        ~ElementOfStack();
    };
    ~PointerStack();
    ElementOfStack *top;
private:
    int size;
};

template <typename T>
PointerStack<T>::ElementOfStack::ElementOfStack()
    : next(nullptr)
{}

template <typename T>
PointerStack<T>::ElementOfStack::ElementOfStack(const T &value)
    : next(nullptr)
{
    key = value;
}

template <typename T>
T PointerStack<T>::ElementOfStack::returnKey()
{
    return key;
}

template <typename T>
PointerStack<T>::ElementOfStack::~ElementOfStack()
{
    delete next;
}

template <typename T>
PointerStack<T>::PointerStack()
    :size(0)
{
    top = new ElementOfStack();
}

template <typename T>
bool PointerStack<T>::push(const T &value)
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
