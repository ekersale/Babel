#ifndef COMMANDSVALUE_HH_
#define COMMANDSVALUE_HH_

#include "PacketInfo.hh"
#include <map>
#include <iostream>

class CommandsValue;

typedef void (CommandsValue::* ptrCmdValue)(std::vector<char *>, std::vector<int>);

class CommandsValue {
public:
  CommandsValue();
  ~CommandsValue();
  void setConnect(std::vector<char *>, std::vector<int>);
  void setSubscribe(std::vector<char *>, std::vector<int>);
  void setAuthAnswer(std::vector<char *>, std::vector<int>);
  void setNick(std::vector<char *>, std::vector<int>);
  void setStatus(std::vector<char *>, std::vector<int>);
  void setModule(std::vector<char *>, std::vector<int>);
  void setBirth(std::vector<char *>, std::vector<int>);
  void setSurname(std::vector<char *>, std::vector<int>);
  void setName(std::vector<char *>, std::vector<int>);
  void setAddress(std::vector<char *>, std::vector<int>);
  void setPhone(std::vector<char *>, std::vector<int>);
  void setContactNick(std::vector<char *>, std::vector<int>);
  void setContactStatus(std::vector<char *>, std::vector<int>);
  void setContactBirth(std::vector<char *>, std::vector<int>);
  void setContactModule(std::vector<char *>, std::vector<int>);
  void setContactSurname(std::vector<char *>, std::vector<int>);
  void setContactName(std::vector<char *>, std::vector<int>);
  void setContactAddress(std::vector<char *>, std::vector<int>);
  void setContactPhone(std::vector<char *>, std::vector<int>);
  void setAddRequest(std::vector<char *>, std::vector<int>);
  void setAddAnswer(std::vector<char *>, std::vector<int>);
  void setRemoveRequest(std::vector<char *>, std::vector<int>);
  void setRemoveAnswer(std::vector<char *>, std::vector<int>);
  void setCall(std::vector<char *>, std::vector<int>);
  void setRequestCall(std::vector<char *>, std::vector<int>);
  void setRequestAnswer(std::vector<char *>, std::vector<int>);
  void setCallAnswer(std::vector<char *>, std::vector<int>);
  int  setCommandsValue(PacketInfo *packet);
private:
  std::map<char, ptrCmdValue> methodPtr;
};

#endif /* COMMANDSVALUE_HH_ */
