#pragma once

#include "tree.h"
#include <iostream>

using namespace std;

class AlreadyExistingElement
{
public:
    AlreadyExistingElement()
    {
        cout << "Element already exist!" << endl;
    }
};

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
 * \brief The Set class - class that implements ADT "Set" based on AVL-Tree
 * The class is a set with the ability to add items, avoiding duplication.
 */
class Set
{
public:
    Set();
    /*!
     * \brief add - function to add element
     * \param element
     * \return true - if element was added and false - if element already exist in the set.
     */
    bool add(const T &element);
    /*!
     * \brief exist - function to check the existence of an element in the set.
     * \param element
     * \return true - if element exists, false - if not.
     */
    bool exist(const T &element);
    /*!
     * \brief remove - function to remove element from the set.
     * \param element
     * \return true - if element was removed, false - if there was no such element.
     */
    bool remove(const T &element);
    /*!
     * \brief getAmount
     * \return number of elements in the set.
     */
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
    if (!exist(element))
    {
        return tree->add(element);
    }
    throw AlreadyExistingElement();
}

template <typename T>
bool Set<T>::exist(const T &element)
{
    return tree->exist(element);
}

template <typename T>
bool Set<T>::remove(const T &element)
{
    if (exist(element))
    {
        return tree->remove(element);
    }
    throw NonexistenElement();
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
