#include "mainwindow.h"
#include <QApplication>
#include "tictactoetest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    TicTacToeTest tester;
    QTest::qExec(&tester);

    return a.exec();
}
