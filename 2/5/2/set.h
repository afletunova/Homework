#pragma once

#include "tree.h"

template <typename T>
class Set
{
public:
    Set();
    bool add(const T &element);
    bool exist(const T &element);
    bool remove(const T &element);
    int getAmount() const;
    ~Set();

private:
    Tree *tree;
};

template <typename T>
Set<T>::Set()
{
    tree = new Tree();
}

template <typename T>
bool Set<T>::add(const T &element)
{
    if (!tree->exist(element))
    {
        return tree->add(element);
    }
    return false;
}

template <typename T>
bool Set<T>::exist(const T &element)
{
    return tree->exist(element);
}

template <typename T>
bool Set<T>::remove(const T &element)
{
    return tree->remove(element);
}

template <typename T>
int Set<T>::getAmount() const
{
    return tree->getAmount();
}

template <typename T>
Set<T>::~Set()
{
    delete tree;
}
