#pragma once

#include <QMainWindow>
#include <QSignalMapper>
#include <QGridLayout>
#include <QVector>
#include <QPushButton>
#include <QLabel>

#include "tictactoe.h"
#include "resizedfontpushbutton.h"

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
    QVector<ResizedFontPushButton *> buttons;
    QGridLayout *buttonLayout;
    TicTacToe *game;
    QLabel *label;
    void createField();

private slots:
    void newGame();
    void showResult(const QString &result);
    void changed(QWidget *button);
    void deleteButtons();

};
