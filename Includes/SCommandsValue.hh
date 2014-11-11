#ifndef SCOMMANDSVALUE_HH_
#define SCOMMANDSVALUE_HH_

#include "PacketInfo.hh"
#include "ACommandsValue.hpp"
#include "XMLParser.hh"
#include <map>
#include <iostream>
#include <sstream>

#ifdef _WIN32
#include <QtCore/QDir>
#else
#include <QDir>
#endif

class User;

class SCommandsValue : public ACommandsValue
{
public:
  SCommandsValue(User *);
  ~SCommandsValue();
  void connect(std::vector<const char *>, std::vector<int>);
  void subscribe(std::vector<const char *>, std::vector<int>);
  //void authAnswer(std::vector<const char *>, std::vector<int>);
  void nick(std::vector<const char *>, std::vector<int>);
  void status(std::vector<const char *>, std::vector<int>);
  void module(std::vector<const char *>, std::vector<int>);
  void birth(std::vector<const char *>, std::vector<int>);
  void surname(std::vector<const char *>, std::vector<int>);
  void name(std::vector<const char *>, std::vector<int>);
  void address(std::vector<const char *>, std::vector<int>);
  void phone(std::vector<const char *>, std::vector<int>);
  //void contactNick(std::vector<const char *>, std::vector<int>);
  //void contactStatus(std::vector<const char *>, std::vector<int>);
  //void contactBirth(std::vector<const char *>, std::vector<int>);
  //void contactModule(std::vector<const char *>, std::vector<int>);
  //void contactSurname(std::vector<const char *>, std::vector<int>);
  //void contactName(std::vector<const char *>, std::vector<int>);
  //void contactAddress(std::vector<const char *>, std::vector<int>);
  //void contactPhone(std::vector<const char *>, std::vector<int>);
  void addRequest(std::vector<const char *>, std::vector<int>);
  //void addAnswer(std::vector<const char *>, std::vector<int>);
  void removeRequest(std::vector<const char *>, std::vector<int>);
  //void removeAnswer(std::vector<const char *>, std::vector<int>);
  void call(std::vector<const char *>, std::vector<int>);
  //void requestCall(std::vector<const char *>, std::vector<int>);
  void requestAnswer(std::vector<const char *>, std::vector<int>);
  //void callAnswer(std::vector<const char *>, std::vector<int>);
  int  cmdVal(IPacketInfo *);
protected:
  XMLParser	* _xmlParser;
  User		*_user;
  std::string	getFilename(std::string, int);
  std::string	getFilenameById(int);
  int	        getIdFromLogin(std::string);
  std::string	intToStdString(int);
};

#endif /* SCOMMANDSVALUE_HH_ */
