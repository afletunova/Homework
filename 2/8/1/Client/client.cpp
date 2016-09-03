#include "client.h"

Client::Client()
    :serverSocket(nullptr)
{}

Client::~Client()
{
    disconnection();
    delete serverSocket;
}

void Client::connection(const QString &hostIP, quint16 hostPort)
{
    if (serverSocket)
    {
        serverSocket->disconnectFromHost();
    }
    serverSocket = new QTcpSocket;

    serverSocket->connectToHost(hostIP, hostPort);

    connect(serverSocket, &QTcpSocket::readyRead, this, &Client::getMessageFromServer);
    connect(serverSocket, &QTcpSocket::disconnected, this, &Client::connectionTerminated);
    connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(emitErrorMessage(QAbstractSocket::SocketError)));

    if (!serverSocket->waitForConnected())
    {
        emit informationMessage("Cannot connect.");
        return;
    }

    sendNicknameToServer(nickname);

    emit informationMessage("Connected.");
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
    emit informationMessage("Server is disconnected.");
}

void Client::emitErrorMessage(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
    {
        break;
    }
    case QAbstractSocket::HostNotFoundError:
    {
        emit informationMessage("Error: The host was not found.");
        break;
    }
    case QAbstractSocket::ConnectionRefusedError:
    {
        emit informationMessage("Error: The connection was refused by the peer.");
        break;
    }
    default:
    {
        emit informationMessage("Error: The following error occured: " + serverSocket->errorString());
    }
    }
}

