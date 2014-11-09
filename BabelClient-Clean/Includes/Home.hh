//
// Home.hh for Home in /home/urvoy_p/Desktop/BabelRepos
// 
// Made by Pierre-Antoine Urvoy
// Login   <urvoy_p@epitech.net>
// 
// Started on  Sun Nov  9 01:53:53 2014 Pierre-Antoine Urvoy
// Last update Sun Nov  9 02:48:02 2014 Pierre-Antoine Urvoy
//

#ifndef			HOME_H
#define			HOME_H

#ifdef			_WIN32
#include		<QtWidgets/QMainWindow>
#include		<QtWidgets/QHBoxLayout>
#include		<QtWidgets/QMessageBox>
#include		<QtCore/QTimer>
#else
#include		<QMainWindow>
#include		<QHBoxLayout>
#include		<QMessageBox>
#include		<QTimer>
#endif
#include		<vector>
#include		<iostream>

#include		"Network.hh"
#include		"BabelSound.hh"
#include		"BabelEncoder.hh"

#include		"../Includes/OpenCV.hh"

#define SERV_ADDR_IP	"10.13.253.162"
//#define SERV_ADDR_IP	"127.0.0.1"

namespace		Ui
{
  class			Home;
}

enum			e_type
{
			ONLINE,
			AWAY,
			BUSY,
};

class			Home : public QMainWindow
{
    Q_OBJECT

public:
  explicit		Home(QWidget *parent = 0);
  void			init(void);
  void			load(void);
  void			destroy(void);
  ~Home(void);
  void			setStatus(e_type newStatus);
  e_type		getStatus(void) const;
  void			defineStatus(e_type newStatus);
  bool			isOncall(void);
  void			setOncall(bool available);
				   
private slots:
  void			addContact(void);
  void			invitContact(void);
  void			callContact(void);
  void			videoCallContact(void);
  void			hangHup(void);
  void			changeOnline(void);
  void			changeAway(void);
  void			changeBusy(void);
  void			showNewField(void);
  void			updatePlayerUI(QImage, int);
  void			sendFrameTo(std::vector<unsigned char *> *);
  void			recvFrameFrom(void);
  void			threadReceive(void);
  void			threadCall(void);

private:
  Ui::Home *		ui;
  ABabelSound		sound;
  BabelEncoder		encode;
  Network *		srv; //anciennement de type UNetwork
  Network *		clt; //anciennement de type UNetwork
  Network *		_tcp;
  Network *		_udp;
  QTimer *		timer;
  int			id;
  e_type		_status;
  bool			_isOncall;
  OpenCV *		_video;
};

#endif // HOME_H
