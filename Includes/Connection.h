#ifndef CONNECTION_H
#define CONNECTION_H
#include    "IGui.h"

#include    <QMainWindow>
#include    <QMessageBox>

namespace Ui {
class Connection;
}

class Connection : public QMainWindow, public IGui
{
    Q_OBJECT


public:
    explicit Connection(QWidget *parent = 0);
    ~Connection();
    void    init();
    void    load();
    void    destroy();

private slots:
    void    connection();
    void    subscribe();

private:
    Ui::Connection *ui;
};

#endif // CONNECTION_H
