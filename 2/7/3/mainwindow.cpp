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
    delete ui->baseLayout;
    delete ui;

}

void MainWindow::createField()
{
    ResizedFontPushButton *currentButton = nullptr;
    game = new TicTacToe(fieldSize);
    buttonLayout = new QGridLayout;
    ui->baseLayout->addLayout(buttonLayout, 1, 1);
    int k = -1;

    for (int i = 0; i < fieldSize; ++i)
    {
        for (int j = 0; j < fieldSize; ++j)
        {
            currentButton = new ResizedFontPushButton;
            currentButton->setObjectName(QString::number(++k));
            currentButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
            buttons.push_back(currentButton);
            connect(currentButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(currentButton, currentButton);
            buttonLayout->addWidget(currentButton, i % fieldSize + 1, j % fieldSize);
        }
    }

    currentButton = new ResizedFontPushButton;
    currentButton->setText("New game");
    currentButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    connect(currentButton, SIGNAL(clicked()), game, SLOT(newGame()));
    connect(currentButton, SIGNAL(clicked()), this, SLOT(newGame()));
    buttonLayout->addWidget(currentButton, fieldSize + 1, 0, 1, fieldSize);

    label = new QLabel;
    QFont font;
    font.setPointSize(14);
    label->setFont(font);
    ui->baseLayout->addWidget(label, 2, 1);

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
    ResizedFontPushButton *currentButton = this->findChild<ResizedFontPushButton *>();
    delete currentButton;
}
