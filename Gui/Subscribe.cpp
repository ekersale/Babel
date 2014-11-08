//#include    "IGui.h"
#include    "../Includes/Subscribe.hh"
#include    "../Includes/Connection.hh"

#include   <QCryptographicHash>
#include    <iostream>

#include "ui_Subscribe.h"

Subscribe::Subscribe(QWidget *parent) : QWidget(parent), ui(new Ui::Subscribe)
{
  init();
}

Subscribe::~Subscribe()
{
  delete ui;
}

void    Subscribe::init()
{
    setFixedSize(1080, 929);
    load();
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

    Connection *page = new Connection;
    page->show();
    this->hide();
}
