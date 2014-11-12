#include "../Includes/Home.hh"

#include "ui_Home.h"

#include    <iostream>


Home::Home(QWidget *parent) : QMainWindow(parent), ui(new Ui::Home)
{
	init();
	_pushtmp = NULL;
	_myid = 0;
	
	_links.push_back(new Network(AF_INET, SOCK_DGRAM, "UDP", 65000));
	_links.push_back(new Network(AF_INET, SOCK_DGRAM, "UDP", 65000));
	_links.push_back(new Network(AF_INET, SOCK_DGRAM, "UDP", 65000));
}

Home::~Home()
{
	delete ui;
}

void    Home::init()
{
	setFixedSize(1080, 929);
	this->_status = ONLINE;
	this->_isOncall = false; //False pour dire qu'on a pas de conversation
	load();
}

void    Home::load()
{
	ui->setupUi(this);
	ui->_line_addContact->hide();


	_video = new OpenCV();

	timer = new QTimer(this);

	QLabel::connect(_video, SIGNAL(processedImage(QImage, int)), this, SLOT(updatePlayerUI(QImage, int)));
	
	
	//QLabel::connect(_video, SIGNAL(sendFrame(std::vector<unsigned char*> *)),
	//this, SLOT(sendFrameTo(std::vector<unsigned char *> *)));
	
	//QLabel::connect(_video, SIGNAL(sendFrame(std::vector<unsigned char*> *)), this,
	  //SLOT(sendFrameTo(std::vector<unsigned char *> *)));


	QLabel::connect(_video, SIGNAL(sendFrame(std::vector<unsigned char*> *)), this, SLOT(sendFrameTo(std::vector<unsigned char *> *)));

	QObject::connect(ui->_btnClose, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(ui->_btn_Online, SIGNAL(clicked()), this, SLOT(changeOnline()));
	QObject::connect(ui->_btn_Away, SIGNAL(clicked()), this, SLOT(changeAway()));
	QObject::connect(ui->_btn_Busy, SIGNAL(clicked()), this, SLOT(changeBusy()));
	QObject::connect(ui->_btnAddContact, SIGNAL(clicked()), this, SLOT(showNewField()));
	// QObject::connect(ui->_btnInviteContact, SIGNAL(clicked()), this, SLOT(invitContact()));
	QObject::connect(ui->_btnMicro, SIGNAL(clicked()), this, SLOT(callContact()));
	QObject::connect(ui->_btnCam, SIGNAL(clicked()), this, SLOT(videoCallContact()));
	QObject::connect(ui->_btnHangUp, SIGNAL(clicked()), this, SLOT(hangHup()));
	QObject::connect(ui->_line_addContact, SIGNAL(returnPressed()), this, SLOT(sendAddContact()));
	QObject::connect(ui->_lineContactName, SIGNAL(returnPressed()), this, SLOT(sendNewName()));
	QObject::connect(ui->_lineSurnameEdit, SIGNAL(returnPressed()), this, SLOT(sendNewSurname()));
	QObject::connect(ui->_lineBirthday, SIGNAL(returnPressed()), this, SLOT(sendNewBirthday()));
	QObject::connect(ui->_lineLocalisation, SIGNAL(returnPressed()), this, SLOT(sendNewLocalisation()));
	QObject::connect(ui->_linePhoneNumber, SIGNAL(returnPressed()), this, SLOT(sendNewPhone()));
	defineStatus(this->_status);
}

bool	Home::sendData(QString value, int nbCmd)
{
  //Value => params ( nom / location ) etc..
  
  IPacketInfo		*packet_info;
  Packet		*packet;
  std::stringbuf	serialize;
  char *params;

  packet_info = new PacketInfo();

  // _parser = new Parser();

  params = strdup(value.toStdString().c_str());

  packet_info->setCmd(nbCmd);
  packet_info->getChars().push_back(params);

  packet = (Packet *)((ThreadCom *)_com)->getParser()->encode(packet_info);

  serialize >> packet;

  if (((ThreadCom *)_com)->getNetwork()->sendSocket(1, (void *)serialize.str().c_str(), 65) == false)
    {
      std::cout << "Error Send" << std::endl;
      return false;
    }

  // free(params);
  // delete(packet);
  // delete(packet_info);
  return true;
}

void	Home::sendNewPhone()
{
	QString newvalue;
	
	newvalue = ui->_linePhoneNumber->text();
	_musers[_activeUser]->set_phone(newvalue.toStdString());

	if ((sendData(newvalue, 11) == false))
	  {
	    QMessageBox::information(this, "Information", "L'update du téléphone n'a pas été send");
	    return;
	  }
}

void	Home::sendNewLocalisation()
{
	QString newvalue;
	
	newvalue = ui->_lineLocalisation->text();
	_musers[_activeUser]->set_adress(newvalue.toStdString());

	if ((sendData(newvalue, 10) == false))
	  {
	    QMessageBox::information(this, "Information", "L'update de la location  n'a pas été send");
	    return;
	  }
}

void	Home::sendNewBirthday()
{
	QString newvalue;
	
	newvalue = ui->_lineBirthday->text();
	_musers[_activeUser]->set_birth(newvalue.toStdString());
       
	if ((sendData(newvalue, 7) == false))
	  {
	    QMessageBox::information(this, "Information", "L'update du téléphone n'a pas été send");
	    return;
	  }
}

void	Home::sendNewSurname()
{
  QString newvalue;
  newvalue = ui->_lineSurnameEdit->text();
  _musers[_activeUser]->set_surname(newvalue.toStdString());
  
  if ((sendData(newvalue, 8) == false))
    {
      QMessageBox::information(this, "Information", "L'update du téléphone n'a pas été send");
      return;
    }
}

void	Home::sendNewName()
{
	QString newvalue;
	newvalue = ui->_lineContactName->text();
	//send to serv the newvalue contactname
}

void    Home::updatePlayerUI(QImage img, int value)
{
	if (!img.isNull())
	{
	  if (value == 1)
	    {
	      ui->_label_Video->setAlignment(Qt::AlignCenter);
	      ui->_label_Video->setPixmap(QPixmap::fromImage(img));
	      ui->_label_Video->show();
	    }
	  if (value == 0)
	    {
	      ui->_label_VideoPerso->setAlignment(Qt::AlignCenter);
	      ui->_label_VideoPerso->setPixmap(QPixmap::fromImage(img));
	      ui->_label_VideoPerso->setScaledContents(true);
	      ui->_label_VideoPerso->show();
	    }
	}
}

void    Home::destroy()
{
}

void    Home::showNewField()
{
	if (!(ui->_line_addContact->text().isEmpty()))
		ui->_line_addContact->clear();
	ui->_line_addContact->show();
}

void	Home::sendAddContact()
{
	QString contactname;
	
	ui->_line_addContact->hide();
	contactname = ui->_line_addContact->text();
	ui->_line_addContact->clear();
	if ((sendData(contactname, 20) == false))
	  {
	    QMessageBox::information(this, "Information", "L'update du téléphone n'a pas été send");
	    return;
	  }
}

void    Home::addContact(UserInfo *added)
{
	QListWidgetItem *item;
	QFont			font;
	QPushButton		*but;
	QString			name;
	QPixmap			*pixmap = NULL;
	QPalette		palette;
	t_contact		*ptr = new t_contact;
	std::string		tmp;
	int				state;


	state = added->get_status();
	if (state < 1 && state > 4)
		state = 4;
	item = new QListWidgetItem();
	tmp = added->get_name() + " " + added->get_surname();
	name = tmp.c_str();
	item->setText(name);
	item->setTextAlignment(21);
	item->setBackgroundColor(QColor(255, 255, 255));
	font.setPointSize(12);
	font.setFamily("calibri");
	item->setFont(font);
	font.setPointSize(8);
	ui->_listContact->addItem(item);
	but = new QPushButton(added->get_nickname().c_str());
	but->setFlat(true);
	switch (state)
	{
	case 2:
		pixmap = new QPixmap("./Images/BabelHD_0001s_0005s_0002_status.png");
		break;
	case 3:
		pixmap = new QPixmap("./Images/BabelHD_0001s_0003s_0000_status.png");
		break;
	case 4:
		pixmap = new QPixmap("./Images/BabelHD_0001s_0000s_0000_status.png");
		break;
	case 1:
		pixmap = new QPixmap("./Images/BabelHD_0001s_0002s_0000_status.png");
		break;
	default:
		break;
	}
	if (pixmap != NULL)
		palette.setBrush(but->backgroundRole(), QBrush(*pixmap));
	but->setFlat(true);
	but->setAutoFillBackground(true);
	but->setPalette(palette);
	but->setFont(font);
	but->setMinimumSize(250, 42);
	but->setMaximumSize(250, 42);
	std::stringstream ss;
	ss << added->get_id();
	ss >> tmp;
	but->setObjectName(tmp.c_str());
	but->setStyleSheet("text-align: middle");
	connect(but, SIGNAL(clicked()), this, SLOT(contactClick()));
	QHBoxLayout *layout = new QHBoxLayout();
	layout->addWidget(but);
	layout->alignment();
	ptr->but = but;
	ptr->item = item;
	_bcontact[added->get_id()] = ptr;
	QWidget *widget = new QWidget();
	widget->setLayout(layout);
	item->setSizeHint(widget->sizeHint());
	ui->_listContact->setItemWidget(item, widget);
}

void Home::contactClick()
{
	QObject *senderObj = sender();
	QString senderObjName = senderObj->objectName();
	QPushButton *tmp = (QPushButton *)senderObj;
	if (_pushtmp != NULL)
	{
		_pushtmp->setEnabled(true);
		_pushtmp->setStyleSheet("QPushButton{color: rgb(0, 0, 0);}");
	}
	tmp->setEnabled(false);
	_pushtmp = tmp;
	_activeUser = senderObjName.toInt();
	if (_activeUser == _myid)
	{
		ui->_lineContactName->setReadOnly(false);
		ui->_lineSurnameEdit->setReadOnly(false);
		ui->_lineBirthday->setReadOnly(false);
		ui->_lineLocalisation->setReadOnly(false);
		ui->_linePhoneNumber->setReadOnly(false);
	}
	else
	{
		ui->_lineContactName->setReadOnly(true);
		ui->_lineSurnameEdit->setReadOnly(true);
		ui->_lineBirthday->setReadOnly(true);
		ui->_lineLocalisation->setReadOnly(true);
		ui->_linePhoneNumber->setReadOnly(true);
	}
	ui->_lineContactName->setText(_musers[_activeUser]->get_name().c_str());
	ui->_lineSurnameEdit->setText(_musers[_activeUser]->get_surname().c_str());
	ui->_lineBirthday->setText(_musers[_activeUser]->get_birth().c_str());
	ui->_lineLocalisation->setText(_musers[_activeUser]->get_address().c_str());
	ui->_linePhoneNumber->setText(_musers[_activeUser]->get_phone().c_str());
}

void    Home::callContact()
{
	if (_activeUser == _myid)
		return;
	IPacketInfo	*packet_info = new PacketInfo();

	char *module = new char[1];
	module[0] = 1;
	packet_info->setCmd(24);
	packet_info->getChars().push_back(module);
	packet_info->getInts().push_back(_activeUser);
	char *nbrid = new char[2];
	nbrid[0] = 1;
	packet_info->getChars().push_back(nbrid);
	packet_info->getInts().push_back(_myid);
	Packet *enpacked = (Packet *)((ThreadCom *)_com)->getParser()->encode(packet_info);
	std::stringbuf sz;
	sz >> enpacked;
	if ((((ThreadCom *)_com)->getNetwork()->sendSocket(1, (void *)sz.str().c_str(), 65) == false))
		std::cout << "Error Send\n";
	delete[] module;
	delete[] nbrid;
	delete(enpacked);
}

void    Home::videoCallContact()
{
	if (_activeUser == _myid)
		return;
	IPacketInfo	*packet_info = new PacketInfo();

	char *module = new char[1];
	module[0] = 2;
	packet_info->setCmd(24);
	packet_info->getChars().push_back(module);
	packet_info->getInts().push_back(_activeUser);
	char *nbrid = new char[2];
	nbrid[0] = 1;
	packet_info->getChars().push_back(nbrid);
	packet_info->getInts().push_back(_myid);
	Packet *enpacked = (Packet *)((ThreadCom *)_com)->getParser()->encode(packet_info);
	std::stringbuf sz;
	sz >> enpacked;
	if ((((ThreadCom *)_com)->getNetwork()->sendSocket(1, (void *)sz.str().c_str(), 65) == false))
		std::cout << "Error Send\n";
	delete[] module;
	delete[] nbrid;
	delete(enpacked);
}

void    Home::hangHup()
{
	timer->stop();
	if (this->_isOncall == false)
	{
		QMessageBox::critical(this, "Error", "Vous ne pouvez pas raccrocher si vous n'avez pas d'appels");
		_links[0]->sflush();
		return;
	}
	else
		_links[1]->sflush();
}

void    Home::setStatus(e_type newStatus)
{
	this->_status = newStatus;
	defineStatus(this->_status);
}

e_type  Home::getStatus() const
{
	return (this->_status);
}

void    Home::defineStatus(e_type status)
{
	if (status == ONLINE)
	{
		QSize   hide(0, 0);
		QSize   printable(32, 32);

		ui->_btn_Online->setIconSize(printable);
		ui->_btn_Busy->setIconSize(hide);
		ui->_btn_Away->setIconSize(hide);
		ui->_label_StatusInfos->setText("En ligne");
		return;
	}
	if (status == AWAY)
	{
		QSize   hide(0, 0);
		QSize   printable(32, 32);

		ui->_btn_Away->setIconSize(printable);
		ui->_btn_Busy->setIconSize(hide);
		ui->_btn_Online->setIconSize(hide);
		ui->_label_StatusInfos->setText("Absent");
		return;
	}
	if (status == BUSY)
	{
		QSize   hide(0, 0);
		QSize   printable(32, 32);

		ui->_btn_Busy->setIconSize(printable);
		ui->_btn_Online->setIconSize(hide);
		ui->_btn_Away->setIconSize(hide);
		ui->_label_StatusInfos->setText("Occupé");
		return;
	}
}

void    Home::changeOnline()
{
	e_type  newStatus;

	newStatus = ONLINE;
	this->setStatus(newStatus);
	defineStatus(newStatus);
}

void    Home::changeAway()
{
	e_type  newStatus;

	newStatus = AWAY;
	this->setStatus(newStatus);
	defineStatus(newStatus);
}

void    Home::changeBusy()
{
	e_type  newStatus;

	newStatus = BUSY;
	defineStatus(newStatus);
}

bool    Home::isOncall()
{
	return (this->_isOncall);
}

void    Home::setOncall(bool available)
{
	this->_isOncall = available;
}

void			Home::setThread(void *ptr)
{
	_com = (ThreadCom *)ptr;
	connect((ThreadCom *)ptr, SIGNAL(s_changeNick(void *, void *)), this, SLOT(setNick(void *, void *)));
	connect((ThreadCom *)ptr, SIGNAL(s_changeStatus(void *, void *)), this, SLOT(setStatus(void *, void *)));
	connect((ThreadCom *)ptr, SIGNAL(s_changeBirth(void *, void *)), this, SLOT(setBirth(void *, void *)));
	connect((ThreadCom *)ptr, SIGNAL(s_contactModule(void *, void *)), this, SLOT(setModule(void *, void *)));
	connect((ThreadCom *)ptr, SIGNAL(s_changeSurname(void *, void *)), this, SLOT(setSurname(void *, void *)));
	connect((ThreadCom *)ptr, SIGNAL(s_changeName(void *, void *)), this, SLOT(setName(void *, void *)));
	connect((ThreadCom *)ptr, SIGNAL(s_changeAddress(void *, void *)), this, SLOT(setAdress(void *, void *)));
	connect((ThreadCom *)ptr, SIGNAL(s_changePhone(void *, void *)), this, SLOT(setPhone(void *, void *)));
	connect((ThreadCom *)ptr, SIGNAL(s_addAnswer(void *, void *)), this, SLOT(setAddAnswer(void *, void *)));
	connect((ThreadCom *)ptr, SIGNAL(s_removeRequest(void *, void *)), this, SLOT(setRemoveRequest(void *, void *)));
	connect((ThreadCom *)ptr, SIGNAL(s_removeAnswer(void *, void *)), this, SLOT(setRemoveAnswer(void *, void *)));
	connect((ThreadCom *)ptr, SIGNAL(s_requestCall(void *, void *)), this, SLOT(setCallRequest(void *, void *)));
	connect((ThreadCom *)ptr, SIGNAL(s_callAnswer(void *, void *)), this, SLOT(setCallAnswer(void *, void *)));
}


void		Home::setRemoveRequest(void *cmdptr, void *idptr)
{
	// std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	// std::vector<int> *id = (std::vector<int> *)idptr;
	static_cast<void>(idptr);	
	static_cast<void>(cmdptr);
}

void		Home::setRemoveAnswer(void *cmdptr, void *idptr)
{
  static_cast<void>(cmdptr);
  static_cast<void>(idptr);
}

void		Home::setCallRequest(void *cmdptr, void *idptr)
{
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
	IPacketInfo	*packet_info = new PacketInfo();
	UserInfo *pkt = _musers[id[0][0]];
	std::string tmp;
	QMessageBox msgBox;
	std::string ip = value[0][1];
	char *answer_user = new char[1];

	if ((int)value[0][0] == 1)
		tmp = pkt->get_name() + " audio call you";
	if ((int)value[0][0] == 2)
		tmp = pkt->get_name() + " video call you";

	msgBox.setText(tmp.c_str());
	msgBox.setInformativeText("Do you want to receve that call ?");
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Ignore);
	msgBox.setDefaultButton(QMessageBox::Yes);
	int res = msgBox.exec();
	packet_info->setCmd(26);
	packet_info->getInts().push_back(pkt->get_id());
	if (res == QMessageBox::Yes)
		answer_user[0] = 0; // OK
	else
		answer_user[0] = 9; // OK
	// #PA #bind
	int modules = -1;
	int port = 2000;
	std::stringstream ss;
	bool retbind = false;
	while (retbind == false)
	{
		ss.flush();
		ss << port;
		retbind = _links[(int)value[0][0] - 1]->bindSocket(ss.str());
		++port;
		if (port >= 65535)
			answer_user[0] = 9;
	}
	// 3*  PORT     ||| P1 : audio    P2 : video     P3 : text
	ss >> port;
	if ((int)value[0][0] == 1)
		packet_info->getInts().push_back(port); // P1
	else
		packet_info->getInts().push_back(0);
	if ((int)value[0][0] == 2)
		packet_info->getInts().push_back(port); // P1
	else
		packet_info->getInts().push_back(0);
	packet_info->getInts().push_back(0); // P3
	Packet *enpacked = (Packet *)((ThreadCom *)_com)->getParser()->encode(packet_info);
	std::stringbuf sz;
	sz >> enpacked;
	if ((((ThreadCom *)_com)->getNetwork()->sendSocket(1, (void *)sz.str().c_str(), 65) == false))
		std::cout << "Error Send\n";
	delete(enpacked);
	//LANCER LA RECEPTION UDP
	if ((int)value[0][0] == 1) {
		timer = new QTimer;
		_sockudp[0] = _links[0]->recvFromSocket();
		if (!sound.initializePA())
			std::cerr << "Error on InitPa()" << std::endl;
		if (!(sound.initializeInput()))
			std::cerr << "Error on initParams()" << std::endl;
		if (!(sound.initializeOutput()))
			std::cerr << "Error on initParams()" << std::endl;
		sound.openStream();
		sound.startStream();
		encode.opusEncoderCreate();
		encode.opusDecoderCreate();
		connect(timer, SIGNAL(timeout()), this, SLOT(threadCall()));
		timer->start();
	}
	if ((int)value[0][0] == 2) {
		_sockudp[1] = _links[1]->recvFromSocket();
		timer = new QTimer;
		connect(timer, SIGNAL(timeout()), this, SLOT(recvFrameFrom()));
		timer->start();
	}
}

