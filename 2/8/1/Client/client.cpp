#include "client.h"

Client::Client()
    :serverSocket(nullptr), hostIP("\0"), port(0)
{}

Client::~Client()
{
    delete serverSocket;
}

bool Client::connection()
{
    if (serverSocket)
    {
        serverSocket->disconnectFromHost();
    }
    serverSocket = new QTcpSocket;

    connect(serverSocket, &QTcpSocket::readyRead, this, &Client::getMessage);
    connect(serverSocket, &QTcpSocket::disconnected, this, &Client::connectionTerminated);

    serverSocket->connectToHost(hostIP, port);

    if (!serverSocket->waitForConnected())
    {
        emit infoMessage("Cannot connect.");
        return false;
    }

    emit infoMessage("Connected.");
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
        emit infoMessage("Error of connection.");
        return false;
    }

    send(serverSocket, message);
    return true;
}

void Client::getMessage()
{
    get(serverSocket);
}

void Client::connectionTerminated()
{
    emit infoMessage("Server is disconected.");
}

QString Client::getNickname()
{
    return nickname;
}

QString Client::getServerNickname()
{
    return serverNickname;
}

