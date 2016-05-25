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

    class TreeNode
    {
    public:
        TreeNode();
        TreeNode(const T &key);
        T key;
        unsigned int height;
        TreeNode *left;
        TreeNode *right;
    };

private:
    TreeNode *root;
    int amount;

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
        remove(root->key);
    }
}

template <typename T>
Tree<T>::TreeNode::TreeNode(const T &key)
    :key(key), height(1), left(nullptr), right(nullptr)
{}

template <typename T>
Tree<T>::TreeNode::TreeNode()
    :height(1), left(nullptr), right(nullptr)
{}

template <typename T>
int Tree<T>::getHeight(Tree::TreeNode *&node) const
{
    if (!node)
    {
        return 0;
    }
    return node->height;
}

template <typename T>
int Tree<T>::getBalanceFactor(Tree::TreeNode *&node) const
{
    return getHeight(node->right) - getHeight(node->left);
}

template <typename T>
bool Tree<T>::find(Tree::TreeNode *&node, const T &value) const
{
    if (!node)
    {
        return false;
    }
    if (node->key > value)
    {
        return find(node->left, value);
    }
    else if (node->key < value)
    {
        return find(node->right, value);
    }
    return true;
}

template <typename T>
void Tree<T>::updateHeight(Tree::TreeNode *&node)
{
    unsigned int leftHeight = getHeight(node->left);
    unsigned int rightHeight = getHeight(node->right);
    if (leftHeight > rightHeight)
    {
        node->height = getHeight(node->left) + 1;
    }
    else
    {
        node->height = getHeight(node->right) + 1;
    }
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::rightRotate(Tree::TreeNode *&node)
{
    TreeNode *auxiliary = node->left;
    node->left = auxiliary->right;
    auxiliary->right = node;
    updateHeight(node);
    updateHeight(auxiliary);
    return auxiliary;
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::leftRotate(TreeNode *&node)
{
    TreeNode *auxiliary = node->right;
    node->right = auxiliary->left;
    auxiliary->left = node;
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
        if (getBalanceFactor(node->right) < 0)
        {
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }
    if (getBalanceFactor(node) == -2)
    {
        if (getBalanceFactor(node->left) > 0)
        {
            node->left = leftRotate(node->left);
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
    if (value > node->key)
    {
        node->right = add(node->right, value);
    }
    else
    {
        node->left = add(node->left, value);
    }
    return balance(node);
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::findLeftmost(Tree::TreeNode *&node)
{
    if (node->left)
    {
        return findLeftmost(node->left);
    }
    return node;
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::removeLeftmost(TreeNode *&node)
{
    if (!node->left)
    {
        return node->right;
    }
    node->left = removeLeftmost(node->left);
    return balance(node);
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::remove(Tree::TreeNode *&node, const T &value)
{
    if (!node)
    {
        return nullptr;
    }
    if (value > node->key)
    {
        node->right = remove(node->right, value);
    }
    else if (node->key > value)
    {
        node->left = remove(node->left, value);
    }
    else
    {
        TreeNode *auxiliaryLeft = node->left;
        TreeNode *auxiliaryRight = node->right;
        delete node;
        --amount;

        if (!auxiliaryRight)
        {
            return auxiliaryLeft;
        }

        TreeNode *Leftmost = findLeftmost(auxiliaryRight);
        Leftmost->right = removeLeftmost(auxiliaryRight);
        Leftmost->left = auxiliaryLeft;

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
        cout << '(' << node->key << ',';
        printTree(node->left);
        cout << ',';
        printTree(node->right);
        cout << ')';
    }
}