void    Home::threadCall()
{
	float *buffer;
	unsigned char *tmp;
	static bool isOk = false;

	if (isOk == false) {
		sound.startStream();
		isOk = true;
	}
	sound.writeStream(encode.decodeFrame((unsigned char *)_links[0]->get_buffer(), 480), encode.getBytesDecode());
	if (!(sound.readStream()))
		std::cerr << "Error on writeStream()" << std::endl;
	buffer = sound.getRecordedSamples();
	tmp = encode.encodeFrame(buffer, 480);
	_links[0]->sendToSocket(_sockudp[0], tmp, encode.getEncodedDataSize()); // revoir à id1 
	_links[0]->recvFromSocket();
	(void)buffer;
	(void)tmp;
}

void    Home::sendFrameTo(std::vector<unsigned char *> *frame)
{
	if (frame->size() != 8)
		return;
	for (size_t it = 0; it < frame->size(); it++) {
		if (_links[1]->sendToSocket(_sockudp[1], (*frame)[it], strlen((char *)((*frame)[it]))) == false)
			std::cerr << "Failed to send frame" << std::endl;
	}
}

void    Home::recvFrameFrom(void)
{
	std::vector<unsigned char *> frame;
	int     packets = 0;
	unsigned char *part;

	while (packets < 8)
	{
		if (_links[1]->recvFromSocket() == false)
			return;
		int i = _links[1]->get_connected(0)->get_filled();
		std::cout << "" << std::endl;
		if (packets > 0)
			_links[1]->get_buffer()[i] = 0;
		part = new unsigned char[strlen((char *)_links[1]->get_buffer())];
		strcpy((char *)part, _links[1]->get_buffer());
		frame.push_back(part);
		++packets;
	}
	_video->displayFrames(frame);
}

