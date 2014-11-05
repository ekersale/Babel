/***********************************************************************
 * Module:  User.cpp
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 6:31:06 PM
 * Purpose: Implementation of the class User
 ***********************************************************************/

#include "User.hh"

void User::print_error(void) const
{
   // TODO : implement
}


IParser * User::get_parser(void) const
{
   return _parser;
}

int User::get_idSocket(void) const
{
   return _idSocket;
}

bool User::get_activeChat(void) const
{
   return _activeChat;
}

char User::get_activeModule(void) const
{
   return _activeModule;
}

void User::set_parser(IParser* new_parser)
{
   _parser = new_parser;
}

void User::set_idSocket(int new_idSocket)
{
   _idSocket = new_idSocket;
}

void User::set_activeChat(bool new_activeChat)
{
   _activeChat = new_activeChat;
}

void User::set_activeModule(char new_activeModule)
{
   _activeModule = new_activeModule;
}

User::User()
{
  _parser = NULL;
   _activeChat = false;
}

User::User(IParser *&parser, const int &idSocket, int tmp_id)
{
  _connected = false;
  _parser = parser;
  _idSocket = idSocket;
  _id = tmp_id;
  std::cout << "Id is :: " << _id << "\n";
}

User::User(const User& oldUser)
{
  _parser = oldUser._parser;
  _idSocket = oldUser._idSocket;
  _activeChat = oldUser._activeChat;
  _activeModule = oldUser._activeModule;
}

User::~User()
{
   // TODO : implement
}
