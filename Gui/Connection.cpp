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
  IPacketInfo	*packet_info;
  
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
      if ((network->sendSocket(1, (void *)"test", 5) == false))
	{
	  std::cerr << "Fail with Sendsocket " << std::endl;
	  return;
	}
      
    }
  
  
   
   
}

void Connection::handleAuth(std::vector<const char *> tableauCmd, std::vector<int>tableauParams)
{
  if ((tableauCmd.size()) > 0)  
    std::cout << "Tableau contient quelque chose " << std::endl;
  // if (auth -> accepted)
  Home *page = new Home();
  page->show();
  this->hide();
  //else
  //display error message
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
