#include "treenode.h"

TreeNode::TreeNode()
    :left(nullptr), right(nullptr)
{}

void TreeNode::addLeft(TreeNode *left)
{
    this->left = left;
}

void TreeNode::addRight(TreeNode *right)
{
    this->right = right;
}

TreeNode::~TreeNode()
{
    delete left;
    delete right;
}
