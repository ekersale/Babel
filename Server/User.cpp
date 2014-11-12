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

Server	*&User::get_server() {
  return (_server);
}

ACommandsValue *&User::get_commandsValue() {
  return (_commandsValue);
}

char	&User::get_call_module() {
  return (call_module);
}
 
int	&User::get_call_id() {
  return (call_id);
}

char	*&User::get_call_ip() {
  return (call_ip);
}

int	&User::get_call_port() {
  return (call_port);
}

User::User()
{
   _activeChat = false;
}

User::User(const int &idSocket, int tmp_id, Server *server)
{
  _connected = false;
  _idSocket = idSocket;
  _id = tmp_id;
  _server = server;
  _commandsValue = new SCommandsValue(this);
  std::cout << "Id is :: " << _id << "\n";
}

User::User(const User& oldUser) : UserInfo()
{
  _idSocket = oldUser._idSocket;
  _activeChat = oldUser._activeChat;
  _activeModule = oldUser._activeModule;
  _server = oldUser._server;
  _commandsValue = oldUser._commandsValue;
}

User::~User() {
}
