#pragma once

#include "..\chat.h"

#include <QString>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QNetworkInterface>

class Server : public Chat
{
    Q_OBJECT

public:
    explicit Server();
    ~Server();

    bool sendMessageToClient(const QString &message);
    bool sendNicknameToClient();
    bool isConnected() const;

    QString getIP() const;
    quint16 getPort() const;

    QString getMyNickname() const;
    void setNickname(const QString newNickname);

private:
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
    QString nickname;

private slots:
    void getMessageFromClient();
    bool newConnection();
    void connectionTerminated();
    void cleanClient();
};
