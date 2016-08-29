#include "../chat.h"

#include <QString>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QNetworkInterface>

class Client : public Chat
{
    Q_OBJECT

public:
    explicit Client();
    ~Client();

    bool connection(const QString &IP, quint16 hostPort);
    void disconnection();
    bool sendMessage(const QString &message);

    QString getNickname();
    void setNickname(const QString &newNickname);
    QString getServerNickname();

private:
    QTcpSocket *serverSocket;
    QString nickname;
    QString serverNickname;

private slots:
    void getMessage();
    void connectionTerminated();
};
