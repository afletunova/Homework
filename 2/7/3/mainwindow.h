#pragma once

#include <QMainWindow>
#include <QSignalMapper>
#include <QGridLayout>
#include <QVector>
#include <QPushButton>

#include "tictactoe.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSignalMapper *signalMapper;
    QVector<QPushButton *> buttons;

    void createField();
    TicTacToe *game;

private slots:
    void newGame();
    void showResult(const QString &result);
    void changed(QPushButton *&button);

};
