#include <QMainWindow>

#include "../plaintexteditwithlimits.h"
#include "client.h"

namespace Ui {
class ClientWindow;
}

/*!
 * \brief The ClientWindow class - represents main window of Client application.
 */

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = 0);
    ~ClientWindow();

private:
    Ui::ClientWindow *ui;
    PlainTextEditWithLimits *dialogHistoryPlainTextEdit;
    Client client;
    QString serverNickname;

private slots:
    /*!
     * \brief sendMessage - called if user want to send message to server and clicked button "Send".
     */
    void sendMessage();
    /*!
     * \brief getMessage - called when server sends message to client.
     * \param newMessage
     */
    void getMessage(const QString &newMessage);
    /*!
     * \brief getNickname - called when server sends nickname to client.
     * \param newServerNickname
     */
    void getNickname(const QString &newServerNickname);
    /*!
     * \brief getInformationMessage - called if information message was required.
     * \param infoMessage
     */
    void getInformationMessage(const QString &infoMessage);
    /*!
     * \brief connection - called if user want to connect to server and clicked button "Connect"
     */
    void connection();
};
