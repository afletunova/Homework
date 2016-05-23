#include "tree.h"
#include "operand.h"
#include "operator.h"

#include <cctype>
#include <QStack>

Tree::Tree(const QString &expression)
{
    QStack<TreeNode *> stack;
    bool isNumber = false;
    bool afterOpeningBracket = false;
    int currentNumber = 0;
    int sign = 1;
    int expressionLength = expression.size();

    for (int i = 0; i < expressionLength; ++i)
    {
        char currentSymbol = expression[i].toLatin1();
        if (isdigit(currentSymbol))
        {
            isNumber = true;
            afterOpeningBracket = false;
            currentNumber = currentNumber * 10 + (currentSymbol - '0');
        }
        else
        {
            if (isNumber)
            {
                Operand *operand = new Operand(sign * currentNumber);
                stack.push(operand);
                isNumber = false;
                currentNumber = 0;
                sign = 1;
            }
            if (currentSymbol == '(')
            {
                afterOpeningBracket = true;
                Operator *operatorNode = new Operator;
            }
            else if (isOperation(currentSymbol))
            {
                if (currentSymbol == '-' && afterOpeningBracket)
                {
                    sign = -1;
                    afterOpeningBracket = false;
                    continue;
                }
                changeOperation(stack.top(), currentSymbol);
            }
            else if (currentSymbol == ')')
            {
                afterOpeningBracket = false;
                TreeNode *right = stack.pop();
                TreeNode *left = stack.pop();
                TreeNode *node = stack.top();
                node->addLeft(left);
                node->addRight(right);
                stack.push(node);
            }
        }
    }
    root = stack.pop();
}

Tree::~Tree()
{
    delete root;
}


bool Tree::isOperation(const char &symbol)
{
    return ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/'));
}

void Tree::changeOperation(TreeNode *node, const char &operation)
{
    dynamic_cast<Operator *>(node)->changeOperation(operation);
}