void		Home::playVideo()
{
	if (_video->isStopped())
		_video->play();
	else
		_video->stop();
}

void		Home::setCallAnswer(void *cmdptr, void *idptr)
{
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
	std::stringstream ss;
	if ((int)value[0][0] == 0) // OK
	{
		std::string ip;
		ip = value[0][1];

		int PA = id[0][0];
		int PV = id[0][1];
		int PT = id[0][2];
		int modules = -1;
		while (++modules < 3)
		{
			ss.flush();
			if (id[0][modules] != 0)
			{
				ss << id[0][modules];
				int socktmp;
				_sockudp[modules - 1] = _links[modules]->connectSocket(ip, ss.str());
			}
			if (id[0][modules] == 1)
			{
				if (!sound.initializePA())
					std::cerr << "Error on InitPa()" << std::endl;
				if (!(sound.initializeInput()))
					std::cerr << "Error on initParams()" << std::endl;
				if (!(sound.initializeOutput()))
					std::cerr << "Error on initParams()" << std::endl;
				sound.openStream();
				sound.startStream();
				encode.opusEncoderCreate();
				encode.opusDecoderCreate();
				connect(timer, SIGNAL(timeout()), this, SLOT(threadCall()));
				timer->start();
			}
			else {
				connect(timer, SIGNAL(timeout), this, SLOT(recvFrameFrom()));
				playVideo();
				timer->start();
			}
		}
	}
	else {
		QMessageBox msgBox;
		msgBox.setText("Contact not available");
		msgBox.setInformativeText("Try later !");
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.setDefaultButton(QMessageBox::Yes);
		msgBox.exec();
	}
}

