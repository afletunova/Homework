#pragma once

#include <QMainWindow>
#include "bash.h"

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
    void showQuote(int index);

    Ui::MainWindow *ui;
    Bash *bash;
    int currentQuoteIndex;

private slots:
    void loadQuotes();
    void loadNextQuote();
    void onQuotesLoaded();
    void voteUp();
    void voteDown();
    void old();
};
