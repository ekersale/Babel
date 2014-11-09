/***********************************************************************
 * Module:  Client.h
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 6:31:06 PM
 * Purpose: Declaration of the class Client
 ***********************************************************************/

#if !defined(__Server_User_hh)
#define __Server_User_hh

#include <XMLParser.h>
#include "UserAction.hh"
#include "UserInfo.hh"
#include "SCommandsValue.hh"
#include "Parser.hh"

//for the 2 other User*.hh
#include <string>

class User : public UserAction, public UserInfo, public SCommandsValue
{
public:
   void print_error(void) const;
  int get_idSocket(void) const;
   bool get_activeChat(void) const;
   char get_activeModule(void) const;
  void set_idSocket(int _idSocket); //LOL
   void set_activeChat(bool new_activeChat);
   void set_activeModule(char new_activeModule);
   User();
User(const int &idSocket, int tmp_id, XMLParser *&xmlParser);
   User(const User& oldUser);
   ~User();

protected:
private:
  int _idSocket;
   bool _activeChat;
   char _activeModule;
  XMLParser * _xmlParser;
};

#endif
