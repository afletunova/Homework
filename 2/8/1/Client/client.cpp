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

    connect(serverSocket, &QTcpSocket::readyRead, this, &Client::getMessage);
    connect(serverSocket, &QTcpSocket::disconnected, this, &Client::connectionTerminated);

    serverSocket->connectToHost(hostIP, hostPort);

    if (!serverSocket->waitForConnected())
    {
        emit informationMessage("Cannot connect.");
        return false;
    }

    emit informationMessage("Connected.");
    return true;
}

void Client::disconnection()
{
    serverSocket->disconnectFromHost();
}

bool Client::sendMessage(const QString &message)
{
    if (!serverSocket)
    {
        emit informationMessage("Error of connection.");
        return false;
    }

    send(serverSocket, message);
    return true;
}

QString Client::getNickname()
{
    return nickname;
}

void Client::setNickname(const QString &newNickname)
{
    nickname = newNickname;
}

void Client::getMessage()
{
    get(serverSocket);
}

void Client::connectionTerminated()
{
    emit informationMessage("Server is disconected.");
}

QString Client::getServerNickname()
{
    return serverNickname;
}

