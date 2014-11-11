/***********************************************************************
 * Module:  Client.h
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 6:31:06 PM
 * Purpose: Declaration of the class Client
 ***********************************************************************/

#if !defined(__Server_User_hh)
#define __Server_User_hh

#include "XMLParser.hh"
#include "UserInfo.hh"
#include "SCommandsValue.hh"
#include "Parser.hh"
#include <string>

class Server;

class User : public UserInfo
{
public:
  void print_error(void) const;
  int get_idSocket(void) const;
  bool get_activeChat(void) const;
  char get_activeModule(void) const;
  void set_idSocket(int _idSocket); //LOL
  void set_activeChat(bool new_activeChat);
  void set_activeModule(char new_activeModule);
  Server *&get_server();
  ACommandsValue *&get_commandsValue();

  void authAnswer(char);
  void connectContactLoop(void);
  void contactLoop(User *, User *);
  void contactCmd(int, const std::string, int, int);
  void removeAnswer(char &);
  void removeRequest(int);
  void addAnswer(char);
  /*
   void startCall(void);
   void endCall(void);
  */
  virtual void isConnected(void);
  virtual void isDisconnected(void);
  bool getConnected(void) const;

  User();
  User(const int &idSocket, int tmp_id, Server *server);
  User(const User& oldUser);
  ~User();

protected:
  int _idSocket;
  bool _activeChat;
  char _activeModule;
  Server *_server;
  ACommandsValue *_commandsValue;
  bool		_connected;
private:
};

#endif
