#pragma once

#include "..\chat.h"

#include <QString>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QNetworkInterface>

/*!
 * \brief The Server class - represents application which is represents server
 * Can exchange messages with client application
 */
class Server : public Chat
{
    Q_OBJECT

public:
    explicit Server();
    ~Server();

    /*!
     * \brief sendMessageToClient - calls function of sending message by class Chat
     * \param message
     * \return
     */
    bool sendMessageToClient(const QString &message);
    /*!
     * \brief sendNicknameToClient - calls function of sending nickname by class Chat
     * \return
     */
    bool sendNicknameToClient();
    /*!
     * \brief isConnected - return true if client is connected and false if it's not
     * \return
     */
    bool isConnected() const;

    /*!
     * \brief getIP
     * \return server IP
     */
    QString getIP() const;
    /*!
     * \brief getPort
     * \return server Port
     */
    quint16 getPort() const;

    /*!
     * \brief getMyNickname
     * \return return server nickname
     */
    QString getMyNickname() const;
    /*!
     * \brief setNickname - change server nickname
     * \param newNickname
     */
    void setNickname(const QString newNickname);

private:
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
    QString nickname;

private slots:
    /*!
     * \brief getMessageFromClient - gets new message from client.
     */
    void getMessageFromClient();
    /*!
     * \brief newConnection - sets a new connection and notifies if new client is connected.
     * \return
     */
    bool newConnection();
    /*!
     * \brief connectionTerminated - notifies that connection has been disconnected.
     */
    void connectionTerminated();
    /*!
     * \brief cleanClient - sets clientSocket as nullptr if client is disconnected.
     */
    void cleanClient();
};
