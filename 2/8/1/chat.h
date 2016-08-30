#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QDataStream>

class Chat : public QObject
{
    Q_OBJECT
public:
    explicit Chat();

    void sendMessage(QTcpSocket *tcpSocket, const QString &message);
    void sendNickname(QTcpSocket *tcpSocket, const QString &nickname);
    void getMessage(QTcpSocket *tcpSocket);

signals:
    void changeNickname(const QString &);
    void messageRecd(const QString &);
    void informationMessage(const QString &);
};
