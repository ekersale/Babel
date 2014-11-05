//
// ServerNetwork.cpp for babel in /home/giraud_d/Desktop/work/babel/Server
// 
// Made by Damien Giraudet
// Login   <giraud_d@epitech.net>
// 
// Started on  Wed Nov  5 15:13:41 2014 Damien Giraudet
// Last update Wed Nov  5 21:35:02 2014 Damien Giraudet
//

#include <errno.h>
#include "Server.hh"

bool	Server::newUser(void)
{
  int	key;

  if ((key = _network->acceptSocket()) == false)
    return (false);
  tmp_user--;
  _users[tmp_user] = new User(_parser, key, tmp_user);
  // une connexion au serveur != une connexion d'un utilisateur donc activeChat & Module = 0
  std::cout << "New User : id : "  << tmp_user << "\n";
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

  //std::cout << "Size of map : " << _users.size() << "\n";
  if (_network->get_connected(0))
    FD_SET(_network->get_connected(0)->get_socket(), &setfd);
  it = _users.begin();
  while (it != _users.end())
    {
      std::cout << "Set with user : " << it->second->get_id() << "\n";
      if ((clientInfo = _network->get_connected((it->second)->get_idSocket())))
	FD_SET(clientInfo->get_socket(), &setfd);
      else
	deleteUser(it->second);
      it++;
    }

}

void	Server::recvIsSet(fd_set &readfs)
{
  std::map<int, User*>::iterator it;
  ClientInfo *clientInfo;

  std::cout << "\n\n";
  if (FD_ISSET(_network->get_connected(0)->get_socket(), &readfs)) {
      newUser();
      tmp++;
    }
  it = _users.begin();
  while (it != _users.end())
    {
      std::cout << "Loop\n";
      if ((clientInfo = _network->get_connected((it->second)->get_idSocket())))
	{
	  std::cout << "Inside Client Info\n";
	  if (FD_ISSET(clientInfo->get_socket(), &readfs))
	    {
	      std::cout << "Inside FD_ISSET\n";
	      if (_network->recvSocket(clientInfo->get_socket())) // renvrera une len via get_field
		_network->get_buffer();
	      else
		{
		  std::cout << "second\n";
		  deleteUser(it->second);
		  tmp--;
		  return ;
		  // pb de it si suppression
		}
	    }
	}
      else
	{
	  std::cout << "third\n";
	  deleteUser(it->second);
	  tmp--;
	}
      it++;
    }
  std::cout << "\n\n";
}

bool Server::loopServer(void)
{
  fd_set	readfs;

  tmp = 3;
  tmp_user = 0;
  while (1)
    {
      FD_ZERO(&readfs);
      setFd(readfs);
      //parcourir la map pour trouver le fd le plus haut
      std::cout << "\ttmp is : " << tmp << "\n";
      if (select(tmp + 1, &readfs, NULL, NULL, NULL) < 0)
	{
	  perror("select");
	  return (false);
	}
      recvIsSet(readfs);
    }
  /*
    if (sendSocket( User->key , buff , size))
{
} else {
// fail = del User
}
   */
}
