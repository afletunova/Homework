#pragma once
#include <QStack>

/*!
 * \brief The Calculator class - class that calculate value of expression.
 */

class Calculator
{
public:
    Calculator();
    QString calculate();
    /*!
     * \brief read - reads the text into array
     * \param text
     */
    void read(char *text, const int &size);
    ~Calculator();

private:
    QStack<int> stack;
    char *input;
    int lineSize;
    int numberOfDigits;
    int countNumbers;
    int *arrayOfBits;
    const int size = 10;

    /*!
     * \brief transform - return expression in an postfix form
     */
    QString transform();
    /*!
     * \brief priority - for determine priority of operation
     * \param operation
     * \return 2 - if operation is multiplicative, 1 - if operation is additive
     */
    int priority(const char &operation);
    bool isOperation(const char &symbol);
    /*!
     * \brief calculation - calculate value depending on the operation
     * \param operation
     * \return value
     */
    double calculation(const char &operation);
};
