//
// ServerNetwork.cpp for babel in /home/giraud_d/Desktop/work/babel/Server
// 
// Made by Damien Giraudet
// Login   <giraud_d@epitech.net>
// 
// Started on  Wed Nov  5 15:13:41 2014 Damien Giraudet
// Last update Wed Nov  5 17:33:47 2014 Damien Giraudet
//

#include "Server.hh"
#include <sys/select.h>

bool	Server::newUser(void)
{
  int	key;

  if ((key = _network->acceptSocket()) == false)
    return (false);
  _users[key] = new User(_parser, key);
  // une connexion au serveur ne veut pas dire une connexion d'un utilisateur donc activeChat & Module = 0
  std::cout << "New User\n";
}

bool Server::loopServer(void)
{
  fd_set	readfs;

  while (1)
    {
      FD_ZERO(&readfs);
      FD_SET(_network->get_connected(0)->get_socket(), &readfs);
      //parcourir la map pour trouver le fd le plus haut
      select(3 + 1, &readfs, NULL, NULL, NULL);
      if (FD_ISSET(_network->get_connected(0)->get_socket(), &readfs))
	newUser();
	/*
      if (FD_ISSET(0, &readfs))
	{
	// TODO : implement select
	  void FD_CLR(int fd, fd_set *set);
	  int  FD_ISSET(int fd, fd_set *set);
	  void FD_SET(int fd, fd_set *set);
	  }
	*/
      /*
      while (map)
	{
	  if (FD_ISSET(_network->get_connected(_idSocket)->get_socket()))
	    {
	      if (_network->recvSocket(_idSocket)) // renvrera une len via get_lenght
		_network->get_buffer();
	      else
		{
		  //del everything related to User obj
		  // _network->sendSocket(_idSocket, User, sizeof(User));
		}
	    }
	}
      */
    }
  //end WHILE
}
