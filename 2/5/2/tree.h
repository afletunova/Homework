#pragma once

template <typename T>
class Tree
{
public:
    Tree();
    bool add(const T &value);
    bool exist(const T &value);
    bool remove(const T &value);
    int getAmount() const;
    ~Tree();

    class TreeNode
    {
    public:
        TreeNode();
        TreeNode(const T &key);
        ~TreeNode();
    private:
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
    void updateHeight(TreeNode *&node);
    TreeNode *rightRotate(TreeNode *node);
    TreeNode *leftRotate(TreeNode *node);
    TreeNode *balance(TreeNode *node);
    TreeNode *add(TreeNode *node, const T &value);
    TreeNode *findLeftmost(TreeNode *node);
    TreeNode *removeLeftmost(TreeNode *node);
    TreeNode *remove(TreeNode *node, const T &value);
};


template <typename T>
Tree<T>::Tree()
    :amount(0), root(nullptr)
{}

template <typename T>
bool Tree<T>::add(const T &value)
{
    if (add(root, value))
    {
        ++amount;
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
    if (remove(root, value))
    {
        --amount;
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
Tree<T>::TreeNode::~TreeNode()
{
    delete left;
    delete right;
}

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
Tree<T>::TreeNode *Tree::rightRotate(Tree::TreeNode *node)
{
    TreeNode *auxiliary = node->left;
    node->left = auxiliary->right;
    auxiliary->right = node;
    updateHeight(node);
    updateHeight(auxiliary);
    return auxiliary;
}

template <typename T>
Tree<T>::TreeNode *Tree::leftRotate(Tree::TreeNode *node)
{
    TreeNode *auxiliary = node->right;
    node->right = auxiliary->left;
    auxiliary->left = node;
    updateHeight(node);
    updateHeight(auxiliary);
    return auxiliary;
}

template <typename T>
Tree<T>::TreeNode *Tree::balance(Tree::TreeNode *node)
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
Tree<T>::TreeNode *Tree::add(Tree::TreeNode *node, const T &value)
{
    if (!node)
    {
        return (new TreeNode(value));
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
Tree<T>::TreeNode *Tree::findLeftmost(Tree::TreeNode *node)
{
    if (node->left)
    {
        return findLeftmost(node->left);
    }
    return node;
}

template <typename T>
Tree<T>::TreeNode *Tree::removeLeftmost(Tree::TreeNode *node)
{
    if (!node->left)
    {
        return node->right;
    }
    node->left = removeLeftmost(node->left);
    return balance(node);
}

template <typename T>
Tree<T>::TreeNode *Tree::remove(Tree::TreeNode *node, const T &value)
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
        node->right = remove(node->right, value);
    }
    else
    {
        TreeNode *auxiliaryLeft = node->left;
        TreeNode *auxiliaryRight = node->right;
        delete node;

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

Tree<T>::~Tree()
{

}
