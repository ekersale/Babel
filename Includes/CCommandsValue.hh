#ifndef SCOMMANDSVALUE_HH_
#define SCOMMANDSVALUE_HH_

#include "ACommandsValue.hpp"
#include "PacketInfo.hh"
#ifdef _WIN32
#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#else
#include <QWidget>
#include <QThread>
#include <QObject>
#endif

class CCommandsValue :  public QObject, public ACommandsValue
{
  Q_OBJECT

public:
	CCommandsValue();
	~CCommandsValue();
	
	void authAnswer(std::vector<const char *>, std::vector<int>);
	void contactNick(std::vector<const char *>, std::vector<int>);
	void contactStatus(std::vector<const char *>, std::vector<int>);
	void contactBirth(std::vector<const char *>, std::vector<int>);
	void contactModule(std::vector<const char *>, std::vector<int>);
	void contactSurname(std::vector<const char *>, std::vector<int>);
	void contactName(std::vector<const char *>, std::vector<int>);
	void contactAddress(std::vector<const char *>, std::vector<int>);
	void contactPhone(std::vector<const char *>, std::vector<int>);
	void addAnswer(std::vector<const char *>, std::vector<int>);
	void removeRequest(std::vector<const char *>, std::vector<int>);
	void removeAnswer(std::vector<const char *>, std::vector<int>);
	void requestCall(std::vector<const char *>, std::vector<int>);
	void callAnswer(std::vector<const char *>, std::vector<int>);
	int  cmdVal(IPacketInfo *);

signals:
	void s_authAnswer(std::vector<const char *>, std::vector<int>);
	void s_changeNick(std::vector<const char *>, std::vector<int>);
	void s_changeStatus(std::vector<const char *>, std::vector<int>);
	void s_changeBirth(std::vector<const char *>, std::vector<int>);
	void s_contactModule(std::vector<const char *>, std::vector<int>);
	void s_changeSurname(std::vector<const char *>, std::vector<int>);
	void s_changeName(std::vector<const char *>, std::vector<int>);
	void s_changeAddress(std::vector<const char *>, std::vector<int>);
	void s_changePhone(std::vector<const char *>, std::vector<int>);
	void s_addAnswer(std::vector<const char *>, std::vector<int>);
	void s_removeRequest(std::vector<const char *>, std::vector<int>);
	void s_removeAnswer(std::vector<const char *>, std::vector<int>);
	void s_requestCall(std::vector<const char *>, std::vector<int>);
	void s_callAnswer(std::vector<const char *>, std::vector<int>);
};

#endif /* SCOMMANDSVALUE_HH_ */
