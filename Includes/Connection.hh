#ifndef CONNECTION_H
#define CONNECTION_H

#include    "IGui.hh"

#ifdef		_WIN32
#include    <QtWidgets/QMainWindow>
#include    <QtWidgets/QMessageBox>
#include	<QtCore/QString>
#include	<QtCore/QTimer>
#include	<QtCore/QThread>
#else
#include    <QMainWindow>
#include    <QMessageBox>
#include	<QString>
#include	<QTimer>
#include	<QThread>
#endif

#include "ThreadCom.hh"
#include "Parser.hh"

namespace Ui {
class Connection;
}

class Connection : public QMainWindow, public IGui
{
  Q_OBJECT

  QThread *thread;
public:
  explicit Connection(QWidget *parent = 0);
  ~Connection();
  bool    init();
  void    load();
  void    destroy();

private slots:
  void    connection();
  void    subscribe();
  void	boxError(QString);
  void	handleAuth(void *, void *);
  
private:
  Ui::Connection *ui;
  void *ptr;
  QTimer *timer;
  Network	*network;
  Parser	*parser;
  bool _allowOpen;
  bool _catchwindow;
};

#endif // CONNECTION_H
