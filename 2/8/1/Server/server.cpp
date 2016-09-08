#include "server.h"

Server::Server()
    :tcpServer(nullptr), clientSocket(nullptr)
{
    tcpServer = new QTcpServer(this);

    QList<QHostAddress> adresses = QNetworkInterface::allAddresses();
    for (auto a : adresses)
    {
        if (a.protocol() == QAbstractSocket::IPv4Protocol && tcpServer->listen(a))
        {
            break;
        }
    }

    if (!tcpServer->isListening())
    {
        emit informationMessage("Server is not listening. Please, try again.");
    }

    connect(tcpServer, &QTcpServer::newConnection, this, &Server::newConnection);
}

Server::~Server()
{
    tcpServer->close();
}

bool Server::sendMessageToClient(const QString &message)
{
    if (!clientSocket)
    {
        emit informationMessage("Error of client connection.");
        return false;
    }
    sendMessage(clientSocket, message);
    return true;
}

bool Server::sendNicknameToClient()
{
    if (!clientSocket)
    {
        emit informationMessage("Error of client connection.");
        return false;
    }
    sendNickname(clientSocket, nickname);
    return true;
}

bool Server::isConnected() const
{
    return clientSocket != nullptr;
}

QString Server::getIP() const
{
    return tcpServer->serverAddress().toString();
}

quint16 Server::getPort() const
{
    return tcpServer->serverPort();
}

QString Server::getMyNickname() const
{
    return nickname;
}

void Server::setNickname(const QString newNickname)
{
    nickname = newNickname;
}

void Server::getMessageFromClient()
{
    getMessage(clientSocket);
}

bool Server::newConnection()
{
    if (!tcpServer->hasPendingConnections())
    {
        return false;
    }
    clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &Server::getMessageFromClient);
    connect(clientSocket, &QTcpSocket::disconnected, this, &Server::connectionTerminated);
    connect(clientSocket, &QTcpSocket::destroyed, this, &Server::cleanClient);

    sendNicknameToClient();

    emit informationMessage("New connection from client.");
    return true;
}

void Server::connectionTerminated()
{
    emit informationMessage("Client is disconected.");
}

void Server::cleanClient()
{
    clientSocket->close();
    clientSocket = nullptr;
}
