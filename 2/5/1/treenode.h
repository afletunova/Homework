#pragma once

/*!
 * \brief The TreeNode class - base class for various types of the tree node
 */
class TreeNode
{
public:
    TreeNode();
    virtual int compute() = 0;
    virtual void print() = 0;
    void addLeft(TreeNode *left);
    void addRight(TreeNode *right);

protected:
    TreeNode *left;
    TreeNode *right;
};
