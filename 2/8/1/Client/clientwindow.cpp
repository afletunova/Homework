#include "clientwindow.h"
#include "ui_clientwindow.h"

#include <QInputDialog>

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);

    plainTextEdit = new PlainTextEditWithLimits;
    ui->plaintTextEditLayout->addWidget(plainTextEdit);

    ui->IPLine->setPlaceholderText("Enter IP...");
    ui->portLine->setPlaceholderText("Enter port...");

    connect(ui->connectButton, &QPushButton::clicked, this, &ClientWindow::connection);
    connect(ui->disconnectButton, &QPushButton::clicked, &client, &Client::disconnection);
    connect(ui->sendButton, &QPushButton::clicked, this, &ClientWindow::sendMessage);

    connect(&client, &Client::informationMessage, this, &ClientWindow::getInformationMessage);
    connect(&client, &Client::messageRecd, this, &ClientWindow::getMessage);

    bool nicknameEntered;
    client.setNickname(QInputDialog::getText(0,
                                     "Hello",
                                     "Your nickname:",
                                     QLineEdit::Normal,
                                     "",
                                     &nicknameEntered));

    if (!nicknameEntered)
    {
        client.setNickname("Anonym");
    }
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

void ClientWindow::getInformationMessage(const QString &infoMessage)
{
    plainTextEdit->appendPlainText(QString("-> %1").arg(infoMessage));
}

void ClientWindow::connection()
{
    client.connection(ui->IPLine->text(), ui->portLine->text().toInt());
}
