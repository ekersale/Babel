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
#include                "OpenCV.hh"
#include				"UserInfo.hh"
#include				"ThreadCom.hh"
#include                "OpenCV.hh"

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
	void				  setThread(void *ptr);
	void                  addContact(UserInfo *);

	private slots:
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
	void				  sendAddContact();
	void				  contactClick();

	public slots:
	void				  setNick(std::vector<const char *>, std::vector<int>);
	void				  setStatus(std::vector<const char *>, std::vector<int>);
	void				  setBirth(std::vector<const char *>, std::vector<int>);
	void				  setModule(std::vector<const char *>, std::vector<int>);
	void				  setSurname(std::vector<const char *>, std::vector<int>);
	void				  setName(std::vector<const char *>, std::vector<int>);
	void				  setAdress(std::vector<const char *>, std::vector<int>);
	void				  setPhone(std::vector<const char *>, std::vector<int>);
	void				  setAddAnswer(std::vector<const char *>, std::vector<int>);
	void				  setCallAnswer(std::vector<const char *>, std::vector<int>);
	void				  setCallRequest(std::vector<const char *>, std::vector<int>);
	void				  setRemoveAnswer(std::vector<const char *>, std::vector<int>);
	void				  setRemoveRequest(std::vector<const char *>, std::vector<int>);

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
	std::map<int, t_contact *> _bcontact;
	void			*_com;
	QPushButton			  *_pushtmp;
	int					 _activeUser;
};

#endif // HOME_H
