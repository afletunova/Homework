#pragma once

#include <iostream>

using namespace std;

template <typename T>

/*!
 * \brief The Tree class - class that implements ADT "AVL-Tree"
 */
class Tree
{
public:
    Tree();
    bool add(const T &value);
    bool exist(const T &value);
    bool remove(const T &value);
    int getAmount() const;
    void printTree();
    ~Tree();

private:
    class TreeNode
    {
    public:
        TreeNode()
            :height(1), left(nullptr), right(nullptr)
        {}
        TreeNode(const T &key)
            :key(key), height(1), left(nullptr), right(nullptr)
        {}
        TreeNode *&getLeft()
        {
            return left;
        }

        TreeNode *&getRight()
        {
            return right;
        }

        T getKey()
        {
            return key;
        }

        int getHeight()
        {
            return height;
        }

        void changeHeight(const int &newHeight)
        {
            height = newHeight;
        }

    private:
        T key;
        unsigned int height;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *root;
    int amount;

    T key(TreeNode *&node) const;
    TreeNode *left();
    TreeNode *right();

    int getHeight(TreeNode *&node) const;
    int getBalanceFactor(TreeNode *&node) const;
    bool find(TreeNode *&node, const T &value) const;
    void updateHeight(TreeNode *&node);
    /*!
     * \brief rightRotate - function to right rotate around node
     * \param node
     * \return node, that gets in the "root" place in this part of tree
     */
    TreeNode *rightRotate(TreeNode *&node);
    /*!
     * \brief leftRotate - function to left rotate around node
     * \param node
     * \return node, that gets in the "root" place in this part of tree
     */
    TreeNode *leftRotate(TreeNode *&node);
    /*!
     * \brief balance - function to get balnced node
     * \param node
     * \return balanced node
     */
    TreeNode *balance(TreeNode *&node);
    /*!
     * \brief add - function that adds element in tree and avoid imbalance
     * \param node
     * \param value
     * \return balanced node with new element among child or current node if element is repeated
     */
    TreeNode *add(TreeNode *&node, const T &value);
    /*!
     * \brief findLeftmost - funtion to find most left element in current part of tree
     * \param node
     * \return most left element
     */
    TreeNode *findLeftmost(TreeNode *&node);
    /*!
     * \brief removeLeftmost - function that removes most left element in current part of tree
     * \param node
     * \return balanced node
     */
    TreeNode *removeLeftmost(TreeNode *&node);
    /*!
     * \brief remove - function that removes element of tree and avoid imbalance
     * \param node
     * \param value
     * \return balanced node without sought-for element if this was found
     */
    TreeNode *remove(TreeNode *&node, const T &value);
    void printTree(TreeNode *&node);
};

template <typename T>
Tree<T>::Tree()
    :amount(0), root(nullptr)
{}

template <typename T>
bool Tree<T>::add(const T &value)
{
    int currentAmount = amount;
    root = add(root, value);
    if (currentAmount + 1 == amount)
    {
        return true;
    }
    return false;
}

template <typename T>
bool Tree<T>::exist(const T &value)
{
    return find(root, value);
}

template <typename T>
bool Tree<T>::remove(const T &value)
{
    int currentAmount = amount;
    root = remove(root, value);
    if (currentAmount - 1 == amount)
    {
        return true;
    }
    return false;
}

template <typename T>
int Tree<T>::getAmount() const
{
    return amount;
}

template <typename T>
Tree<T>::~Tree()
{
    while (root)
    {
        remove(key(root));
    }
}

template <typename T>
T Tree<T>::key(Tree::TreeNode *&node) const
{
    return node->getKey();
}

template <typename T>
int Tree<T>::getHeight(Tree::TreeNode *&node) const
{
    if (!node)
    {
        return 0;
    }
    return node->getHeight();
}

template <typename T>
int Tree<T>::getBalanceFactor(Tree::TreeNode *&node) const
{
    return getHeight(node->getRight()) - getHeight(node->getLeft());
}

template <typename T>
bool Tree<T>::find(Tree::TreeNode *&node, const T &value) const
{
    if (!node)
    {
        return false;
    }
    if (node->getKey() > value)
    {
        return find(node->getLeft(), value);
    }
    else if (node->getKey() < value)
    {
        return find(node->getRight(), value);
    }
    return true;
}

template <typename T>
void Tree<T>::updateHeight(Tree::TreeNode *&node)
{
    unsigned int leftHeight = getHeight(node->getLeft());
    unsigned int rightHeight = getHeight(node->getRight());
    if (leftHeight > rightHeight)
    {
        node->changeHeight(getHeight(node->getLeft()) + 1);
    }
    else
    {
        node->changeHeight(getHeight(node->getRight()) + 1);
    }
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::rightRotate(Tree::TreeNode *&node)
{
    TreeNode *auxiliary = node->getLeft();
    node->getLeft() = auxiliary->getRight();
    auxiliary->getRight() = node;
    updateHeight(node);
    updateHeight(auxiliary);
    return auxiliary;
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::leftRotate(TreeNode *&node)
{
    TreeNode *auxiliary = node->getRight();
    node->getRight() = auxiliary->getLeft();
    auxiliary->getLeft() = node;
    updateHeight(node);
    updateHeight(auxiliary);
    return auxiliary;
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::balance(Tree::TreeNode *&node)
{
    updateHeight(node);
    if (getBalanceFactor(node) == 2)
    {
        if (getBalanceFactor(node->getRight()) < 0)
        {
            node->getRight() = rightRotate(node->getRight());
        }
        return leftRotate(node);
    }
    if (getBalanceFactor(node) == -2)
    {
        if (getBalanceFactor(node->getLeft()) > 0)
        {
            node->getLeft() = leftRotate(node->getLeft());
        }
        return rightRotate(node);
    }
    return node;
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::add(Tree::TreeNode *&node, const T &value)
{
    if (!node)
    {
        ++amount;
        node = new TreeNode(value);
        return node;
    }
    if (value > node->getKey())
    {
        node->getRight() = add(node->getRight(), value);
    }
    else if (value < node->getKey())
    {
        node->getLeft() = add(node->getLeft(), value);
    }
    return balance(node);
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::findLeftmost(Tree::TreeNode *&node)
{
    if (node->getLeft())
    {
        return findLeftmost(node->getLeft());
    }
    return node;
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::removeLeftmost(TreeNode *&node)
{
    if (!node->getLeft())
    {
        return node->getRight();
    }
    node->getLeft() = removeLeftmost(node->getLeft());
    return balance(node);
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::remove(Tree::TreeNode *&node, const T &value)
{
    if (!node)
    {
        return nullptr;
    }
    if (value > node->getKey())
    {
        node->getRight() = remove(node->getRight(), value);
    }
    else if (node->getKey() > value)
    {
        node->getLeft() = remove(node->getLeft(), value);
    }
    else
    {
        TreeNode *auxiliaryLeft = node->getLeft();
        TreeNode *auxiliaryRight = node->getRight();
        delete node;
        --amount;

        if (!auxiliaryRight)
        {
            return auxiliaryLeft;
        }

        TreeNode *Leftmost = findLeftmost(auxiliaryRight);
        Leftmost->getRight() = removeLeftmost(auxiliaryRight);
        Leftmost->getLeft() = auxiliaryLeft;

        return balance(Leftmost);
    }
    return balance(node);
}

template <typename T>
void Tree<T>::printTree()
{
    printTree(root);
}

template <typename T>
void Tree<T>::printTree(Tree::TreeNode *&node)
{
    if (!node)
    {
        cout << "nullptr";
    }
    else
    {
        cout << '(' << node->getKey() << ',';
        printTree(node->getLeft());
        cout << ',';
        printTree(node->getRight());
        cout << ')';
    }
}
