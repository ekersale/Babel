#include "../Includes/Home.hh"

#include "ui_Home.h"

#include    <iostream>


Home::Home(QWidget *parent) : QMainWindow(parent), ui(new Ui::Home)
{
	init();
	_pushtmp = NULL;
	_myid = 0;
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

	QObject::connect(ui->_btnClose, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(ui->_btn_Online, SIGNAL(clicked()), this, SLOT(changeOnline()));
	QObject::connect(ui->_btn_Away, SIGNAL(clicked()), this, SLOT(changeAway()));
	QObject::connect(ui->_btn_Busy, SIGNAL(clicked()), this, SLOT(changeBusy()));
	QObject::connect(ui->_btnAddContact, SIGNAL(clicked()), this, SLOT(showNewField()));
	QObject::connect(ui->_btnInviteContact, SIGNAL(clicked()), this, SLOT(invitContact()));
	QObject::connect(ui->_btnMicro, SIGNAL(clicked()), this, SLOT(callContact()));
	//QObject::connect(ui->_btnMicro, SIGNAL(clicked()), this, SLOT(recvFrameFrom()));                            
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
  _parser = new Parser(_xmlParser->getCommandArgs("commands.xml"));
  params = strdup(value.toStdString().c_str());

  packet_info->setCmd(nbCmd);
  packet_info->getChars().push_back(params);

  packet = (Packet *)_parser->encode(packet_info);

  serialize >> packet;

  if ((_tcp->sendSocket(1, (void *)serialize.str().c_str(), 65) == false))
    {
      std::cout << "Error Send" << std::endl;
      return false;
    }

  free(params);
  delete(packet);
  delete(packet_info);
  return true;
}

void	Home::sendNewPhone()
{
	QString newvalue;
	newvalue = ui->_linePhoneNumber->text();
	
	// send to serv the newvalue surname 
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
	
	// send to serv the newvalue surname 
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
	// send to serv the newvalue birthday 
       
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
	// send to serv the newvalue surname 
	
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
		if (value == 1) {
			ui->_label_Video->setAlignment(Qt::AlignCenter);
			ui->_label_Video->setPixmap(QPixmap::fromImage(img));
			ui->_label_Video->show();
		}
		if (value == 0) {
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

	///send ajout contact with contactname
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
	ui->_lineBirthday->setText(_musers[_activeUser]->get_birth().c_str());
	ui->_linePhoneNumber->setText(_musers[_activeUser]->get_phone().c_str());
	ui->_lineLocalisation->setText(_musers[_activeUser]->get_address().c_str());
	//displayConversation(senderObjName);
}

void    Home::invitContact()
{
	// srv = new Network(AF_INET, SOCK_DGRAM, "UDP", 1106);
	// srv->bindSocket("2000");
	// if (!sound.initializePA())

	//   std::cerr << "Error on InitPa()" << std::endl;
	// if (!(sound.initializeInput()))
	//   std::cerr << "Error on initParams()" << std::endl;
	// if (!(sound.initializeOutput()))                                                                           
	//   std::cerr << "Error on initParams()" << std::endl;
	// sound.openStream();
	// encode.opusEncoderCreate();
	// encode.opusDecoderCreate();

	_udp = new Network(AF_INET, SOCK_DGRAM, "UDP", 65000);
	_udp->bindSocket("2000");
	connect(timer, SIGNAL(timeout()), this, SLOT(recvFrameFrom()));
	timer->start();
	// while (1) {
	
	//   if (!(sound.readStream()))
	//     std::cerr << "Error on writeStream()" << std::endl;
	//   buffer = sound.getRecordedSamples();
	//   sound.writeStream(buffer, 480);                                                                          
	//   // tmp = encode.encodeFrame(buffer, 480);
	//   // int i;
	//   // for (i = 0; tmp[i]; i++);
	//   // srv->sendToSocket(id1, (void *)tmp, i); // revoir à id1
	//   // id1 = srv->recvFromSocket(); //premier recu, socket settée sur id1
	// sound.writeStream(encode.decodeFrame((unsigned char *)srv->get_buffer(), 480), encode.getBytesDecode());
	// }
}

void Home::threadReceive()
{
	float *buffer;
	unsigned char *tmp;

	if (!(sound.readStream()))
		std::cerr << "Error on writeStream()" << std::endl;
	buffer = sound.getRecordedSamples();
	tmp = encode.encodeFrame(buffer, 480);
	clt->sendToSocket(id, tmp, encode.getEncodedDataSize()); //envoie à id2 séttée sur une socket par connect
	clt->recvFromSocket();// recoit de n'importe qui qui connait
	// std::cout << "LEN RECUE" << clt->get_filled() << std::endl;  
	sound.writeStream(encode.decodeFrame((unsigned char *)clt->get_buffer(), 480), encode.getBytesDecode());
	static_cast<void>(buffer);
	static_cast<void>(tmp);
}

void    Home::threadCall()
{
	float *buffer;
	unsigned char *tmp;
	static bool isOk = false;

	id = srv->recvFromSocket();
	if (isOk == false) {
		sound.startStream();
		isOk = true;
	}
	sound.writeStream(encode.decodeFrame((unsigned char *)srv->get_buffer(), 480), encode.getBytesDecode());
	if (!(sound.readStream()))
		std::cerr << "Error on writeStream()" << std::endl;
	buffer = sound.getRecordedSamples();
	tmp = encode.encodeFrame(buffer, 480);
	srv->sendToSocket(id, tmp, encode.getEncodedDataSize()); // revoir à id1 
	(void)buffer;
	(void)tmp;
}


void    Home::callContact()
{
	/*if (!sound.initializePA())
		std::cerr << "Error on InitPa()" << std::endl;
	if (!(sound.initializeInput()))
		std::cerr << "Error on initParams()" << std::endl;
	if (!(sound.initializeOutput()))
		std::cerr << "Error on initParams()" << std::endl;
	sound.openStream();
	sound.startStream();
	encode.opusEncoderCreate();
	encode.opusDecoderCreate();

	_udp = new Network(AF_INET, SOCK_DGRAM, "UDP", 65000);
	_udp->bindSocket("2000");
	connect(timer, SIGNAL(timeout()), this, SLOT(recvFrameFrom()));
	timer->start();*/
	if (_activeUser == 0)
		return;
	IPacketInfo	*packet_info = new PacketInfo();

	char *pd1 = new char[2];

	pd1[0] = 1;
	packet_info->setCmd(24);
	packet_info->getChars().push_back(pd1);
	std::stringstream ss;
	ss << _activeUser;
	std::string tmp;
	ss >> tmp;
	packet_info->getChars().push_back(strdup(tmp.c_str()));
	ss.flush();
	ss << _myid;
	tmp.erase(tmp.begin(), tmp.end());
	ss >> tmp;
	packet_info->getChars().push_back(strdup(tmp.c_str()));
	Packet *enpacked = (Packet *)((ThreadCom *)_com)->getParser()->encode(packet_info);
	std::stringbuf sz;
	sz >> enpacked;
	if ((((ThreadCom *)_com)->getNetwork()->sendSocket(1, (void *)sz.str().c_str(), 65) == false))
		std::cout << "Error Send\n";
	delete(pd1);
	delete(enpacked);
}

void    Home::videoCallContact()
{
	_udp = new Network(AF_INET, SOCK_DGRAM, "UDP", 65000);
	_udp->connectToSocket(SERV_ADDR_IP, "2000");
	if (_video->isStopped())
	{
		std::cout << "Dans Home::videoCallContact > _video->isStopped " << std::endl;
		_video->play();
	}
	else
		_video->stop();
}

void    Home::hangHup()
{
	timer->stop();
	if (this->_isOncall == false)
	{
		QMessageBox::critical(this, "Error", "Vous ne pouvez pas raccrocher si vous n'avez pas d'appels");
		return;
	}
	else
	{
		; //Fonction pour la vidéo                                                                             
	}
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

void    Home::sendFrameTo(std::vector<unsigned char *> *frame)
{
	if (frame->size() != 8)
		return;
	for (size_t it = 0; it < frame->size(); it++) {
		if (_udp->sendToSocket(1, (*frame)[it], strlen((char *)((*frame)[it]))) == false)
			std::cout << "coucou" << std::endl;
	}
}

void    Home::recvFrameFrom(void)
{
	std::vector<unsigned char *> frame;
	int     packets = 0;
	unsigned char *part;

	while (packets < 8)
	{
		if (_udp->recvFromSocket() == false)
			std::cout << "coucou c'est la merde" << std::endl;
		int i = _udp->get_connected(0)->get_filled();
		std::cout << "" << std::endl;
		if (packets > 0)
			_udp->get_buffer()[i] = 0;
		part = new unsigned char[strlen((char *)_udp->get_buffer())];
		strcpy((char *)part, _udp->get_buffer());
		frame.push_back(part);
		++packets;
	}
	_video->displayFrames(frame);
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
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
}

void		Home::setRemoveAnswer(void *cmdptr, void *idptr)
{

}

void		Home::setCallRequest(void *cmdptr, void *idptr)
{
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
	UserInfo *pkt = _musers[id[0][0]];
	std::string tmp = pkt->get_name() + " audio call you";

	QMessageBox msgBox;
	msgBox.setText(tmp.c_str());
	msgBox.setInformativeText("Do you want to receve that call ?");
	msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::Ignore);
	msgBox.setDefaultButton(QMessageBox::Yes);
	int res = msgBox.exec();
	if (res == QMessageBox::Yes)
	{

	}
	else
	{

	}
}

void		Home::setCallAnswer(void *cmdptr, void *idptr)
{

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
	std::vector<const char *> *value = (std::vector<const char *> *)cmdptr;
	std::vector<int> *id = (std::vector<int> *)idptr;
}
