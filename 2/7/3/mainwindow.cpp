#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>
#include <QPushButton>

const int fieldSize = 3;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    signalMapper = new QSignalMapper(this);

    createField();
}

MainWindow::~MainWindow()
{
    deleteButtons();
    delete signalMapper;
    delete game;
    delete ui->buttonLayout;
    delete ui;

}

void MainWindow::createField()
{
    QPushButton *currentButton = nullptr;
    game = new TicTacToe(fieldSize);
    int k = -1;

    for (int i = 0; i < fieldSize; ++i)
    {
        for (int j = 0; j < fieldSize; ++j)
        {
            currentButton = new QPushButton;
            currentButton->setObjectName(QString::number(++k));
            buttons.push_back(currentButton);
            currentButton->setFixedSize(20, 20);
            connect(currentButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(currentButton, currentButton);
            ui->buttonLayout->addWidget(currentButton, i % fieldSize + 1, j % fieldSize);
        }
    }

    currentButton = new QPushButton("New game");
    connect(currentButton, SIGNAL(clicked()), game, SLOT(newGame()));
    connect(currentButton, SIGNAL(clicked()), this, SLOT(newGame()));
    ui->buttonLayout->addWidget(currentButton, fieldSize + 1, 0, 1, fieldSize);

    label = new QLabel;
    ui->buttonLayout->addWidget(label, fieldSize + 2, 0);

    connect(game, SIGNAL(gameOver(QString)), this, SLOT(showResult(QString)));

    connect(signalMapper, SIGNAL(mapped(QWidget *)), this, SLOT(changed(QWidget *)));
}

void MainWindow::newGame()
{
    for (auto button : buttons)
    {
        button->setEnabled(true);
        button->setText("");
    }
    label->setText("");
}

void MainWindow::showResult(const QString &result)
{
    label->setText(result);
}

void MainWindow::changed(QWidget *button)
{
    game->changed(button);
}

void MainWindow::deleteButtons()
{
    for (auto button: this->buttons)
    {
        delete button;
    }
    buttons.clear();
    QPushButton *currentButton = this->findChild<QPushButton *>();
    delete currentButton;
}