void		Home::setNick(void *cmdptr, void *idptr)
{
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
	static int tmp = 0;

	std::map<int, UserInfo *>::iterator it;
	if ((it = _musers.find(id[0][0])) == _musers.end()) {
		if (tmp == 0)
			_myid = id[0][0];
		tmp++;
		UserInfo *info = new UserInfo;
		info->set_id(id[0][0]);
		info->set_nickname(value[0][0]);
		_musers[id[0][0]] = info;
		addContact(_musers[id[0][0]]);
	}
	else {
		UserInfo *tmp = _musers[id[0][0]];
		tmp->set_nickname(value[0][0]);
		std::string stmp;
		stmp = tmp->get_nickname();
		std::map<int, t_contact *>::iterator it;
		if ((it = _bcontact.find(id[0][0])) == _bcontact.end())
			return;
		_bcontact[id[0][0]]->but->setText(stmp.c_str());
	}
}

void		Home::setStatus(void *cmdptr, void *idptr)
{
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
	std::map<int, UserInfo *>::iterator it;
	static int tmp = 0;

	if ((it = _musers.find(id[0][0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		if (tmp == 0)
			_myid = id[0][0];
		tmp++;
		info->set_id(id[0][0]);
		info->set_status((*value)[0][0]);
		_musers[id[0][0]] = info;
		addContact(_musers[id[0][0]]);
	}
	else {
		UserInfo *tmp = _musers[id[0][0]];
		QPixmap			*pixmap = NULL;
		QPalette		palette;

		tmp->set_status((*value)[0][0]);
		int itmp = (*value)[0][0];
		switch (itmp)
		{
		case 2:
			pixmap = new QPixmap("./Images/BabelHD_0001s_0005s_0002_status.png");
			break;
		case 3:
			pixmap = new QPixmap("./Images/BabelHD_0001s_0003s_0000_status.png");
			break;
		case 4:
			pixmap = new QPixmap("./Images/BabelHD_0001s_0000s_0000_status.png");
			break;
		case 1:
			pixmap = new QPixmap("./Images/BabelHD_0001s_0002s_0000_status.png");
			break;
		default:
			break;
		}
		if (pixmap != NULL)
			palette.setBrush(_bcontact[id[0][0]]->but->backgroundRole(), QBrush(*pixmap));
		_bcontact[id[0][0]]->but->setPalette(palette);
	}
}

void		Home::setBirth(void *cmdptr, void *idptr)
{
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
	std::map<int, UserInfo *>::iterator it;
	static int tmp = 0;

	if ((it = _musers.find(id[0][0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		if (tmp == 0)
			_myid = id[0][0];
		tmp++;
		info->set_id(id[0][0]);
		info->set_birth((*value)[0]);
		_musers[id[0][0]] = info;
	}
	else {
		UserInfo *tmp = _musers[id[0][0]];
		tmp->set_birth((*value)[0]);
	}
}

void		Home::setModule(void *cmdptr, void *idptr)
{
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
	std::map<int, UserInfo *>::iterator it;
	static int tmp = 0;

	if ((it = _musers.find(id[0][0])) == _musers.end()) {
		if (tmp == 0)
			_myid = id[0][0];
		tmp++;
		UserInfo *info = new UserInfo;
		info->set_id(id[0][0]);
		info->set_module((*value)[0][0]);
		_musers[id[0][0]] = info;
	}
	else {
		UserInfo *tmp = _musers[id[0][0]];
		tmp->set_module((*value)[0][0]);
	}
}

void		Home::setSurname(void *cmdptr, void *idptr)
{
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
	std::map<int, UserInfo *>::iterator it;
	static int tmp = 0;

	if ((it = _musers.find(id[0][0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		if (tmp == 0)
			_myid = id[0][0];
		tmp++;
		info->set_id(id[0][0]);
		std::cout << info->get_id() << std::endl;
		info->set_surname((*value)[0]);
		_musers[id[0][0]] = info;
		addContact(_musers[id[0][0]]);
	}
	else {
		UserInfo *tmp = _musers[id[0][0]];
		std::string stmp;
		tmp->set_surname((*value)[0]);
		stmp = tmp->get_name() + " " + tmp->get_surname();
		std::map<int, t_contact *>::iterator it;
		if ((it = _bcontact.find(id[0][0])) == _bcontact.end())
			return;
		_bcontact[id[0][0]]->item->setText(stmp.c_str());
	}
}

void		Home::setName(void *cmdptr, void *idptr)
{
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
	std::map<int, UserInfo *>::iterator it;
	static int tmp = 0;

	if ((it = _musers.find(id[0][0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		if (tmp == 0)
			_myid = id[0][0];
		tmp++;
		info->set_id(id[0][0]);
		info->set_name((*value)[0]);
		_musers[id[0][0]] = info;
		addContact(_musers[id[0][0]]);
	}
	else {
		UserInfo *tmp = _musers[id[0][0]];
		tmp->set_name((*value)[0]);
		std::string stmp;
		stmp = tmp->get_name() + " " + tmp->get_surname();
		std::map<int, t_contact *>::iterator it;
		if ((it = _bcontact.find(id[0][0])) == _bcontact.end())
			return;
		_bcontact[id[0][0]]->item->setText(stmp.c_str());
	}
}

void		Home::setAdress(void *cmdptr, void *idptr)
{
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
	std::map<int, UserInfo *>::iterator it;
	static int tmp = 0;

	if ((it = _musers.find(id[0][0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		if (tmp == 0)
			_myid = id[0][0];
		tmp++;
		info->set_id(id[0][0]);
		info->set_adress((*value)[0]);
		_musers[id[0][0]] = info;
	}
	else {
		UserInfo *tmp = _musers[id[0][0]];
		tmp->set_adress((*value)[0]);
	}
}

void		Home::setPhone(void *cmdptr, void *idptr)
{
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
	std::map<int, UserInfo *>::iterator it;
	static int tmp = 0;

	if ((it = _musers.find(id[0][0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		if (tmp == 0)
			_myid = id[0][0];
		tmp++;
		info->set_id(id[0][0]);
		info->set_phone((*value)[0]);
		_musers[id[0][0]] = info;
	}
	else {
		UserInfo *tmp = _musers[id[0][0]];
		tmp->set_phone((*value)[0]);
	}
}

void		Home::setAddAnswer(void *cmdptr, void *idptr)
{
	// std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	// std::vector<int> *id = (std::vector<int> *)idptr;
	static_cast<void>(cmdptr);
	static_cast<void>(idptr);
}
