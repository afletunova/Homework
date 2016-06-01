#pragma once

#include "tree.h"

class NonexistenElement
{
public:
    NonexistenElement()
    {
        cout << "Element does not exist!" << endl;
    }
};

template <typename T>
/*!
 * \brief The Bag class - class that implements ADT "Multi Set" based on AVL-Tree
 * It is a class set with the possibility of adding identical elements.
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
    if (exist(element))
    {
        return tree->remove(element);
    }
    throw NonexistenElement();
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
