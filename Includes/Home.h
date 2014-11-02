#ifndef HOME_H
#define HOME_H

#include    <QMainWindow>
#include    <QHBoxLayout>
#include    <QMessageBox>

#include	"../Includes/OpenCV.h"

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
  void	  updatePlayerUI(QImage test);

private:
  Ui::Home *ui;
  e_type  _status;
  bool    _isOncall;
  OpenCV	*_video;
};

#endif // HOME_H
