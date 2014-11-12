
#include	"IGui.hh"
#include	"Network.hh"
#include	"Subscribe.hh"
#include	"Connection.hh"

#ifdef		_WIN32
#include	<QtCore/QCryptographicHash>

#else
#include	<QCryptographicHash>
#endif

#include	<iostream>

#include	"Packet.hh"

#include	"ui_Subscribe.h"

Subscribe::Subscribe(QWidget *parent) : QWidget(parent), ui(new Ui::Subscribe)
{
  thread = new QThread;
  ThreadCom *_com;
  
  _com = new ThreadCom();
  this->_ptr = _com;
  
  this->_net = ((ThreadCom *)_ptr)->getNetwork();
  this->_parser = ((ThreadCom *)_ptr)->getParser();

  connect(_com, SIGNAL(s_authAnswer(void *, void *)), this,
	  SLOT(handleSubscribe(void *, void *)));

  ((ThreadCom *)_ptr)->connectServer();
  
  _com->moveToThread(thread);
  
  connect(thread, SIGNAL(started()), _com, SLOT(run()));

  thread->connect(_com, SIGNAL(finished()), SLOT(quit()));
  thread->start();
  init();
}

Subscribe::~Subscribe()
{
  delete ui;
}

bool		Subscribe::init()
{
  setFixedSize(1080, 929);
  load();
  return (true);
}

void    Subscribe::load()
{
    ui->setupUi(this);
    this->show();
    QObject::connect(ui->_btnSubscribe, SIGNAL(clicked()), this, SLOT(toSubscribe()));
}

void    Subscribe::destroy()
{
    delete ui;
}

void	Subscribe::handleSubscribe(void *cmdptr, void *idptr)
{
  std::vector<const char *> *tableCmd = (std::vector<const char *> *)cmdptr;
  std::vector<int> *vids = (std::vector<int> *)idptr;

  static_cast<void>(vids);
  if (tableCmd->at(0)[0] == 3)
    {
      QMessageBox::critical(this, "Information", "Login is not available");
      return;
    }
  else if (tableCmd->at(0)[0] == 4)
    {
      QMessageBox::critical(this, "Information", "Invalid login");
      return;
    }
  else if (tableCmd->at(0)[0] == 5)
    {
      QMessageBox::critical(this, "Information", "Invalid password");
      return;
    }
  else
    {
      QMessageBox::information(this, "Information", "Inscription réussi");
      Connection              *page;
      
      page = new Connection;
      page->show();
      this->hide();
      //return;
    }
}

void    Subscribe::toSubscribe()
{ 
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
      PacketInfo   *packet_info = new PacketInfo();

      // char *pd1 = (char *)malloc(2);
      char *pd2 = (char *)malloc(2);
      char *sd1;
      char *sd2;

      sd1 = strdup(ui->_lineLogin->text().toStdString().c_str());
      sd2 = strdup(ui->_linePassword->text().toStdString().c_str());
      // pd1[0] = 2;
      pd2[0] = 3;

      packet_info->setCmd(2);
      packet_info->getChars().push_back(sd1);
      packet_info->getChars().push_back(sd2);
      // packet_info->getChars().push_back(pd1);
      packet_info->getChars().push_back(pd2);
    

      Packet    *packet;
      packet = (Packet *)_parser->encode(packet_info);

      std::stringbuf sz;
      sz >> packet;
      //on send sz.str() via le rézo maggle^M
      //      std::cout << "sz: " << sz.str() << std::endl;                                                            
      if ((_net->sendSocket(1, (void *)sz.str().c_str(), 65) == false))
	std::cout << "Error Send" << std::endl;

      // free(pd1);
      free(pd2);
      free(sd1);
      free(sd2);
      delete(packet);
      delete(packet_info);
    }
  
}
