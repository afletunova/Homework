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
    bool sendMessageToServer(const QString &message);

    void setNickname(const QString &newNickname);
    QString getMyNickname();
    QString getServerNickname();

private:
    QTcpSocket *serverSocket;
    QString nickname;
    QString serverNickname;

private slots:
    void getMessageFromServer();
    void connectionTerminated();
    void getNewServerNickname();
};
