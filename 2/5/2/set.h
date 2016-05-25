#pragma once

#include "tree.h"

template <typename T>

/*!
 * \brief The Set class - class that implements ADT "Set" based on AVL-Tree
 */
class Set
{
public:
    Set();
    bool add(const T &element);
    bool exist(const T &element);
    bool remove(const T &element);
    int getAmount() const;
    void printSet();
    ~Set();

private:
    Tree<T> *tree;
};

template <typename T>
Set<T>::Set()
{
    tree = new Tree<T>();
}

template <typename T>
bool Set<T>::add(const T &element)
{
    return tree->add(element);
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
void Set<T>::printSet()
{
    tree->printTree();
}

template <typename T>
Set<T>::~Set()
{
    delete tree;
}
