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
#include                "Parser.hh"
#include                "XMLParser.hh"

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
	bool			sendData(QString data, int size);
	private slots:
	// void                  invitContact(void);
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
	void                  threadCall(void);
	void				  sendAddContact();
	void				  contactClick();

	public slots:
	void				  setNick(void *, void *);
	void				  setStatus(void *, void *);
	void				  setBirth(void *, void *);
	void				  setModule(void *, void *);
	void				  setSurname(void *, void *);
	void				  setName(void *, void *);
	void				  setAdress(void *, void *);
	void				  setPhone(void *, void *);
	void				  setAddAnswer(void *, void *);
	void				  setCallAnswer(void *, void *);
	void				  setCallRequest(void *, void *);
	void				  setRemoveAnswer(void *, void *);
	void				  setRemoveRequest(void *, void *);
	void				  sendNewName();
	void				  sendNewSurname();
	void				  sendNewBirthday();
	void				  sendNewLocalisation();
	void				  sendNewPhone();
	void				  playVideo();

private:
	Ui::Home *            ui;
	ABabelSound           sound;
	BabelEncoder          encode;
	//Network *             srv; //anciennement de type UNetwork
	//Network *             clt; //anciennement de type UNetwork
	Network *             _tcp;
	Network *             _udp;
        Parser		      *_parser;
	XMLParser	      *_xmlParser;
	std::vector<Network *> _links;
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
	int					_myid;
	int					_sockudp[3];
};

#endif // HOME_H
