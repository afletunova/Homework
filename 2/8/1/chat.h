#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QDataStream>

class Chat : public QObject
{
    Q_OBJECT
public:
    explicit Chat(QObject *parent = 0);

    void send(QTcpSocket *tcpSocket, const QString &message);
    void get(QTcpSocket *tcpSocket);

signals:
    void messageRecd(const QString &);
    void infoMessage(const QString &);
};
