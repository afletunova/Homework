#include "chat.h"

Chat::Chat(QObject *parent)
{}

void Chat::sendNickname(QTcpSocket *tcpSocket, const QString &nickname)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << (quint16)0 << nickname;
    out.device()->seek(0);
    out << (quint16)(data.size() - sizeof(quint16));
    tcpSocket->write(data);
}

void Chat::sendMessage(QTcpSocket *tcpSocket, const QString &message)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << (quint16)0 << message;
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

    QString message;
    in >> message;
    emit messageRecd(message);
}

void Chat::getNickname(QTcpSocket *tcpSocket)
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

    QString nickname;
    in >> nickname;
    emit changeNickname(nickname);
}
