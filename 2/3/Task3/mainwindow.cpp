#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QGridLayout>

const int numberButtons = 10;
const int operationButtons = 4;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    signalMapper = new QSignalMapper(this);
    lineEditor = new  QLineEdit;

    ui->gridLayout->addWidget(lineEditor, 0, 0, 1, 4);

    QPushButton *currentButton = nullptr;

    for (int i = 0; i < numberButtons; ++i)
    {
        currentButton = new QPushButton(QString::number(i));
        connect(currentButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(currentButton, QString::number(i));
        ui->gridLayout->addWidget(currentButton, (i - 1) / 3 + 1, (i - 1) % 3);
    }

    QChar names[4] = {'+', '-', '*', '/'};

    for (int i = 0; i < operationButtons; ++i)
    {
        currentButton = new QPushButton(names[i]);
        connect(currentButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(currentButton, names[i]);
        ui->gridLayout->addWidget(currentButton, i + 1, 3);
    }

    currentButton = new QPushButton("=");
    connect(currentButton, SIGNAL(clicked()), this, SLOT(calculate()));
    ui->gridLayout->addWidget(currentButton, 4, 0);

    currentButton = new QPushButton("0");
    connect(currentButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(currentButton, "0");
    ui->gridLayout->addWidget(currentButton, 4, 1);

    currentButton = new QPushButton("clear");
    connect(currentButton, SIGNAL(clicked()), this, SLOT(clear()));
    ui->gridLayout->addWidget(currentButton, 4, 2);

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(clicked(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete signalMapper;
    delete lineEditor;
}

void MainWindow::clicked(const QString &text)
{
    lineEditor->insert(text);
}

void MainWindow::calculate()
{
    calculator = new Calculator;
    QByteArray array = lineEditor->text().toLocal8Bit();
    calculator->read(array.data(), lineEditor->text().size());
    lineEditor->setText(calculator->calculate());
    delete calculator;
}

void MainWindow::clear()
{
    lineEditor->clear();
}
