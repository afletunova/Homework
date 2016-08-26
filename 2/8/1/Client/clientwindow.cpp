#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);

    plainTextEdit = new PlainTextEditWithLimits;
    ui->plaintTextEditLayout->addWidget(plainTextEdit);

    connect(ui->connectButton, &QPushButton::clicked, this, &ClientWindow::connection);
    connect(ui->disconnectButton, &QPushButton::clicked, &client, &Client::disconnection);
    connect(ui->sendButton, &QPushButton::clicked, this, &ClientWindow::sendMessage);
    connect(&client, &Client::messageRecd, this, &ClientWindow::getMessage);
}

ClientWindow::~ClientWindow()
{
    delete ui;
    delete plainTextEdit;
}

void ClientWindow::sendMessage()
{
    QString message = ui->textEdit->toPlainText();
    ui->textEdit->setText("\0");

    if (!client.sendMessage(message))
    {
        return;
    }

    plainTextEdit->appendPlainText(client.getNickname());
    plainTextEdit->appendPlainText(QString(": %1").arg(message));
}

void ClientWindow::getMessage(const QString &message)
{
    plainTextEdit->appendPlainText(client.getServerNickname());
    plainTextEdit->appendPlainText(QString(": %1").arg(message));
}

void ClientWindow::connection()
{

}
