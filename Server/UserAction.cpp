/***********************************************************************
 * Module:  UserAction.cpp
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 10:55:09 AM
 * Purpose: Implementation of the class UserAction
 ***********************************************************************/

#include "User.hh"
#include "Server.hh"
#include <stdexcept>

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

  contactLoop(this, this);
  all_clients = _server->get_xmlParser()->getClients(_commandsValue->getFilename(_login));
  //std::cout <<  "\tSize of all_clients " << all_clients.size() << std::endl;
  it_clients = all_clients.begin();
  while (it_clients != all_clients.end())
    {
      /*
      if ((it_users = _server->get_users().find(*it_clients)) != _server->get_users().end())
	{	  
	  //j'envoie a mes potes du push
	  contactLoop(this, it_users->second);
	  //je recoie du server les infos de mes potes
	  contactLoop(it_users->second, this);
	}
      else
	{
      */
	  try
	    {
	      contactOfflineLoop(*it_clients);
	    }
	  catch (std::out_of_range const & exc) {
	    //std::cout << exc.what() << std::endl;
	  }
	  //	}
      it_clients++;
    }
}

void	User::contactOfflineLoop(int id) {
  std::string	filename;
  std::string	for_status;
  std::string	for_module;

  for_status[0] = 1;

  //  if () // pas dans la map de <int, User*>
	//for_module[0] = 1;
  //else //présent dedan
    for_module[0] = 2;
  //std::cout << "\t\tSDQQQQQQQQQQQQQQQQQDQSDQSDQSDQSDQSDQSD\n\n\n";
  filename = _commandsValue->getFilenameById(id);
  contactCmd(12, _server->get_xmlParser()->getNodeValue(filename, "nickname"), id, get_idSocket());
  contactCmd(13, for_status, id, get_idSocket());
  contactCmd(14, _server->get_xmlParser()->getNodeValue(filename, "birth"), id, get_idSocket());
  contactCmd(15, for_module, id, get_idSocket());
  contactCmd(16, _server->get_xmlParser()->getNodeValue(filename, "surname"), id, get_idSocket());
  contactCmd(17, _server->get_xmlParser()->getNodeValue(filename, "name"), id, get_idSocket());
  contactCmd(18, _server->get_xmlParser()->getNodeValue(filename, "address"), id, get_idSocket());
  contactCmd(19, _server->get_xmlParser()->getNodeValue(filename, "phone"), id, get_idSocket());
}

void User::contactLoop(User *usr_from, User *usr_to) {
  std::string	for_status;
  std::string	for_module;
  int		usr_from_id;
  int		usr_to_id_socket;

  //std::cout << "STATUS == " << (int)usr_from->get_status() << " MODULE " << (int)usr_from->get_module() << std::endl;
  for_status[0] = usr_from->get_status();
  for_module[0] = usr_from->get_module();
  //  if (usr_from->get_id() == usr_to->get_id())
  //usr_from_id = 0;
  //else
    usr_from_id = usr_from->get_id();
  usr_to_id_socket = usr_to->get_idSocket();
  contactCmd(12, usr_from->get_nickname(), usr_from_id, usr_to_id_socket);
  contactCmd(13, for_status, usr_from_id, usr_to_id_socket);
  contactCmd(14, usr_from->get_birth(), usr_from_id, usr_to_id_socket);
  contactCmd(15, for_module, usr_from_id, usr_to_id_socket);
  contactCmd(16, usr_from->get_surname(), usr_from_id, usr_to_id_socket);
  contactCmd(17, usr_from->get_name(), usr_from_id, usr_to_id_socket);
  contactCmd(18, usr_from->get_address(), usr_from_id, usr_to_id_socket);
  contactCmd(19, usr_from->get_phone(), usr_from_id, usr_to_id_socket);
}

void	User::contactCmd(int cmd, const std::string val, int id_from, int id_socket)
{
  IPacketInfo	*packet_info;

  //std::cout << "\tVal de 0 : " << (int)(val[0]) << std::endl;
  //std::cout << "\tValue de : " << val << std::endl;
  packet_info = new PacketInfo();
  packet_info->setCmd(cmd);
  packet_info->getChars().push_back(val.c_str());
  packet_info->getInts().push_back(id_from);
  //std::cout << "id_socket : " << id_socket << std::endl;
  _server->pushToSend(id_socket, _server->get_parser()->encode(packet_info));
  delete (packet_info);
}
 
void User::removeAnswer(char ret_val) {
  IPacketInfo	*packet_info;
  char		*cpy = new char[1];

  cpy[0] = ret_val;
  packet_info = new PacketInfo();
  packet_info->setCmd(22);
  packet_info->getChars().push_back(cpy);
  _server->pushToSend(_idSocket, _server->get_parser()->encode(packet_info));
  delete (packet_info);
}

void User::removeRequest(int from_id) {
  IPacketInfo	*packet_info;

  packet_info = new PacketInfo();
  packet_info->setCmd(22);
  packet_info->getInts().push_back(from_id);
  _server->pushToSend(_idSocket, _server->get_parser()->encode(packet_info));
  delete (packet_info);
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

void User::requestCall(char call_module, User *src, User *target) {
  IPacketInfo	*packet_info;
  char	*module = new char[1];
  //  char	*nbr = new char[1];

  module[0] = call_module;
  //nbr[0] = 1;
  packet_info = new PacketInfo();
  packet_info->setCmd(25);
  packet_info->getChars().push_back(module);
  //packet_info->getChars().push_back(nbr);
  packet_info->getInts().push_back(src->get_id());
  std::cout << "\tGet id de src is !!!!! : " << src->get_id() << std::endl;
  packet_info->getChars().push_back(_server->get_network()->get_connected(src->get_idSocket())->get_ip());
  _server->pushToSend(target->get_idSocket(), _server->get_parser()->encode(packet_info));
  delete (packet_info);
  //  std::cout << "\n\tDONE 1/2\n\n";
}

void User::callAnswer(char err, std::vector<int> ints) { //C2
  IPacketInfo	*packet_info;
  char	*error = new char[1];

  error[0] = err;
  packet_info = new PacketInfo();
  packet_info->setCmd(27);
  packet_info->getChars().push_back(error);
  packet_info->getChars().push_back(_server->get_network()->get_connected(_idSocket)->get_ip()); //ip C2
  packet_info->getInts().push_back(ints[1]);
  packet_info->getInts().push_back(ints[2]);
  packet_info->getInts().push_back(ints[3]);
  _server->pushToSend(_server->get_users().find(ints[0])->second->get_idSocket(), _server->get_parser()->encode(packet_info));
  delete (packet_info);
}
