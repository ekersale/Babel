#ifndef SUBSCRIBE_H
#define SUBSCRIBE_H

#include    "IGui.hh"

#ifdef		_WIN32
#include	<QtWidgets/QWidget>

#else
#include	<QWidget>

#endif

#include	"ThreadCom.hh"
#include	"Parser.hh"

namespace Ui {
class Subscribe;
}

class Subscribe : public QWidget, public IGui
{

    Q_OBJECT

  QThread	*thread;
public:
    explicit Subscribe(QWidget *parent = 0);
  ~Subscribe();
  bool			init();
  void			load();
  void			destroy();
  void			setThread();
private slots:
  void			toSubscribe();
  // void			boxError(QString);
  void			handleSubscribe(void *, void *);
 
private:
  Ui::Subscribe		*ui;
  Network		*_net;
  Parser		*_parser;
  void			*_ptr;
  QTimer		*_timer;
  bool			_allowOpen;
};

#endif // SUBSCRIBE_H
