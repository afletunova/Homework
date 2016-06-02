#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>

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
            buttons.push_front(currentButton);
            currentButton->setFixedSize(20, 20);
            connect(currentButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(currentButton, k);
            ui->buttonLayout->addWidget(currentButton, i % fieldSize + 1, j % fieldSize);
        }
    }

    currentButton = new QPushButton("New game");
    connect(currentButton, SIGNAL(clicked()), game, SLOT(newGame()));
    connect(currentButton, SIGNAL(clicked()), this, SLOT(newGame()));
    ui->buttonLayout->addWidget(currentButton, fieldSize + 1, 0, 1, fieldSize);

    connect(signalMapper, SIGNAL(mapped(QObject *)), this, SLOT(changed(QPushButton*&)));
}

void MainWindow::newGame()
{
    for (auto button : buttons)
    {
        button->setEnabled(true);
        button->setText("");
    }
}

void MainWindow::showResult(const QString &result)
{
    QMessageBox resultBox;
    resultBox.setText(result);
    resultBox.setStandardButtons(QMessageBox::Ok);
}

void MainWindow::changed(QPushButton *&button)
{
    game->changed(button);
}
