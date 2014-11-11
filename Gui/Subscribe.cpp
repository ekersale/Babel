//#include    "IGui.h"
#include    "../Includes/Subscribe.hh"
#include    "../Includes/Connection.hh"

#ifdef		_WIN32
#include	<QtCore/QCryptographicHash>

#else
#include	<QCryptographicHash>
#endif

#include	<iostream>

#include	"ui_Subscribe.h"

Subscribe::Subscribe(QWidget *parent) : QWidget(parent), ui(new Ui::Subscribe)
{
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

void    Subscribe::toSubscribe()
{
   IPacketInfo   *packet_info = new PacketInfo();

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
      // Packet    *packet;
      // packet = (Packet *)parser->encode(packet_info);

      // std::stringbuf sz;
      // sz >> packet;

      
      // if ((network->sendSocket(1, (void *)sz.str().c_str(), 65) == false))
      // 	std::cout << "Error Send\n";
      
      // Connection *page = new Connection;
      // page->show();
      // this->hide();
      
      // delete(packet);
      // delete(packet_info);
    }

}
