#pragma once

#include "treenode.h"

class Operator : public TreeNode
{
public:
    Operator();
    int compute();
    void printResult();
    void changeOperation(const &operation);

private:
    char operation;
};
