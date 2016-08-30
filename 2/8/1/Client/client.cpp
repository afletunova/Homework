#include "client.h"

Client::Client()
    :serverSocket(nullptr)
{}

Client::~Client()
{
    delete serverSocket;
}

bool Client::connection(const QString &hostIP, quint16 hostPort)
{
    if (serverSocket)
    {
        serverSocket->disconnectFromHost();
    }
    serverSocket = new QTcpSocket;

    connect(serverSocket, &QTcpSocket::readyRead, this, &Client::getMessageFromServer);
    connect(serverSocket, &QTcpSocket::disconnected, this, &Client::connectionTerminated);

    serverSocket->connectToHost(hostIP, hostPort);

    if (!serverSocket->waitForConnected())
    {
        emit informationMessage("Cannot connect.");
        return false;
    }

    sendNicknameToServer(nickname);

    emit informationMessage("Connected.");
    return true;
}

void Client::disconnection()
{
    serverSocket->disconnectFromHost();
}

bool Client::sendMessageToServer(const QString &message)
{
    if (!serverSocket)
    {
        emit informationMessage("Error of connection.");
        return false;
    }

    sendMessage(serverSocket, message);
    return true;
}

bool Client::sendNicknameToServer(const QString &nickname)
{
    if (!serverSocket)
    {
        emit informationMessage("Error of connection.");
        return false;
    }

    sendNickname(serverSocket, nickname);
    return true;
}

QString Client::getMyNickname() const
{
    return nickname;
}

void Client::setNickname(const QString &newNickname)
{
    nickname = newNickname;
}

void Client::getMessageFromServer()
{
    getMessage(serverSocket);
}

void Client::connectionTerminated()
{
    emit informationMessage("Server is disconected.");
}

