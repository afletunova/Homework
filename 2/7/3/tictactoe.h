#pragma once

#include <QObject>
#include <QPushButton>

class TicTacToe : public QObject
{
    Q_OBJECT

public:
    TicTacToe(int size);
    ~TicTacToe();

public slots:
    void newGame();
    void changed(QPushButton *&button);

signals:
    void gameOver(const QString &) const;

private:
    int size;
    int buttons;
    int clickedButtons;
    int currentLine;
    int currentColumn;
    int maxLength;

    int **idarray;
    char **field;
    char winnerSymbol;

    void setSymbol(QPushButton *&button);
    void cleanUpField();
    bool win();
    bool fullDiagonal();
    bool fullSecondDiagonal();
    bool fullLine();
    bool fullColumn();
    char getCurrentSymbol() const;
    void changeMaxLength(int number);
    void getParameters(int &line, int &column, int id);
};

