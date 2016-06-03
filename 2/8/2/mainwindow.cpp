#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent), ui(new Ui::MainWindow), bash(new Bash(this)), currentQuoteIndex(0)
{
    ui->setupUi(this);

    connect(bash, SIGNAL(quotesLoaded()), SLOT(onQuotesLoaded()));

    connect(ui->loadButton, SIGNAL(clicked()), SLOT(loadQuotes()));
    connect(ui->nextButton, SIGNAL(clicked()), SLOT(loadNextQuote()));
    connect(ui->voteUpButton, SIGNAL(clicked()),SLOT(voteUp()));
    connect(ui->voteDownButton, SIGNAL(clicked()),SLOT(voteDown()));
    connect(ui->bayanButton, SIGNAL(clicked()),SLOT(bayan()));

    loadQuotes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showQuote(int index)
{
    ui->quoteText->document()->setHtml(bash->getQuote(index).getText());
}

void MainWindow::loadQuotes()
{
    bash->loadQuotes();
}

void MainWindow::loadNextQuote()
{
    if (bash->isQuotesLoaded())
    {
        currentQuoteIndex = (currentQuoteIndex + 1) % bash->getQuotesCount();
        showQuote(currentQuoteIndex);
    }
}

void MainWindow::onQuotesLoaded()
{
    currentQuoteIndex = 0;
    showQuote(0);
}

void MainWindow::voteUp()
{
    bash->voteUp(currentQuoteIndex);
}

void MainWindow::voteDown()
{
    bash->voteDown(currentQuoteIndex);
}

void MainWindow::old()
{
    bash->old(currentQuoteIndex);
}
