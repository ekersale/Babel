#include "CCommandsValue.hh"
#ifdef _WIN32
#else
#include "dirent.h"
#endif

CCommandsValue::CCommandsValue()
{
  methodPtr[3] = &ACommandsValue::authAnswer;
  methodPtr[12] = &ACommandsValue::contactNick;
  methodPtr[13] = &ACommandsValue::contactStatus;
  methodPtr[14] = &ACommandsValue::contactBirth;
  methodPtr[15] = &ACommandsValue::contactModule;
  methodPtr[16] = &ACommandsValue::contactSurname;
  methodPtr[17] = &ACommandsValue::contactName;
  methodPtr[18] = &ACommandsValue::contactAddress;
  methodPtr[19] = &ACommandsValue::contactPhone;
  methodPtr[21] = &ACommandsValue::addAnswer;
  methodPtr[22] = &ACommandsValue::removeRequest;
  methodPtr[23] = &ACommandsValue::removeAnswer;
  methodPtr[25] = &ACommandsValue::requestCall;
  methodPtr[27] = &ACommandsValue::callAnswer;
}

CCommandsValue::~CCommandsValue() {
}

int		CCommandsValue::cmdVal(IPacketInfo *packet_info)
{
  std::vector<int>	     ints;
  std::vector<const char *>        chars;
  char                       cmd;

  ints = packet_info->getInts();
  chars = packet_info->getChars();
  cmd = packet_info->getCmd();
  if (methodPtr.find(cmd) != methodPtr.end())
    (this->*methodPtr[cmd])(chars, ints);
  else
    return (-1);
  return (0);
}

void CCommandsValue::authAnswer(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_authAnswer(vtmp, vids);
}

void CCommandsValue::contactNick(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_changeNick(vtmp, vids);
}

void CCommandsValue::contactStatus(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_changeStatus(vtmp, vids);
}

void CCommandsValue::contactBirth(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_changeBirth(vtmp, vids);
}

void CCommandsValue::contactModule(std::vector<const char *> values, std::vector<int> ids)
{
std::vector<const char *> *vtmp = new std::vector<const char *>;
std::vector<int> *vids = new std::vector<int>;
*vtmp = values;
*vids = ids;
	emit s_contactModule(vtmp, vids);
}

void CCommandsValue::contactSurname(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_changeSurname(vtmp, vids);
}

void CCommandsValue::contactName(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_changeName(vtmp, vids);
}

void CCommandsValue::contactAddress(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_changeAddress(vtmp, vids);
}

void CCommandsValue::contactPhone(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_changePhone(vtmp, vids);
}

void CCommandsValue::addAnswer(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_addAnswer(vtmp, vids);
}

void CCommandsValue::removeRequest(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_removeRequest(vtmp, vids);
}

void CCommandsValue::removeAnswer(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_removeAnswer(vtmp, vids);
}

void CCommandsValue::requestCall(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_requestCall(vtmp, vids);
}

void CCommandsValue::callAnswer(std::vector<const char *> values, std::vector<int> ids)
{
	std::vector<const char *> *vtmp = new std::vector<const char *>;
	std::vector<int> *vids = new std::vector<int>;
	*vtmp = values;
	*vids = ids;
	emit s_callAnswer(vtmp, vids);
}
