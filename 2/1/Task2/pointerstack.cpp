#include "pointerstack.h"

PointerStack::PointerStack()
    :size(0)
{
    top = new ElementOfStack();
}

PointerStack::ElementOfStack::ElementOfStack()
    :next(nullptr)
{}

PointerStack::ElementOfStack(T value)
{
    key = value;
}

bool PointerStack::push(double value)
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

double PointerStack::pop()
{
    if(size > 0)
    {
        double outputValue = top->key;
        ElementOfStack *newTop = top->next;
        delete top;
        top = newTop;
        return outputValue;
    }
    else
    {
        return;
    }
}
