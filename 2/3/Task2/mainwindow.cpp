#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->firstArgument, SIGNAL(valueChanged(int)), this, SLOT(calculator()));
    connect(ui->secondArgument, SIGNAL(valueChanged(int)), this, SLOT(calculator()));
    connect(ui->answer, SIGNAL(currentIndexChanged(int)), this, SLOT(calculator()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::calculator after select operation and changing arguments returns result value
 */

void MainWindow::calculator()
{
    int firstArgument = ui->firstArgument->value();
    int secondArgument = ui->secondArgument->value();
    char operation = ui->operationBox->currentText()[0].toLatin1();

    switch(operation)
    {
    case '+':
        ui->answer->setText(QString::number(firstArgument + secondArgument));
        break;
    case '-':
        ui->answer->setText(QString::number(firstArgument - secondArgument));
        break;
    case '*':
        ui->answer->setText(QString::number(firstArgument * secondArgument));
        break;
    case '/':
    {
        if (secondArgument != 0)
        {
            ui->answer->setText(QString::number(firstArgument / secondArgument));
        }
        else
        {
            ui->answer->setText(QString("Error!"));
        }
        break;
    }
    }
}
