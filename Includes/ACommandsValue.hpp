#ifndef ACOMMANDSVALUE_HH_
#define ACOMMANDSVALUE_HH_

#include "PacketInfo.hh"
#include <map>
#include <iostream>

class ACommandsValue;
typedef void (ACommandsValue::* ptrCmdValue)(std::vector<const char *>, std::vector<int>);

class ACommandsValue
{
public:
  ACommandsValue() {};
  virtual ~ACommandsValue() {};
  virtual void connect(std::vector<const char *>, std::vector<int>) {};
  virtual void subscribe(std::vector<const char *>, std::vector<int>) {};
  virtual void authAnswer(std::vector<const char *>, std::vector<int>) {};
  virtual void nick(std::vector<const char *>, std::vector<int>) {};
  virtual void status(std::vector<const char *>, std::vector<int>) {};
  virtual void module(std::vector<const char *>, std::vector<int>) {};
  virtual void birth(std::vector<const char *>, std::vector<int>) {};
  virtual void surname(std::vector<const char *>, std::vector<int>) {};
  virtual void name(std::vector<const char *>, std::vector<int>) {};
  virtual void address(std::vector<const char *>, std::vector<int>) {};
  virtual void phone(std::vector<const char *>, std::vector<int>) {};
  virtual void contactNick(std::vector<const char *>, std::vector<int>) {};
  virtual void contactStatus(std::vector<const char *>, std::vector<int>) {};
  virtual void contactBirth(std::vector<const char *>, std::vector<int>) {};
  virtual void contactModule(std::vector<const char *>, std::vector<int>) {};
  virtual void contactSurname(std::vector<const char *>, std::vector<int>) {};
  virtual void contactName(std::vector<const char *>, std::vector<int>) {};
  virtual void contactAddress(std::vector<const char *>, std::vector<int>) {};
  virtual void contactPhone(std::vector<const char *>, std::vector<int>) {};
  virtual void addRequest(std::vector<const char *>, std::vector<int>) {};
  virtual void addAnswer(std::vector<const char *>, std::vector<int>) {};
  virtual void removeRequest(std::vector<const char *>, std::vector<int>) {};
  virtual void removeAnswer(std::vector<const char *>, std::vector<int>) {};
  virtual void call(std::vector<const char *>, std::vector<int>) {};
  virtual void requestCall(std::vector<const char *>, std::vector<int>) {};
  virtual void requestAnswer(std::vector<const char *>, std::vector<int>) {};
  virtual void callAnswer(std::vector<const char *>, std::vector<int>) {};
  virtual int  cmdVal(IPacketInfo *) = 0;
  virtual std::string	getFilename(std::string, int) = 0;
protected:
  std::map<char, ptrCmdValue> methodPtr;
private:
};

#endif /* ACOMMANDSVALUE_HH_ */
