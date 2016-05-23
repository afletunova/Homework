#pragma once

#include "treenode.h"

class Operand : public TreeNode
{
public:
    Operand(const int &value);
    int compute();
    void printResult();

private:
    int value;
};
