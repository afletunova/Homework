#include "../chat.h"

#include <QString>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QNetworkInterface>

/*!
 * \brief The Client class - represent application which can connect to server and exchange messages with it
 */

class Client : public Chat
{
    Q_OBJECT

public:
    explicit Client();
    ~Client();

    /*!
     * \brief connection - try to connect with server and return emit with information message about connection.
     * \param IP
     * \param hostPort
     */
    void connection(const QString &IP, quint16 hostPort);
    /*!
     * \brief disconnection - called if user want to disconnect from server.
     */
    void disconnection();
    /*!
     * \brief sendMessageToServer - calls function of sending message by class Chat
     * \param message
     * \return
     */
    bool sendMessageToServer(const QString &message);
    /*!
     * \brief sendNicknameToServer - calls function of sending nickname by class Chat
     * \param nickname
     * \return
     */
    bool sendNicknameToServer(const QString &nickname);

    /*!
     * \brief setNickname - change client nickname.
     * \param newNickname
     */
    void setNickname(const QString &newNickname);
    /*!
     * \brief getMyNickname - return client nickname.
     * \return
     */
    QString getMyNickname() const;

private:
    QTcpSocket *serverSocket;
    QString nickname;

private slots:
    /*!
     * \brief getMessageFromServer - gets new message from server.
     */
    void getMessageFromServer();
    /*!
     * \brief connectionTerminated - notifies that connection has been disconnected.
     */
    void connectionTerminated();
    /*!
     * \brief emitInformationMessage - emit information message in case of error of connection with server.
     */
    void emitErrorMessage(QAbstractSocket::SocketError socketError);
};
