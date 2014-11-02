#include    "../Includes/IGui.h"
#include    "../Includes/Connection.h"
#include    "../Includes/Subscribe.h"
#include    "../Includes/Home.h"


#include    <iostream>

#include    "ui_Connection.h"

Connection::Connection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Connection)
{
    init();
    //load();
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
}

void    Connection::destroy()
{

}
