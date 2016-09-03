#include "clientwindow.h"
#include "ui_clientwindow.h"

#include <QInputDialog>

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow),
    dialogHistoryPlainTextEdit(nullptr),
    serverNickname("\0")
{
    ui->setupUi(this);

    dialogHistoryPlainTextEdit = new PlainTextEditWithLimits;
    ui->plaintTextEditLayout->addWidget(dialogHistoryPlainTextEdit);

    ui->IPLine->setPlaceholderText("Enter IP...");
    ui->portLine->setPlaceholderText("Enter port...");

    setTabOrder(ui->IPLine, ui->portLine);
    setTabOrder(ui->portLine, ui->textEdit);

    connect(ui->disconnectButton, &QPushButton::clicked, &client, &Client::disconnection);
    connect(ui->connectButton, &QPushButton::clicked, this, &ClientWindow::connection);
    connect(ui->sendButton, &QPushButton::clicked, this, &ClientWindow::sendMessage);

    connect(&client, &Client::informationMessage, this, &ClientWindow::getInformationMessage);
    connect(&client, &Client::messageRecd, this, &ClientWindow::getMessage);
    connect(&client, &Client::changeNickname, this, &ClientWindow::getNickname);

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
    delete dialogHistoryPlainTextEdit;
    delete ui;
}

void ClientWindow::sendMessage()
{
    QString newMessage = ui->textEdit->toPlainText();
    ui->textEdit->setText("\0");

    if (!client.sendMessageToServer(newMessage))
    {
        return;
    }

    dialogHistoryPlainTextEdit->appendPlainText(client.getMyNickname() + ": " + newMessage);
}

void ClientWindow::getMessage(const QString &newMessage)
{
    dialogHistoryPlainTextEdit->appendPlainText(serverNickname + ": " + newMessage);
}

void ClientWindow::getNickname(const QString &newServerNickname)
{
    serverNickname = newServerNickname;
}

void ClientWindow::getInformationMessage(const QString &infoMessage)
{
    dialogHistoryPlainTextEdit->appendPlainText(QString("-> %1").arg(infoMessage));
}

void ClientWindow::connection()
{
    client.connection(ui->IPLine->text(), ui->portLine->text().toInt());
}
