#include "chat.h"

enum {newMessageToSend, newNicknameToSend};

Chat::Chat()
{}

void Chat::sendNickname(QTcpSocket *tcpSocket, const QString &nickname)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << (quint16)0 << (quint16)newNicknameToSend << nickname;
    out.device()->seek(0);
    out << (quint16)(data.size() - sizeof(quint16));
    tcpSocket->write(data);
}

void Chat::sendMessage(QTcpSocket *tcpSocket, const QString &message)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << (quint16)0 << (quint16)newMessageToSend << message;
    out.device()->seek(0);
    out << (quint16)(data.size() - sizeof(quint16));
    tcpSocket->write(data);
}

void Chat::getMessage(QTcpSocket *tcpSocket)
{
    QDataStream in(tcpSocket);
    quint16 dataSize = 0;

    if (dataSize == 0)
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
        {
            return;
        }
        in >> dataSize;
    }

    if (tcpSocket->bytesAvailable() < dataSize)
    {
        return;
    }

    quint16 senderCommand;
    in >> senderCommand;

    if (senderCommand == (quint16)newMessageToSend)
    {
        QString message;
        in >> message;
        emit messageRecd(message);
    }
    else if (senderCommand == (quint16)newNicknameToSend)
    {
        QString nickname;
        in >> nickname;
        emit changeNickname(nickname);
    }
}
