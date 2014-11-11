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
  char		*cpy = new char[1];

  cpy[0] = ret_val;
  packet_info = new PacketInfo();
  packet_info->setCmd(3);
  packet_info->getChars().push_back(cpy);
  std::cout << "id Socket : " << _idSocket << std::endl;
  _server->pushToSend(_idSocket, _server->get_parser()->encode(packet_info));
  delete (packet_info);
  if (ret_val == 0)
    connectContactLoop();
}

void User::connectContactLoop(void) {
  std::vector<int>	id_clients;
  std::vector<int>::iterator	_clients;
  std::map<int, User *>::iterator it;
  int			id;

  contactLoop(this, (id = 0));
  id_clients = _server->get_xmlParser()->getClients(_commandsValue->getFilename(_login));
  _clients = id_clients.begin();
  while (_clients != id_clients.end())
    {
      if ((it = _server->get_users().find(*_clients)) != _server->get_users().end())
	{
	  //j'envoie a mes potes du push
	  contactLoop(this, _id);
	  //je recoie du server les infos de mes potes
	  contactLoop(it->second, _id);
	}
      _clients++;
    }
}

void User::contactLoop(User *_usr, int &my_id) {
  std::string	for_status;
  std::string	for_module;

  for_status[0] = _usr->get_status();
  for_module[0] = _usr->get_module();
  contactCmd(12, _usr->get_nickname(), _usr->get_idSocket(), my_id);
  contactCmd(13, for_status, _usr->get_idSocket(), my_id); //Cond Jump
  contactCmd(14, _usr->get_birth(), _usr->get_idSocket(), my_id);
  contactCmd(15, for_module, _usr->get_idSocket(), my_id); //Cond Jump
  contactCmd(16, _usr->get_surname(), _usr->get_idSocket(), my_id);
  contactCmd(17, _usr->get_name(), _usr->get_idSocket(), my_id);
  contactCmd(18, _usr->get_address(), _usr->get_idSocket(), my_id);
  contactCmd(19, _usr->get_phone(), _usr->get_idSocket(), my_id);
}

void	User::contactCmd(int cmd, const std::string val, int id_socket, int &my_id)
{
  IPacketInfo	*packet_info;

  std::cout << "\tVal de 0 : " << (int)(val[0]) << std::endl;
  std::cout << "\tValue de : " << val << std::endl;
  packet_info = new PacketInfo();
  packet_info->setCmd(cmd);
  packet_info->getChars().push_back(val.c_str());
  packet_info->getInts().push_back(my_id);
  std::cout << "id_socket : " << id_socket << std::endl;
  _server->pushToSend(id_socket, _server->get_parser()->encode(packet_info));
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
