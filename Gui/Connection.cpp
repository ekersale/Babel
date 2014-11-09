#include    "../Includes/IGui.hh"
#include    "../Includes/Connection.hh"
#include    "../Includes/Subscribe.hh"
#include    "../Includes/Home.hh"

#ifdef		_WIN32
#include	<QCryptographicHash>
#else
#include	<QtCore/QCryptographicHash>
#endif
#include	 <iostream>

#include    "ui_Connection.h"

Connection::Connection(QWidget *parent) : QMainWindow(parent), ui(new Ui::Connection)
{
    init();
}

Connection::~Connection()
{
    delete ui;
}


void Connection::connection()
{
    if (ui->_lineLogin->text().isEmpty())
    {
      QMessageBox::critical(this,"Warning", "You must enter a valid login");
      return;
    }

   if (ui->_linePassword->text().isEmpty())
    {
      QMessageBox::critical(this,"Warning", "You must enter a valid password");
      return;
    }
   
   
   std::string		test;
   QCryptographicHash	md5Generator(QCryptographicHash::Sha1);
   
   md5Generator.addData(ui->_linePassword->text().toStdString().c_str());
   
   //test.append(md5Generator.result());
   test.append(md5Generator.result().toHex());
   
   std::cout  << test << std::endl;
   
   Home *page = new Home;
   page->show();
   this->hide();
}

void    Connection::subscribe()
{
    Subscribe *page = new Subscribe;

    page->show();
    this->hide();
}

void    Connection::init()
{
    setFixedSize(1080, 929);
    load();
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

void    Connection::destroy()
{

}
