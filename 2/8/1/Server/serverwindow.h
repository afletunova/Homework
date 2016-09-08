#pragma once

#include <QMainWindow>

#include "server.h"
#include "../plaintexteditwithlimits.h"

namespace Ui {
class ServerWindow;
}

/*!
 * \brief The ServerWindow class - represents main window of Server application.
 */

class ServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerWindow(QWidget *parent = 0);
    ~ServerWindow();

private:
    Ui::ServerWindow *ui;
    PlainTextEditWithLimits *dialogHistoryPlainTextEdit;
    Server server;
    QString clientNickname;

private slots:
    /*!
     * \brief sendMessage - called if user want to send message to client and clicked button "Send"
     */
    void sendMessage();
    /*!
     * \brief getMessage - called when client sends message to server.
     * \param newMessage
     */
    void getMessage(const QString &newMessage);
    /*!
     * \brief getNickname - called when client sends nickname to server.
     * \param newClientNickname
     */
    void getNickname(const QString &newClientNickname);
    /*!
     * \brief getInformationMessage - called if information message was required.
     * \param infoMessage
     */
    void getInformationMessage(const QString &infoMessage);
};
