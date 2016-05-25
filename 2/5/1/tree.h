#pragma once

#include "treenode.h"
#include <QString>

/*!
 * \brief The Tree class - class that implements ADT Tree for counting expression prepared after processing the parse tree.
 */
class Tree
{
public:
    Tree(const QString &expression);
    int compute();
    void print();
    ~Tree();

private:
    TreeNode *root;

    bool isOperation(const char &symbol);
    /*!
     * \brief changeOperation - function that leads node type to the type of the operand and change the value of a field operation
     * \param node
     * \param operation
     */
    void changeOperation(TreeNode *node, const char &operation);
};
