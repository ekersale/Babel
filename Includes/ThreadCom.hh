#ifndef _THREAD_COM_HH__
# define _THREAD_COM_HH__

#ifdef _WIN32
#include <QtCore/QTimer>
#include <QtWidgets/QWidget>
#include <QtCore/QObject>
#else
#include <QMessageBox>
#include <QWidget>
#include <QObject>
#endif
#include		"Network.hh"
#include		"Home.hh"
#include		"Subscribe.hh"
#include		"Connection.hh"
#include		"IGui.hh"
#include		"Parser.hh"
#include		"XMLParser.hh"
#include		"Packet.hh"
#include		"CCommandsValue.hh"
#include		"Parser.hh"
#include		"Serialize.hh"

#define			ERROR_CONNECTION	"Failed to join server"
#define			IP_ADDR_SERV		"10.13.253.15"
#define			PORT				"2000"

class ThreadCom : public CCommandsValue
{
  Q_OBJECT

public:
  ThreadCom();
  ~ThreadCom();
  
  bool connectServer();
  Network	*getNetwork() const;
  Parser	*getParser() {return _parser;};
  Serialize	*getSerialize() {return _serialize;};
  XMLParser	*getXMLParser() {return _xmlParser;};
  int	test;
  
signals:
  void displayError(QString);
  void finished();

public slots:
	void run();

private:
	int _socket;
	Network *_network;
	Parser *_parser;
	Serialize *_serialize;
	XMLParser *_xmlParser;
};

#endif
