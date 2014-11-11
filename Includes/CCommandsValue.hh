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
	void s_authAnswer(void *, void *);
	void s_changeNick(void *, void *);
	void s_changeStatus(void *, void *);
	void s_changeBirth(void *, void *);
	void s_contactModule(void *, void *);
	void s_changeSurname(void *, void *);
	void s_changeName(void *, void *);
	void s_changeAddress(void *, void *);
	void s_changePhone(void *, void *);
	void s_addAnswer(void *, void *);
	void s_removeRequest(void *, void *);
	void s_removeAnswer(void *, void *);
	void s_requestCall(void *, void *);
	void s_callAnswer(void *, void *);
};

#endif /* SCOMMANDSVALUE_HH_ */
