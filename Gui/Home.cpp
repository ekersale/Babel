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

    _video = new OpenCV(); //Initialisatio de la camera

    QLabel::connect(_video, SIGNAL(processedImage(QImage)), this, SLOT(updatePlayerUI(QImage)));
    
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


void	Home::updatePlayerUI(QImage img)
{
  if (!img.isNull())
    {
      ui->_label_Video->setAlignment(Qt::AlignCenter);
      ui->_label_Video->setPixmap(QPixmap::fromImage(img));
      ui->_label_Video->show();
      
      ui->_label_VideoPerso->setAlignment(Qt::AlignCenter);
      ui->_label_VideoPerso->setPixmap(QPixmap::fromImage(img));
      ui->_label_VideoPerso->setScaledContents(true);
      ui->_label_VideoPerso->show();
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

void    Home::invitContact()
{

}

void    Home::callContact()
{

}

void    Home::videoCallContact()
{
  
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
