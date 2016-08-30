#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QDataStream>

/*!
 * \brief The Chat class - represents an application that can receive, process and send messages.
 */

class Chat : public QObject
{
    Q_OBJECT
public:
    explicit Chat();

    /*!
     * \brief sendMessage - processes message and sends it with relevant code.
     * \param tcpSocket
     * \param message
     */
    void sendMessage(QTcpSocket *tcpSocket, const QString &message);
    /*!
     * \brief sendNickname - processes nickname and sends it with relevant code.
     * \param tcpSocket
     * \param nickname
     */
    void sendNickname(QTcpSocket *tcpSocket, const QString &nickname);
    /*!
     * \brief getMessage - processes received message and determine what it is: nickname or message.
     * \param tcpSocket
     */
    void getMessage(QTcpSocket *tcpSocket);

signals:
    /*!
     * \brief changeNickname - called if nickname was received.
     */
    void changeNickname(const QString &);
    /*!
     * \brief messageRecd - called if message was received.
     */
    void messageRecd(const QString &);
    /*!
     * \brief informationMessage - called if information message was required.
     */
    void informationMessage(const QString &);
};
