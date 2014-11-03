/***********************************************************************
 * Module:  Client.cpp
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 6:31:06 PM
 * Purpose: Implementation of the class Client
 ***********************************************************************/

#include "Client.hh"

void Client::print_error(void) const
{
   // TODO : implement
}


IParser * Client::get_parser(void) const
{
   return _parser;
}

int Client::get_idSocket(void) const
{
   return _idSocket;
}

bool Client::get_activeChat(void) const
{
   return _activeChat;
}

char Client::get_activeModule(void) const
{
   return _activeModule;
}

void Client::set_parser(IParser* new_parser)
{
   _parser = new_parser;
}

void Client::set_idSocket(int new_idSocket)
{
   _idSocket = new_idSocket;
}

void Client::set_activeChat(bool new_activeChat)
{
   _activeChat = new_activeChat;
}

void Client::set_activeModule(char new_activeModule)
{
   _activeModule = new_activeModule;
}

Client::Client()
{
  _parser = NULL;
   _activeChat = false;
}

Client::Client(const Client& oldClient)
{
  _parser = oldClient._parser;
  _idSocket = oldClient._idSocket;
   _activeChat = oldClient._activeChat;
   _activeModule = oldClient._activeModule;
}

Client::~Client()
{
   // TODO : implement
}
