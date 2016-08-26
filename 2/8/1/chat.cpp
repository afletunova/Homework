#include "chat.h"

Chat::Chat(QObject *parent)
{}

void Chat::send(QTcpSocket *tcpSocket, const QString &message)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << (quint16)0 << message;
    out.device()->seek(0);
    out << (quint16)(data.size() - sizeof(quint16));
    tcpSocket->write(data);
}

void Chat::get(QTcpSocket *tcpSocket)
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
