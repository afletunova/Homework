#include "tictactoe.h"

TicTacToe::TicTacToe(int size)
    :size(size), buttons(size * size), clickedButtons(0), currentLine(0), currentColumn(0), maxLength(0), winnerSymbol('\0')
{
    field = new char*[size];
    for (int i = 0; i < size; ++i)
    {
        field[i] = new char[size];
    }

    idarray = new int*[size];
    for (int i = 0; i < size; ++i)
    {
        idarray[i] = new int[size];
    }

    int k = -1;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            idarray[i][j] = ++k;
        }
    }

    cleanUpField();
}

TicTacToe::~TicTacToe()
{
    for (int i = 0; i < size; ++i)
    {
        delete[] field[i];
    }
    delete[] field;

    for (int i = 0; i < size; ++i)
    {
        delete[] idarray[i];
    }
    delete[] idarray;
}

void TicTacToe::newGame()
{
    clickedButtons = 0;
    cleanUpField();
}

void TicTacToe::changed(QPushButton *&button)
{
    setSymbol(button);
    int line = 0; int column = 0;
    getParameters(line, column, button->objectName().toInt());
    currentLine = line;
    currentColumn = column;
    field[currentLine][currentColumn] = getCurrentSymbol();

    if(win())
    {
        QString result;
        if (getCurrentSymbol() == 'X')
        {
            result = QString("First player win!");
        }
        else
        {
            result = QString("Second player win!");
        }
        emit gameOver(result);
    }
}

void TicTacToe::setSymbol(QPushButton *&button)
{
    button->setText(QString(getCurrentSymbol()));
    button->setEnabled(false);
}

void TicTacToe::cleanUpField()
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            field[i][j] = '\0';
        }
    }
}

bool TicTacToe::win()
{
    return (fullColumn() || fullDiagonal() || fullLine() || fullSecondDiagonal());
}

bool TicTacToe::fullDiagonal()
{
    int line = currentLine - 1;
    int column = currentColumn - 1;

    int number = 1;

    while ((field[line][column] == getCurrentSymbol()) && (line >= 0) && (column >= 0))
    {
        --line; --column;
        ++number;
    }

    line = currentLine + 1;
    column = currentColumn + 1;

    while ((field[line][column] == getCurrentSymbol()) && (line < size) && (column < size))
    {
        ++line; ++column;
        ++number;
    }

    changeMaxLength(number);
    return (number == size);
}

bool TicTacToe::fullSecondDiagonal()
{
    int line = currentLine + 1;
    int column = currentColumn - 1;

    int number = 1;

    while ((field[line][column] == getCurrentSymbol()) && (line < size) && (column >= 0))
    {
        ++line; --column;
        ++number;
    }

    line = currentLine - 1;
    column = currentColumn + 1;

    while ((field[line][column] == getCurrentSymbol()) && (line >= 0) && (column < size))
    {
        --line; ++column;
        ++number;
    }

    changeMaxLength(number);
    return (number == size);
}

bool TicTacToe::fullLine()
{
    int line = currentLine - 1;

    int number = 1;

    while ((field[line][currentColumn] == getCurrentSymbol()) && (line >= 0))
    {
        --line;
        ++number;
    }

    line = currentLine + 1;

    while ((field[line][currentColumn] == getCurrentSymbol()) && (line < size))
    {
        ++line;
        ++number;
    }

    changeMaxLength(number);
    return (number == size);
}

bool TicTacToe::fullColumn()
{
    int column = currentColumn - 1;

    int number = 1;

    while ((field[currentLine][column] == getCurrentSymbol()) && (column >= 0))
    {
        --column;
        ++number;
    }

    column = currentColumn + 1;

    while ((field[currentLine][column] == getCurrentSymbol()) && (column < size))
    {
        ++column;
        ++number;
    }

    changeMaxLength(number);
    return (number == size);
}

char TicTacToe::getCurrentSymbol() const
{
    if (clickedButtons % 2)
    {
        return '0';
    }
    else
    {
        return 'X';
    }
}

void TicTacToe::changeMaxLength(int number)
{
    if (maxLength < number)
    {
        maxLength = number;
        winnerSymbol = getCurrentSymbol();
    }
}

void TicTacToe::getParameters(int &line, int &column, int id)
{
    while (line < size)
    {
        while (column < size)
        {
            if (idarray[line][column] == id)
            {
                break;
            }
            ++column;
        }
        if (idarray[line][column] == id)
        {
            break;
        }
        ++line;
    }
}

