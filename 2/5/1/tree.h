#pragma once

#include "treenode.h"
#include <QString>

class Tree : public TreeNode
{
public:
    Tree(const QString &expression);
    int compute();
    void printResult();
    ~Tree();

private:
    TreeNode *root;

    bool isOperation(const char &symbol);
    void changeOperation(TreeNode *node, const char &operation);
};
