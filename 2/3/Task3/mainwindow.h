#pragma once

#include <QMainWindow>
#include <QSignalMapper>
#include <QLineEdit>

#include "calculator.h"

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
    QLineEdit *lineEditor;

private slots:
    void clicked(const QString &text);
    void calculate();
    void clear();
};
