#pragma once

#include <QMainWindow>

#include "server.h"
#include "../plaintexteditwithlimits.h"

namespace Ui {
class ServerWindow;
}

class ServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerWindow(QWidget *parent = 0);
    ~ServerWindow();

private:
    Ui::ServerWindow *ui;
    PlainTextEditWithLimits *dialogHistoryPlainTextEdit;
    Server server;
    QString clientNickname;

private slots:
    void sendMessage();
    void getMessage(const QString &newMessage);
    void getNickname(const QString &newClientNickname);
    void getInformationMessage(const QString &infoMessage);
};
