#ifndef CONNECTION_H
#define CONNECTION_H

#include    "IGui.hh"

#ifdef		_WIN32
#include    <QtWidgets/QMainWindow>
#include    <QtWidgets/QMessageBox>
#else
#include    <QMainWindow>
#include    <QMessageBox>
#endif

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
