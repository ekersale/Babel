#ifndef HOME_H
#define HOME_H

#include    <QMainWindow>
#include    <QHBoxLayout>
#include    <QMessageBox>
#include <iostream>
#include    <QTimer>
#include "UNetwork.h"
#include "BabelSound.h"
#include "BabelEncoder.h"


#define SERV_ADDR_IP "127.0.0.1"


namespace Ui {
class Home;
}

enum e_type
{
    ONLINE,
    AWAY,
    BUSY,
};

class Home : public QMainWindow
{
    Q_OBJECT


public:
    explicit Home(QWidget *parent = 0);
    void    init();
    void    load();
    void    destroy();
    ~Home();
    void    setStatus(e_type newStatus);
    e_type  getStatus();
    void    defineStatus(e_type newStatus);
    bool    isOncall();
    void    setOncall(bool available);

private slots:
    void    addContact();
    void    invitContact();
    void    callContact();
    void    videoCallContact();
    void    hangHup();
    void    changeOnline();
    void    changeAway();
    void    changeBusy();
    void    showNewField();
    void    threadReceive();
    void    threadCall();

private:
    Ui::Home *ui;
    ABabelSound sound;
    BabelEncoder encode;
    UNetwork *srv;
    UNetwork *clt;
    QTimer *timer;
    int id;
    e_type  _status;
    bool    _isOncall;
};

#endif // HOME_H
