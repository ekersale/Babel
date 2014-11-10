#ifndef                 HOME_H
#define                 HOME_H

#ifdef                  _WIN32
#include                <QtWidgets/QMainWindow>
#include                <QtWidgets/QHBoxLayout>
#include                <QtWidgets/QMessageBox>
#include                <QtCore/QTimer>
#else
#include                <QMainWindow>
#include                <QHBoxLayout>
#include                <QMessageBox>
#include                <QTimer>
#endif
#include                <vector>
#include                <iostream>
#include				<map>

#include                "Network.hh"
#include                "BabelSound.hh"
#include                "BabelEncoder.hh"
<<<<<<< HEAD
#include                "OpenCV.hh"
#include				"UserInfo.hh"
=======

#include		"ThreadCom.hh"

#include                "../Includes/OpenCV.hh"
>>>>>>> 4e49177b2cb682479725d6d39c58b551c7f0d71b

#define SERV_ADDR_IP    "10.13.253.162"
//#define SERV_ADDR_IP  "127.0.0.1"                                                                                    

namespace               Ui
{
  class                 Home;
}

enum                    e_type
  {
    ONLINE,
    AWAY,
    BUSY,
  };

class                   Home : public QMainWindow
{
    Q_OBJECT

public:
  explicit              Home(QWidget *parent = 0);
  void                  init(void);
  void                  load(void);
  void                  destroy(void);
  ~Home(void);
  void                  setStatus(e_type newStatus);
  e_type                getStatus(void) const;
  void                  defineStatus(e_type newStatus);
  bool                  isOncall(void);
  void                  setOncall(bool available);
  void			setThread(void *ptr);
private slots:
  void                  addContact(void);
  void                  invitContact(void);
  void                  callContact(void);
  void                  videoCallContact(void);
  void                  hangHup(void);
  void                  changeOnline(void);
  void                  changeAway(void);
  void                  changeBusy(void);
  void                  showNewField(void);
  void                  updatePlayerUI(QImage, int);
  void                  sendFrameTo(std::vector<unsigned char *> *);
  void                  recvFrameFrom(void);
  void                  threadReceive(void);
  void                  threadCall(void);

private:
  Ui::Home *            ui;
  ABabelSound           sound;
  BabelEncoder          encode;
  Network *             srv; //anciennement de type UNetwork
  Network *             clt; //anciennement de type UNetwork
  Network *             _tcp;
  Network *             _udp;
  QTimer *              timer;
  int                   id;
  e_type                _status;
  bool                  _isOncall;
  OpenCV *              _video;
  std::map<int, UserInfo *> _musers;
  void			*_com;
};

#endif // HOME_H
