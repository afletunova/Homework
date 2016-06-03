#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "tictactoe.h"

class TicTacToeTest : public QObject
{
    Q_OBJECT

private:
    TicTacToe *game;
    QPushButton *button;
    QVector<QPushButton *> buttons;

private slots:

    void init()
    {
        game = new TicTacToe(3);
        for (int i = 0; i < 9; ++i)
        {
            button = new QPushButton;
            button->setObjectName(QString::number(i));
            buttons.push_back(button);
        }
    }

    void cleanup()
    {
        for (auto button : buttons)
        {
            delete button;
        }
        buttons.clear();
        delete game;
    }

    void firstPlayerWinnerTest()
    {
        game->changed(buttons[0]);
        game->changed(buttons[2]);
        game->changed(buttons[4]);
        game->changed(buttons[1]);
        QCOMPARE(QString("First player win!"), game->changed(buttons[8]));
    }

    void secondPlayerWinnerTest()
    {
        game->changed(buttons[0]);
        game->changed(buttons[4]);
        game->changed(buttons[8]);
        game->changed(buttons[1]);
        game->changed(buttons[2]);
        QCOMPARE(QString("Second player win!"), game->changed(buttons[7]));
    }
};
