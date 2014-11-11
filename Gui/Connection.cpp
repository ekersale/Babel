#include	"IGui.hh"
#include	"Connection.hh"
#include	"Subscribe.hh"
#include	"Home.hh"
#include	"Network.hh"

#ifdef		_WIN32
#include	<QtCore/QCryptographicHash>
#else
#include	<QCryptographicHash>
#endif

#include	"Packet.hh"
#include	 <iostream>

#include    "ui_Connection.h"

Connection::Connection(QWidget *parent) : QMainWindow(parent), ui(new Ui::Connection)
{
  _allowOpen = true;
  thread = new QThread;
  ThreadCom *_com;
  _com = new ThreadCom();
  ptr = _com;
  this->network = ((ThreadCom *)ptr)->getNetwork();
  this->parser = ((ThreadCom *)ptr)->getParser();

  connect(_com, SIGNAL(displayError(QString)), this, SLOT(boxError(QString)));
  connect(_com, SIGNAL(s_authAnswer(std::vector<const char *>, std::vector<int>)), this,
	  SLOT(handleAuth(std::vector<const char *>, std::vector<int>)));
  
  ((ThreadCom *)ptr)->connectServer();
  _com->moveToThread(thread);
  connect(thread, SIGNAL(started()), _com, SLOT(run()));
  thread->connect(_com, SIGNAL(finished()), SLOT(quit()));
  thread->start();
  init();
}

Connection::~Connection()
{
  delete ui;
}


void Connection::connection()
{
  IPacketInfo	*packet_info = new PacketInfo();
  
  char *pd1 = (char *)malloc(2);
  char *pd2 = (char *)malloc(2);
  char *sd1;
  char *sd2;
  
  sd1 = strdup(ui->_lineLogin->text().toStdString().c_str());
  sd2 = strdup(ui->_linePassword->text().toStdString().c_str());
  pd1[0] = 2;
  pd2[0] = 3;

  packet_info->setCmd(1);
  packet_info->getChars().push_back(sd1);
  packet_info->getChars().push_back(sd2);
  packet_info->getChars().push_back(pd1);
  packet_info->getChars().push_back(pd2);

  if (ui->_lineLogin->text().isEmpty())
    {
      QMessageBox::critical(this,"Warning", "You must enter a valid login");
      return;
    }
  else if (ui->_linePassword->text().isEmpty())
    {
      QMessageBox::critical(this,"Warning", "You must enter a valid password");
      return;
    }
  else
    {
      Packet	*packet;
      packet = (Packet *)parser->encode(packet_info);
      

      std::stringbuf sz;
      sz >> packet;
      //on send sz.str() via le rézo maggle
      //      std::cout << "sz: " << sz.str() << std::endl;

      if ((network->sendSocket(1, (void *)sz.str().c_str(), 65) == false))
	std::cout << "Error Send\n";
      //sinon on fait un receive et on recevra un buffer
      //pour l'exemple le buffer est celui du dessus
      //std::stringbuf usz(sz.str());
      //Packet	*packet2 = new Packet();
      //on insère alors le le tout dans le paquet comme le dit l'expression
      //usz << packet2;
      // //on teste_z notre gros paquet rempli de foutre
      //std::cout << "usz: " << usz.str() << std::endl; 
      
      free(pd1); 
      free(pd2);
      free(sd1);
      free(sd2);
      delete(packet);
      delete(packet_info);
    } 
}

void Connection::handleAuth(std::vector<const char *>tableCmd, std::vector<int>tableParams)
{
  Home		*page;
  
  std::cout << "On recoit quelque chose" << std::endl;
  static_cast<void>(tableCmd);
  static_cast<void>(tableParams);
  // if ((char)tableCmd.at(0)[0] == 1)
  //   {
  //     QMessageBox::critical(this,"Warning", "Bad login");
  //     return;
  //   }
  // else if ((char)tableCmd.at(0)[0] == 2)
  //   {
  //     QMessageBox::critical(this,"Warning", "Bad login");
  //     return;
  //   }
  // else
  //   {
     
      page = new Home;
      page->setThread(ptr);
      page->show();
      this->hide(); 
    // }
}

void    Connection::subscribe()
{
    Subscribe *page = new Subscribe;
    
    page->show();
    this->hide();
}

bool    Connection::init()
{
  if (_allowOpen == false)
    return (false);
  else {
    setFixedSize(1080, 929);
    load();
    return (true);
  }
  return (true);
}

void    Connection::load()
{
    ui->setupUi(this);
    this->show();

    QObject::connect(ui->_btnConnection, SIGNAL(clicked()), this, SLOT(connection()));
    QObject::connect(ui->_btnSubscribe, SIGNAL(clicked()), this, SLOT(subscribe()));
    QObject::connect(ui->_lineLogin, SIGNAL(returnPressed()), this, SLOT(connection()));
    QObject::connect(ui->_linePassword, SIGNAL(returnPressed()), this, SLOT(connection()));
}

void	Connection::boxError(QString msg)
{
	QMessageBox::critical(this, "Error", msg);
	_allowOpen = false;
}

void    Connection::destroy()
{

}
