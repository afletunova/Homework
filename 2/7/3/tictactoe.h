#pragma once

#include <QObject>
#include <QPushButton>

/*!
 * \brief The TicTacToe class - class that implements game "Tic Tac Toe". It works with an external user interface class.
 */

class TicTacToe : public QObject
{
    Q_OBJECT

public:
    TicTacToe(int size);
    ~TicTacToe();

public slots:
    void newGame();
    QString changed(QObject *button);

signals:
    void gameOver(const QString &) const;

private:
    int size;
    int buttons;
    int clickedButtons;
    int currentLine;
    int currentColumn;
    int maxLength;

    /*!
     * \brief idarray - array to find the position of the сlicked button.
     */
    int **idArray;
    char **field;
    char winnerSymbol;

    void setSymbol(QObject *&button);
    void cleanUpField();
    /*!
     * \brief win - function to check whether there is a winner
     * \return true - if somebody is winner, false - no winner
     */
    bool win();
    ///functions to check winning combinations.
    bool fullDiagonal();
    bool fullSecondDiagonal();
    bool fullLine();
    bool fullColumn();
    char getCurrentSymbol() const;
    void changeMaxLength(int number);
    void getParameters(int &line, int &column, int id);
};

