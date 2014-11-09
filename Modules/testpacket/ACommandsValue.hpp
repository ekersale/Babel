#ifndef ACOMMANDSVALUE_HH_
#define ACOMMANDSVALUE_HH_

#include "PacketInfo.hh"
#include <map>
#include <iostream>

class SCommandsValue;
typedef void (SCommandsValue::* ptrCmdValue)(std::vector<char *>, std::vector<int>);

class ACommandsValue
{
public:
  ACommandsValue() {};
  virtual ~ACommandsValue() {};
  virtual void connect(std::vector<char *>, std::vector<int>) {};
  virtual void subscribe(std::vector<char *>, std::vector<int>) {};
  virtual void authAnswer(std::vector<char *>, std::vector<int>) {};
  virtual void nick(std::vector<char *>, std::vector<int>) {};
  virtual void status(std::vector<char *>, std::vector<int>) {};
  virtual void module(std::vector<char *>, std::vector<int>) {};
  virtual void birth(std::vector<char *>, std::vector<int>) {};
  virtual void surname(std::vector<char *>, std::vector<int>) {};
  virtual void name(std::vector<char *>, std::vector<int>) {};
  virtual void address(std::vector<char *>, std::vector<int>) {};
  virtual void phone(std::vector<char *>, std::vector<int>) {};
  virtual void contactNick(std::vector<char *>, std::vector<int>) {};
  virtual void contactStatus(std::vector<char *>, std::vector<int>) {};
  virtual void contactBirth(std::vector<char *>, std::vector<int>) {};
  virtual void contactModule(std::vector<char *>, std::vector<int>) {};
  virtual void contactSurname(std::vector<char *>, std::vector<int>) {};
  virtual void contactName(std::vector<char *>, std::vector<int>) {};
  virtual void contactAddress(std::vector<char *>, std::vector<int>) {};
  virtual void contactPhone(std::vector<char *>, std::vector<int>) {};
  virtual void addRequest(std::vector<char *>, std::vector<int>) {};
  virtual void addAnswer(std::vector<char *>, std::vector<int>) {};
  virtual void removeRequest(std::vector<char *>, std::vector<int>) {};
  virtual void removeAnswer(std::vector<char *>, std::vector<int>) {};
  virtual void call(std::vector<char *>, std::vector<int>) {};
  virtual void requestCall(std::vector<char *>, std::vector<int>) {};
  virtual void requestAnswer(std::vector<char *>, std::vector<int>) {};
  virtual void callAnswer(std::vector<char *>, std::vector<int>) {};
  virtual int  cmdVal(PacketInfo *) = 0;
protected:
  std::map<char, ptrCmdValue> methodPtr;
private:
};

#endif /* ACOMMANDSVALUE_HH_ */
