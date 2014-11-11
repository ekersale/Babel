//
// ServerNetwork.cpp for babel in /home/giraud_d/Desktop/work/babel/Server
// 
// Made by Damien Giraudet
// Login   <giraud_d@epitech.net>
// 
// Started on  Wed Nov  5 15:13:41 2014 Damien Giraudet
// Last update Tue Nov 11 12:26:35 2014 Sliman Desmars
//

#include <errno.h>
#include "Server.hh"

bool	Server::newUser(void)
{
  int	key;

  std::cout << "1/ Max fd id : " << _network->maxSocket()->get_socket() << "\n";
  if ((key = _network->acceptSocket()) == false)
    return (false);
  tmp_user--;
  _users[tmp_user] = new User(key, tmp_user, this);
  std::cout << "2/ Max fd id : " << _network->maxSocket()->get_socket() << "\n";
  // une connexion au serveur != une connexion d'un utilisateur donc activeChat & Module = 0
  std::cout << "New User : id : "  << tmp_user << "\n";
  return (true);
}

void	Server::deleteUser(User *user)
{
  std::cout << "\nUser id : " << user->get_id() << "\n";
  _users.erase(user->get_id());
  delete (user);
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
      if ((clientInfo = _network->get_connected((it->second)->get_idSocket())))
	FD_SET(clientInfo->get_socket(), &setfd);
      else
	{
	  deleteUser(it->second);
	  std::cout << "\t3 : setFd\n";
	}
      it++;
    }
}
#include <string.h>

bool	Server::treatRecv(User *user)
{
  std::cout << "\n\n\tMoi le get_filled : " << _network->get_filled() << " octects\n\n";
  if (_network->get_filled() != 65)
    return (false);
  std::cout << "\tTreat Req2l\n";


  //sinon on fait un receive et on recevra un buffer
  //pour l'exemple le buffer est celui du dessus



  std::string		rbuff(_network->get_buffer(), 65);
  std::stringbuf	usz(rbuff);
  Packet		*packet = new Packet();
  //on insère alors le le tout dans le paquet comme le dit l'expression
  usz << packet;
  std::cout << packet->getData() << std::endl;
  // //on teste_z notre gros paquet rempli de foutre
  //std::cout << "usz: " << usz.str() << std::endl; 
  


  IPacketInfo *packet_info;
  packet_info = get_parser()->decode(packet);
  std::cout << "\t Size of vector is " << packet_info->getChars().size() << "\n";
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
  std::cout << "\n\t_user size is : " << _users.size() << "\n\n";
  it = _users.begin();
  while (it != _users.end())
    {
      if ((clientInfo = _network->get_connected((it->second)->get_idSocket())))
	{
	  puts("--------------------------");
	  if (FD_ISSET(clientInfo->get_socket(), &readfs))
	    {
	      puts("++++++++++++++++++++++++++++");
	      if (_network->recvSocket((it->second)->get_idSocket())) // renvrera une len via get_field
		treatRecv(it->second);
	      else
		{
		  std::cout << "\t1 : Pb Recv\n";
		  deleteUser(it->second);
		  return ;  // pb de it si suppression
		}
	    }
	}
      else
	{
	  std::cout << "\t2 : Pb id_socket\n";
	  deleteUser(it->second);
	}
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
	  sz >> (Packet *)_toSend.front()._packet;
	  _network->sendSocket(_network->get_connected(_toSend.front()._id_socket)->get_socket(),
			       (void *)sz.str().c_str(), 65);
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
	FD_SET(_network->get_connected(_toSend.front()._id_socket)->get_socket(), &setfd);
      else
	{
	  delete (_toSend.front()._packet);
	  _toSend.pop();
	  std::cout << "\n\n\tRECCCCCCCCCCCCCCC\n\n";
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
      std::cout << "Max fd id : " << _network->maxSocket()->get_socket() << "\n";
      if (select(_network->maxSocket()->get_socket() + 1, &readfs, &writefs, NULL, NULL) < 0)
	{
	  perror("select");
	  return (false);
	}
      recvIsSet(readfs);
      sendIsSet(writefs);
    }
  return (true);
}

void  Server::pushToSend(int id_socket, IPacket *packet)
{
  ToSend	toPush; // un new ?

  toPush._id_socket = id_socket;
  toPush._packet = packet;
  _toSend.push(toPush);
}
