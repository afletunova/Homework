#include "mainwindow.h"
#include <QApplication>

#include "calculatortest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    CalculatorTest tester;
    QTest::qExec(&tester);

    return a.exec();
}
