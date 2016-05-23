#pragma once

class TreeNode
{
public:
    TreeNode();
    virtual int compute() = 0;
    virtual void printResult() = 0;
    void addLeft(TreeNode *left);
    void addRight(TreeNode *right);
    ~TreeNode();

protected:
    TreeNode *left;
    TreeNode *right;
};
