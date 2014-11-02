#include "../Includes/Home.h"
#include "ui_Home.h"

#include    <iostream>

Home::Home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    init();
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
    timer = new QTimer(this);

    QObject::connect(ui->_btnClose, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->_btn_Online, SIGNAL(clicked()), this, SLOT(changeOnline()));
    QObject::connect(ui->_btn_Away, SIGNAL(clicked()), this, SLOT(changeAway()));
    QObject::connect(ui->_btn_Busy, SIGNAL(clicked()), this, SLOT(changeBusy()));
    QObject::connect(ui->_btnAddContact, SIGNAL(clicked()), this, SLOT(showNewField()));
    QObject::connect(ui->_btnInviteContact, SIGNAL(clicked()), this, SLOT(invitContact()));
    QObject::connect(ui->_btnMicro, SIGNAL(clicked()), this, SLOT(callContact()));
    QObject::connect(ui->_btnCam, SIGNAL(clicked()), this, SLOT(videoCallContact()));
    QObject::connect(ui->_btnHangUp, SIGNAL(clicked()), this, SLOT(hangHup()));
    QObject::connect(ui->_line_addContact,SIGNAL(returnPressed()), this,SLOT(addContact()));

    defineStatus(this->_status);
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

    /*QPixmap *pixmap;
    QPalette palette;

    switch (state)
    {
    case 1:
        pixmap = new QPixmap("../Images/BabelHD_0001s_0005s_0002_status.png");
        break;
    case 2:
        pixmap = new QPixmap("../Images/BabelHD_0001s_0003s_0000_status.png");
        break;
    case 3:
        pixmap = new QPixmap("../Images/BabelHD_0001s_0000s_0000_status.png");
        break;
    case 4 :
        pixmap = new QPixmap("../Images/BabelHD_0001s_0002s_0000_status.png");
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
    but->setObjectName(login);
    but->setStyleSheet("text-align: middle");
    connect(but, SIGNAL(clicked()), this, SLOT(contactClick()));
    */
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(but);
    layout->alignment();
    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    item->setSizeHint(widget->sizeHint());

    ui->_listContact->setItemWidget(item, widget);

}

void	Home::threadCall()
{
  float *buffer;
  unsigned char *tmp;
  static bool isOk = false;

  std::cout << "egergergereé" << std::endl;
  //  while (1) {
  id = srv->recvFromSocket(); //premier recu, socket settée sur id1
  if (isOk == false) {
    sound.startStream();
    isOk = true;
  }
  sound.writeStream(encode.decodeFrame((unsigned char *)srv->get_buffer(), 480), encode.getBytesDecode());
  if (!(sound.readStream()))
    std::cerr << "Error on writeStream()" << std::endl;
  buffer = sound.getRecordedSamples();
  tmp = encode.encodeFrame(buffer, 480);
  int i;
  for (i = 0; tmp[i]; i++);
  srv->sendToSocket(id, tmp, i); // revoir à id1
  (void)buffer;
  (void)tmp;
 //  }
}

void    Home::invitContact()
{
  srv = new UNetwork(AF_INET, SOCK_DGRAM, "UDP");
  srv->bindSocket("2000");
  if (!sound.initializePA())
    std::cerr << "Error on InitPa()" << std::endl;
  if (!(sound.initializeInput()))
    std::cerr << "Error on initParams()" << std::endl;
  if (!(sound.initializeOutput()))
    std::cerr << "Error on initParams()" << std::endl;
  sound.openStream();
  encode.opusEncoderCreate();
  encode.opusDecoderCreate();
  connect(timer, SIGNAL(timeout()), this, SLOT(threadCall()));
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
  //   // sound.writeStream(encode.decodeFrame((unsigned char *)srv->get_buffer(), 480), encode.getBytesDecode());
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
  int i;
  for (i = 0; tmp[i]; i++);
  clt->sendToSocket(id, tmp, i); //envoie à id2 séttée sur une socket par connect
  clt->recvFromSocket();// recoit de n'importe qui qui connait
  sound.writeStream(encode.decodeFrame((unsigned char *)clt->get_buffer(), 480), encode.getBytesDecode());
  (void)buffer;
  (void)tmp;
}

void    Home::callContact()
{
  float *buffer;
  unsigned char *tmp;

  clt = new UNetwork(AF_INET, SOCK_DGRAM, "UDP", 480);
  id = clt->connectToSocket(SERV_ADDR_IP, "2000"); //host port   

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
  connect(timer, SIGNAL(timeout()), this, SLOT(threadReceive()));
  timer->start();
}

void    Home::videoCallContact()
{

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

e_type  Home::getStatus()
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
    this->setStatus(newStatus);
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
