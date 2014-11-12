//
// ServerNetwork.cpp for babel in /home/giraud_d/Desktop/work/babel/Server
// 
// Made by Damien Giraudet
// Login   <giraud_d@epitech.net>
// 
// Started on  Wed Nov  5 15:13:41 2014 Damien Giraudet
// Last update Wed Nov 12 19:07:44 2014 Damien Giraudet
//

#include <errno.h>
#include "Server.hh"

bool	Server::newUser(void)
{
  int	id_socket;

  if ((id_socket = _network->acceptSocket()) == false)
    return (false);
  tmp_user--;
  _users[tmp_user] = new User(id_socket, tmp_user, this);
  return (true);
}

void	Server::deleteUser(User *user)
{
  if (user == 0)
    return ;
  if (_users.find(user->get_id()) == _users.end())
    return ;
  _users.erase(user->get_id());
  delete (_users[user->get_id()]);
  std::cout << "Delete User\nSize of map : " << _users.size() << "\n\n";
}

void	Server::setFd(fd_set &setfd)
{
  std::map<int, User*>::iterator it;
  ClientInfo *clientInfo;

  if (_network->get_connected(0))
    FD_SET(_network->get_connected(0)->get_socket(), &setfd);
  it = _users.begin();
  while (it != _users.end())
    {
      if (it->second != 0 && (clientInfo = _network->get_connected((it->second)->get_idSocket())))
	FD_SET(clientInfo->get_socket(), &setfd);
      else
	deleteUser(it->second);
      it++;
    }
}
#include <string.h>

bool	Server::treatRecv(User *user)
{
  if (_network->get_filled() != 65)
    return (false);

  std::string		rbuff(_network->get_buffer(), 65);
  std::stringbuf	usz(rbuff);
  Packet		*packet = new Packet();
  //on insère alors le le tout dans le paquet comme le dit l'expression
  usz << packet;
  //  std::cout << packet->getData() << std::endl;
  // //on teste_z notre gros paquet rempli de foutre
  //std::cout << "usz: " << usz.str() << std::endl; 
  
  IPacketInfo *packet_info;
  if (user == 0)
    return (false);
  packet_info = get_parser()->decode(packet);
  user->get_commandsValue()->cmdVal(packet_info);
  // map ptr sur fct
  return (true);
}

void	Server::recvIsSet(fd_set &readfs)
{
  std::map<int, User*>::iterator it;
  ClientInfo *clientInfo;

  if (FD_ISSET(_network->get_connected(0)->get_socket(), &readfs))
    newUser();
  it = _users.begin();
  while (it != _users.end())
    {
      if (it->second != 0 && (clientInfo = _network->get_connected(it->second->get_idSocket())))
	{
	  if (FD_ISSET(clientInfo->get_socket(), &readfs))
	    {
	      if (_network->recvSocket((it->second)->get_idSocket())) // renvrera une len via get_field
		treatRecv(it->second);
	      else
	      	{
		  std::cout << "\n\tREAD FAIL !!!!!\n\n";
		  deleteUser(it->second);
	      	  return ;  // pb de it si suppression
	      	}
	    }
	}
      else
	deleteUser(it->second);
      it++;
    }
}

void	Server::sendIsSet(fd_set &setfd)
{
  std::stringbuf sz;

  if (!_toSend.empty() && _network->get_connected(_toSend.front()._id_socket))
    {
      if (FD_ISSET(_network->get_connected(_toSend.front()._id_socket)->get_socket(), &setfd))
	{
	  //std::cout << "I will send cmd nb : " << (int)(_toSend.front()._packet->getCommand()) << std::endl;
	  sz >> (Packet *)_toSend.front()._packet;
	  if (!(_network->sendSocket(_toSend.front()._id_socket, (void *)sz.str().c_str(), 65)))
	    puts("FAIL : sendSocket");
	  else
	    puts("SUCCES : sendSocket");
	  // puts("TEST");
	  // std::string test(sz.str().c_str(), 65);
	  // std::stringbuf buf(test);
	  // Packet *packets = new Packet();
	  // buf << packets;
	  // std::cout << (int)packets->getCommand() << std::endl;
	  // write(1, packets->getData(), 64);
	  // puts("TEST");
	}
      delete (_toSend.front()._packet);
      _toSend.pop();

    }

}

void	Server::setFdWrite(fd_set &setfd)
{
  if (!_toSend.empty())
    {
      if (_network->get_connected(_toSend.front()._id_socket))
	{
	  puts("I fdSet");
	  FD_SET(_network->get_connected(_toSend.front()._id_socket)->get_socket(), &setfd);
	}
      else
	{
	  delete (_toSend.front()._packet);
	  _toSend.pop();
	  setFdWrite(setfd);
	}
    }
}

bool Server::loopServer(void)
{
  fd_set	readfs;
  fd_set	writefs;

  tmp_user = 0;
  while (1)
    {
      FD_ZERO(&readfs);
      FD_ZERO(&writefs);
      setFd(readfs);
      setFdWrite(writefs);
      std::cout << "Max fd id : " << _network->maxSocket()->get_socket() << std::endl;
      if (select(_network->maxSocket()->get_socket() + 1, &readfs, &writefs, NULL, NULL) < 0)
	{
	  perror("select");
	  return (false);
	}
      sendIsSet(writefs);
      recvIsSet(readfs);
    }
  return (true);
}

void  Server::pushToSend(int id_socket, IPacket *packet)
{
  ToSend	toPush; // un new ?

  toPush._id_socket = id_socket;
  toPush._packet = packet;
  _toSend.push(toPush);
  //std::cout << "The size of _toSend" << _toSend.size() << std::endl;
}
