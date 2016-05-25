#pragma once

#include "tree.h"

template <typename T>
/*!
 * \brief The Bag class - class that implements ADT "Multi Set" based on AVL-Tree
 */
class Bag
{
public:
    Bag();
    Bag(const Bag &object);
    bool add(const T &element) const;
    bool exist(const T &element) const;
    bool remove(const T &element) const;
    int getAmount() const;
    void printBag();
    ~Bag();

private:
    Tree<T> *tree;
};

template <typename T>
Bag<T>::Bag()
{
    tree = new Tree<T>;
}

template <typename T>
Bag<T>::Bag(const Bag &object)
    :tree(object.tree)
{}

template <typename T>
bool Bag<T>::add(const T &element) const
{
    return tree->add(element);
}

template <typename T>
bool Bag<T>::exist(const T &element) const
{
    return tree->exist(element);
}

template <typename T>
bool Bag<T>::remove(const T &element) const
{
    return tree->remove(element);
}

template <typename T>
int Bag<T>::getAmount() const
{
    return tree->getAmount();
}

template <typename T>
void Bag<T>::printBag()
{
    tree->printTree();
}

template <typename T>
Bag<T>::~Bag()
{
    delete tree;
}
