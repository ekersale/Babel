/***********************************************************************
 * Module:  Client.h
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 6:31:06 PM
 * Purpose: Declaration of the class Client
 ***********************************************************************/

#if !defined(__Server_Client_hh)
#define __Server_Client_hh

#include "ClientAction.hh"
#include "ClientInfo.hh"
#include "Parser.hh"

//for the 2 other Client*.hh
#include <string>

class Client : public ClientAction, public ClientInfo
{
public:
   void print_error(void) const;
  IParser * get_parser(void) const;
  int get_idSocket(void) const;
   bool get_activeChat(void) const;
   char get_activeModule(void) const;
  void set_parser(IParser* new_parser);
  void set_idSocket(int _idSocket); //LOL
   void set_activeChat(bool new_activeChat);
   void set_activeModule(char new_activeModule);
   Client();
   Client(const Client& oldClient);
   ~Client();

protected:
private:
  IParser *_parser;
  int _idSocket;
   bool _activeChat;
   char _activeModule;


};

#endif
