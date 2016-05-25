#pragma once

#include "treenode.h"

/*!
 * \brief The Operator class - class that implements operand to calculate the value of the result of the parse tree.
 */

class Operator : public TreeNode
{
public:
    Operator();
    /*!
     * \brief compute - function that calculate value in this node
     * \return
     */
    int compute();
    void print();
    void changeOperation(const &operation);

private:
    char operation;
};
