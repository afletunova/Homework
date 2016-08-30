#include "serverwindow.h"
#include "ui_serverwindow.h"

#include <QInputDialog>

ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow),
    dialogHistoryPlainTextEdit(nullptr),
    clientNickname("\0")
{
    ui->setupUi(this);

    dialogHistoryPlainTextEdit = new PlainTextEditWithLimits;
    ui->dialogHistoryGridLayout->addWidget(dialogHistoryPlainTextEdit);

    ui->IPLine->setText(server.getIP());
    ui->IPLine->setReadOnly(true);
    ui->PortLine->setText(QString("%1").arg(server.getPort()));
    ui->PortLine->setReadOnly(true);

    connect(ui->sendButton, &QPushButton::clicked, this, &ServerWindow::sendMessage);

    connect(&server, &Server::changeNickname, this, &ServerWindow::getNickname);
    connect(&server, &Server::messageRecd, this, &ServerWindow::getMessage);
    connect(&server, &Server::informationMessage, this, &ServerWindow::getInformationMessage);

    bool nicknameEntered;
    server.setNickname(QInputDialog::getText(0,
                                     "Hello",
                                     "Your nickname:",
                                     QLineEdit::Normal,
                                     "",
                                     &nicknameEntered));

    if (!nicknameEntered)
    {
        server.setNickname("Anonym");
    }
}

ServerWindow::~ServerWindow()
{
    delete ui;
    delete dialogHistoryPlainTextEdit;
}

void ServerWindow::sendMessage()
{
    QString newMessage = ui->sendMessageTextEdit->toPlainText();
    ui->sendMessageTextEdit->setText("\0");
    if (!server.sendMessageToClient(newMessage))
    {
        return;
    }

    dialogHistoryPlainTextEdit->appendPlainText(server.getMyNickname() + ": " + newMessage);
}

void ServerWindow::getMessage(const QString &newMessage)
{
    dialogHistoryPlainTextEdit->appendPlainText(clientNickname + ": " + newMessage);
}

void ServerWindow::getNickname(const QString &newClientNickname)
{
    clientNickname = newClientNickname;
}

void ServerWindow::getInformationMessage(const QString &infoMessage)
{
    dialogHistoryPlainTextEdit->appendPlainText(QString("-> %1").arg(infoMessage));
}
