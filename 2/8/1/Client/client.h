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

    bool connection();
    void disconnection();
    bool sendMessage(const QString &message);

    QString getNickname();
    QString getServerNickname();

private:
    QTcpSocket *serverSocket;
    QString hostIP;
    quint16 port;
    QString nickname;
    QString serverNickname;

private slots:
    void getMessage();
    void connectionTerminated();
};
