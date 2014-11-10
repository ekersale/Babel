#include "../Includes/Home.hh"

#include "ui_Home.h"

#include    <iostream>


Home::Home(QWidget *parent) : QMainWindow(parent), ui(new Ui::Home)
{
  init();
  // _tcp = new Network(AF_INET, SOCK_STREAM, "TCP", sizeof(Packet));                                            
  //   _udp = new Network(AF_INET, SOCK_DGRAM, "UDP", 65000);                                                    
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
  QLabel::connect(_video, SIGNAL(sendFrame(std::vector<unsigned char*> *)), this, SLOT(sendFrameTo(std::vector<u\
												   nsigned char *> *)));
  QObject::connect(ui->_btnClose, SIGNAL(clicked()), this, SLOT(close()));
  QObject::connect(ui->_btn_Online, SIGNAL(clicked()), this, SLOT(changeOnline()));
  QObject::connect(ui->_btn_Away, SIGNAL(clicked()), this, SLOT(changeAway()));
  QObject::connect(ui->_btn_Busy, SIGNAL(clicked()), this, SLOT(changeBusy()));
  QObject::connect(ui->_btnAddContact, SIGNAL(clicked()), this, SLOT(showNewField()));
  QObject::connect(ui->_btnInviteContact, SIGNAL(clicked()), this, SLOT(invitContact()));
  QObject::connect(ui->_btnMicro, SIGNAL(clicked()), this, SLOT(callContact()));
  // QObject::connect(ui->_btnMicro, SIGNAL(clicked()), this, SLOT(recvFrameFrom()));                            
  QObject::connect(ui->_btnCam, SIGNAL(clicked()), this, SLOT(videoCallContact()));
  QObject::connect(ui->_btnHangUp, SIGNAL(clicked()), this, SLOT(hangHup()));
  QObject::connect(ui->_line_addContact, SIGNAL(returnPressed()), this, SLOT(addContact()));

  defineStatus(this->_status);
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

void    Home::addContact()
{
  int state = 1;
  //std::cout << "Fuck ça marchera " << std::endl;                                                               
  ui->_line_addContact->hide();
  //ui->_line_addContact->clear();                                                                               

  QListWidgetItem *item;
  item = new QListWidgetItem();
  item->setText(ui->_line_addContact->text());
  item->setTextAlignment(21);
  //item->setSizeHint(QSize(80, 50));                                                                            
  item->setBackgroundColor(QColor(255, 255, 255));
  QFont font;
  font.setPointSize(12);
  font.setFamily("calibri");
  item->setFont(font);



  font.setPointSize(8);
  ui->_listContact->addItem(item);
  QPushButton *but = new QPushButton(ui->_line_addContact->text());
  but->setFlat(true);

  QPixmap *pixmap;
  QPalette palette;

  switch (state)
    {
    case 1:
      pixmap = new QPixmap("./Images/BabelHD_0001s_0005s_0002_status.png");
      break;
    case 2:
      pixmap = new QPixmap("./Images/BabelHD_0001s_0003s_0000_status.png");
      break;
    case 3:
      pixmap = new QPixmap("./Images/BabelHD_0001s_0000s_0000_status.png");
      break;
    case 4:
      pixmap = new QPixmap("./Images/BabelHD_0001s_0002s_0000_status.png");
      break;
    default:
      break;
    }

  palette.setBrush(but->backgroundRole(), QBrush(*pixmap));
  but->setFlat(true);
  but->setAutoFillBackground(true);
  but->setPalette(palette);
  but->setFont(font);
  but->setMinimumSize(250, 42);
  but->setMaximumSize(250, 42);
  // but->setObjectName(login);                                                                                  
  but->setStyleSheet("text-align: middle");
  // connect(but, SIGNAL(clicked()), this, SLOT(contactClick()));                                                

  QHBoxLayout *layout = new QHBoxLayout();
  layout->addWidget(but);
  layout->alignment();
  QWidget *widget = new QWidget();
  widget->setLayout(layout);
  item->setSizeHint(widget->sizeHint());

  ui->_listContact->setItemWidget(item, widget);

}

void    Home::threadCall()
{
  float *buffer;
  unsigned char *tmp;
  static bool isOk = false;

  // std::cout << "egergergereé" << std::endl;                                                                   
  //  while (1) {                                                                                                
  id = srv->recvFromSocket(); //premier recu, socket settée sur id1                                              
  if (isOk == false) {
    sound.startStream();
    isOk = true;
  }
  // std::cout << "LEN RECUE" << srv->get_filled() << std::endl;                                                 
  sound.writeStream(encode.decodeFrame((unsigned char *)srv->get_buffer(), 480), encode.getBytesDecode());
  if (!(sound.readStream()))
    std::cerr << "Error on writeStream()" << std::endl;
  buffer = sound.getRecordedSamples();
  tmp = encode.encodeFrame(buffer, 480);
  srv->sendToSocket(id, tmp, encode.getEncodedDataSize()); // revoir à id1                                       
  (void)buffer;
  (void)tmp;
  //  }                                                                                                          
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
  //   sound.w;riteStream(buffer, 480);                                                                          
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


void    Home::callContact()
{
  // clt = new Network(AF_INET, SOCK_DGRAM, "UDP", 1106);                                                        
  // id = clt->connectToSocket(SERV_ADDR_IP, "2000"); //host port                                                
  // if (!sound.initializePA())                                                                                  
  //   std::cerr << "Error on InitPa()" << std::endl;                                                            
  // if (!(sound.initializeInput()))                                                                             
  //   std::cerr << "Error on initParams()" << std::endl;                                                        
  // if (!(sound.initializeOutput()))                                                                            
  //   std::cerr << "Error on initParams()" << std::endl;                                                        
  // sound.openStream();                                                                                         
  // sound.startStream();                                                                                        
  // encode.opusEncoderCreate();                                                                                 
  // encode.opusDecoderCreate();                                                                                 

  /*_udp = new Network(AF_INET, SOCK_DGRAM, "UDP", 65000);                                                       
    _udp->connectToSocket(SERV_ADDR_IP, "2000");*/
  connect(timer, SIGNAL(timeout()), this, SLOT(recvFrameFrom()));
  timer->start();
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
  connect((ThreadCom *)ptr, SIGNAL(s_changeNick(std::vector<const char *>, std::vector<int>)), this, SLOT(setNick(std::vector<const char *>, std::vector<int>)));
  connect((ThreadCom *)ptr, SIGNAL(s_changeStatus(std::vector<const char *>, std::vector<int>)), this, SLOT(setStatus(std::vector<const char *>, std::vector<int>)));
  connect((ThreadCom *)ptr, SIGNAL(s_changeBirth(std::vector<const char *>, std::vector<int>)), this, SLOT(setBirth(std::vector<const char *>, std::vector<int>)));
  connect((ThreadCom *)ptr, SIGNAL(s_contactModule(std::vector<const char *>, std::vector<int>)), this, SLOT(setModule(std::vector<const char *>, std::vector<int>)));
  connect((ThreadCom *)ptr, SIGNAL(s_changeSurname(std::vector<const char *>, std::vector<int>)), this, SLOT(setSurname(std::vector<const char *>, std::vector<int>)));
  connect((ThreadCom *)ptr, SIGNAL(s_changeName(std::vector<const char *>, std::vector<int>)), this, SLOT(setName(std::vector<const char *>, std::vector<int>)));
  connect((ThreadCom *)ptr, SIGNAL(s_changeAddress(std::vector<const char *>, std::vector<int>)), this, SLOT(setAdress(std::vector<const char *>, std::vector<int>)));
  connect((ThreadCom *)ptr, SIGNAL(s_changePhone(std::vector<const char *>, std::vector<int>)), this, SLOT(setPhone(std::vector<const char *>, std::vector<int>)));
  connect((ThreadCom *)ptr, SIGNAL(s_addAnswer(std::vector<const char *>, std::vector<int>)), this, SLOT(setAddAnswer(std::vector<const char *>, std::vector<int>)));
  connect((ThreadCom *)ptr, SIGNAL(s_removeRequest(std::vector<const char *>, std::vector<int>)), this, SLOT(setRemoveRequest(std::vector<const char *>, std::vector<int>)));
  connect((ThreadCom *)ptr, SIGNAL(s_removeAnswer(std::vector<const char *>, std::vector<int>)), this, SLOT(setRemoveAnswer(std::vector<const char *>, std::vector<int>)));
  connect((ThreadCom *)ptr, SIGNAL(s_requestCall(std::vector<const char *>, std::vector<int>)), this, SLOT(setCallRequest(std::vector<const char *>, std::vector<int>)));
  connect((ThreadCom *)ptr, SIGNAL(s_callAnswer(std::vector<const char *>, std::vector<int>)), this, SLOT(setCallAnswer(std::vector<const char *>, std::vector<int>)));
}


void		Home::setRemoveRequest(std::vector<const char *> value, std::vector<int> id)
{

}

void		Home::setRemoveAnswer(std::vector<const char *> value, std::vector<int> id)
{

}

void		Home::setCallRequest(std::vector<const char *> value, std::vector<int> id)
{

}

void		Home::setCallAnswer(std::vector<const char *> value, std::vector<int> id)
{

}

void		Home::setNick(std::vector<const char *> value, std::vector<int> id)
{
	std::map<int, UserInfo *>::iterator it;
	if ((it = _musers.find(id[0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		info->set_id(id[0]);
		info->set_nickname(value[0]);
		_musers[id[0]] = info;
	}
	else {
		UserInfo *tmp = _musers[id[0]];
		tmp->set_nickname(value[0]);
	}
}

void		Home::setStatus(std::vector<const char *> value, std::vector<int> id)
{
	std::map<int, UserInfo *>::iterator it;
	if ((it = _musers.find(id[0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		info->set_id(id[0]);
		info->set_status(value[0][0]);
		_musers[id[0]] = info;
	}
	else {
		UserInfo *tmp = _musers[id[0]];
		tmp->set_status(value[0][0]);
	}
}

void		Home::setBirth(std::vector<const char *> value, std::vector<int> id)
{
	std::map<int, UserInfo *>::iterator it;
	if ((it = _musers.find(id[0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		info->set_id(id[0]);
		info->set_birth(value[0]);
		_musers[id[0]] = info;
	}
	else {
		UserInfo *tmp = _musers[id[0]];
		tmp->set_birth(value[0]);
	}
}

void		Home::setModule(std::vector<const char *> value, std::vector<int> id)
{
	std::map<int, UserInfo *>::iterator it;
	if ((it = _musers.find(id[0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		info->set_id(id[0]);
		info->set_module(value[0][0]);
		_musers[id[0]] = info;
	}
	else {
		UserInfo *tmp = _musers[id[0]];
		tmp->set_module(value[0][0]);
	}
}

void		Home::setSurname(std::vector<const char *> value, std::vector<int> id)
{
	std::map<int, UserInfo *>::iterator it;
	if ((it = _musers.find(id[0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		info->set_id(id[0]);
		info->set_surname(value[0]);
		_musers[id[0]] = info;
	}
	else {
		UserInfo *tmp = _musers[id[0]];
		tmp->set_surname(value[0]);
	}
}

void		Home::setName(std::vector<const char *> value, std::vector<int> id)
{
	std::map<int, UserInfo *>::iterator it;
	if ((it = _musers.find(id[0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		info->set_id(id[0]);
		info->set_name(value[0]);
		_musers[id[0]] = info;
	}
	else {
		UserInfo *tmp = _musers[id[0]];
		tmp->set_name(value[0]);
	}
}

void		Home::setAdress(std::vector<const char *> value, std::vector<int> id)
{
	std::map<int, UserInfo *>::iterator it;
	if ((it = _musers.find(id[0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		info->set_id(id[0]);
		info->set_adress(value[0]);
		_musers[id[0]] = info;
	}
	else {
		UserInfo *tmp = _musers[id[0]];
		tmp->set_adress(value[0]);
	}
}

void		Home::setPhone(std::vector<const char *> value, std::vector<int> id)
{
	std::map<int, UserInfo *>::iterator it;
	if ((it = _musers.find(id[0])) == _musers.end()) {
		UserInfo *info = new UserInfo;
		info->set_id(id[0]);
		info->set_phone(value[0]);
		_musers[id[0]] = info;
	}
	else {
		UserInfo *tmp = _musers[id[0]];
		tmp->set_phone(value[0]);
	}
}

void		Home::setAddAnswer(std::vector<const char *> value, std::vector<int> id)
{

}
