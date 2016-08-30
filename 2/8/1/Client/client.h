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
    bool sendNicknameToServer(const QString &nickname);

    void setNickname(const QString &newNickname);
    QString getMyNickname();

private:
    QTcpSocket *serverSocket;
    QString nickname;

private slots:
    void getMessageFromServer();
    void connectionTerminated();
};
