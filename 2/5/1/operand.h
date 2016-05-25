#pragma once

#include "treenode.h"

/*!
 * \brief The Operand class - class that implements operand to calculate the value of the result of the parse tree.
 */

class Operand : public TreeNode
{
public:
    Operand(const int &value);
    /*!
     * \brief compute - function that calculate value in this node
     * \return
     */
    int compute();
    void print();

private:
    int value;
};
