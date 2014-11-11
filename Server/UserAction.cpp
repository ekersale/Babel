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
  std::vector<int>	all_clients;
  std::vector<int>::iterator	it_clients;
  std::map<int, User *>::iterator it_users;
  int			id;

  contactLoop(this, this);
  all_clients = _server->get_xmlParser()->getClients(_commandsValue->getFilename(_login));
  it_clients = all_clients.begin();
  while (it_clients != all_clients.end())
    {
      if ((it_users = _server->get_users().find(*it_clients)) != _server->get_users().end())
	{
	  //j'envoie a mes potes du push
	  contactLoop(this, it_users->second);
	  //je recoie du server les infos de mes potes
	  contactLoop(it_users->second, this);
	}
      it_clients++;
    }
}

void User::contactLoop(User *usr_from, User *usr_to) {
  std::string	for_status;
  std::string	for_module;

  for_status[0] = usr_from->get_status();
  for_module[0] = usr_from->get_module();
  contactCmd(12, usr_from->get_nickname(), usr_from->get_id(), usr_to->get_idSocket());
  contactCmd(13, for_status, usr_from->get_id(), usr_to->get_idSocket()); //Cond Jump
  contactCmd(14, usr_from->get_birth(), usr_from->get_id(), usr_to->get_idSocket());
  contactCmd(15, for_module, usr_from->get_id(), usr_to->get_idSocket()); //Cond Jump
  contactCmd(16, usr_from->get_surname(), usr_from->get_id(), usr_to->get_idSocket());
  contactCmd(17, usr_from->get_name(), usr_from->get_id(), usr_to->get_idSocket());
  contactCmd(18, usr_from->get_address(), usr_from->get_id(), usr_to->get_idSocket());
  contactCmd(19, usr_from->get_phone(), usr_from->get_id(), usr_to->get_idSocket());
}

void	User::contactCmd(int cmd, const std::string val, int id_from, int id_socket)
{
  IPacketInfo	*packet_info;

  std::cout << "\tVal de 0 : " << (int)(val[0]) << std::endl;
  std::cout << "\tValue de : " << val << std::endl;
  packet_info = new PacketInfo();
  packet_info->setCmd(cmd);
  packet_info->getChars().push_back(val.c_str());
  packet_info->getInts().push_back(id_from);
  std::cout << "id_socket : " << id_socket << std::endl;
  _server->pushToSend(id_socket, _server->get_parser()->encode(packet_info));
  delete (packet_info);
}
 
void User::removeAnswer(char &) {
  
}

void User::removeRequest(int) {

}

void User::addAnswer(char ret_val) {
  IPacketInfo	*packet_info;
  char		*cpy = new char[1];

  cpy[0] = ret_val;
  packet_info = new PacketInfo();
  packet_info->setCmd(21);
  packet_info->getChars().push_back(cpy);
  _server->pushToSend(_idSocket, _server->get_parser()->encode(packet_info));
  delete (packet_info);
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
