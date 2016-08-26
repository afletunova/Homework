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
    PlainTextEditWithLimits *plainTextEdit;
    Client client;

private slots:
    void sendMessage();
    void getMessage(const QString &message);
//    void getInfo(const QString &newMessage);
    void connection();
};
