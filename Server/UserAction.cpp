/***********************************************************************
 * Module:  UserAction.cpp
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 10:55:09 AM
 * Purpose: Implementation of the class UserAction
 ***********************************************************************/

#include "User.hh"
#include "Server.hh"

void User::authAnswer(char ret_val) {
  IPacketInfo	*packet_info;

  packet_info = new PacketInfo();
  packet_info->setCmd(3);
  packet_info->getChars().push_back(&ret_val);
  _server->pushToSend(_idSocket, _server->get_parser()->encode(packet_info));
  delete (packet_info);
  if (ret_val == 0)
    connectContactLoop();
}

void User::connectContactLoop(void) {
  std::vector<int>	id_clients;
  std::vector<int>::iterator	_clients;
  std::map<int, User *>::iterator it;

  contactLoop(_idSocket);
  id_clients = _server->get_xmlParser()->getClients(_commandsValue->getFilename(_login, -1));
  _clients = id_clients.begin();
  while (_clients != id_clients.end())
    {
      if ((it = _server->get_users().find(*_clients)) != _server->get_users().end()) // to check
	contactLoop(it->second->get_idSocket());
      _clients++;
    }
}

void User::contactLoop(int id_socket) {
  contactCmd(12, _nickname, id_socket);
  contactCmd(13, (std::string)&_status, id_socket);
  contactCmd(14, _birth, id_socket);
  contactCmd(15, (std::string)&_module, id_socket);
  contactCmd(16, _surname, id_socket);
  contactCmd(17, _name, id_socket);
  contactCmd(18, _address, id_socket);
  contactCmd(19, _phone, id_socket);
}

void	User::contactCmd(int cmd, const std::string val, int id_socket)
{
  IPacketInfo	*packet_info;

  packet_info = new PacketInfo();
  packet_info->setCmd(cmd);
  packet_info->getChars().push_back(val.c_str());
  _server->pushToSend(_idSocket, _server->get_parser()->encode(packet_info));
  delete (packet_info);
}
 
void User::removeAnswer(char &) {
  
}

void User::removeRequest(int) {

}

void User::addAnswer(char) {

}

/*
bool User::startCall(void)
{
   // TODO : implement
}

bool User::endCall(void)
{
   // TODO : implement
}
*/
void User::isConnected(void) {
  _connected = true;
}

void User::isDisconnected(void) {
  _connected = false;
}

bool User::getConnected(void) const {
  return (_connected);
}
