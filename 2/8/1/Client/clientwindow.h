#include <QMainWindow>

#include "plaintexteditwithlimits.h"
#include "client.h"

namespace Ui {
class ClientWindow;
}

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
    void sendMessage();
    void getMessage(const QString &message);
    void getNickname(const QString &newServerNickname);
    void getInformationMessage(const QString &infoMessage);
    void connection();
};
