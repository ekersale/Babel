/***********************************************************************
 * Module:  Server.cpp
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 6:31:47 PM
 * Purpose: Implementation of the class Server
 ***********************************************************************/

#include "Server.hh"
#include <sys/select.h>

#define		PORT	"2000" // en dur
#define		LISTEN_VAL	20

bool Server::startServer(void)
{
  //ifndef
  _network = new UNetwork(AF_INET, SOCK_STREAM, "TCP", sizeof(Packet));
  _network->bindSocket(PORT);
  _network->listenSocket(LISTEN_VAL);
   // TODO : implement
}

bool Server::endServer(void)
{
   // TODO : implement
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
	{
	  
	  // co d'un nouveau client (TCP)
	  _clients[_network->acceptSocket()] = new Client();
	}
      /*
	while (map)
	{
	if (FD_ISSET(_network->get_connected(_idSocket)->get_socket()))
	{
	if (_network->recvSocket(_idSocket)) // renvrera une len
	_network->get_buffer();
	else
	//del everything related to Client obj
	// _network->sendSocket(_idSocket, Client, sizeof(Client));
	}
	}
      */
    }
   // TODO : implement select
  /*
       void FD_CLR(int fd, fd_set *set);
       int  FD_ISSET(int fd, fd_set *set);
       void FD_SET(int fd, fd_set *set);
       void FD_ZERO(fd_set *set);

         int select(int nfds, fd_set *readfds, fd_set *writefds,
                  fd_set *exceptfds, struct timeval *timeout);
  */
}

void Server::print_error(void)
{
   // TODO : implement
}

std::string Server::get_version(void) const
{
   return _version;
}

UNetwork * Server::get_network(void) const
{
   return _network;
}

std::map<int, Client *> Server::get_clients(void) const
{
   return _clients;
}

/*
XMLParser * Server::get_xmlParser(void) const
{
   return _xmlParser;
}
*/


IParser * Server::get_parser(void) const
{
   return _parser;
}

std::map<std::string, int> Server::get_idClients(void) const
{
   return _idClients;
}

void Server::set_version(std::string new_version)
{
   _version = new_version;
}

void Server::set_network(UNetwork * new_network)
{
   _network = new_network;
}

void Server::set_clients(std::map<int, Client *> new_clients)
{
   _clients = new_clients;
}

/*
void Server::set_xmlParser(XMLParser* new_xmlParser)
{
   _xmlParser = new_xmlParser;
}
*/

void Server::set_parser(IParser* new_parser)
{
   _parser = new_parser;
}

void Server::set_idClients(std::map<std::string, int> new_idClients)
{
   _idClients = new_idClients;
}

Server::Server()
{
   _version = VERSION;
   _network = NULL;
   //   _xmlParser = NULL;
      _parser = NULL;

      startServer();
      loopServer();
}

Server::Server(const Server& oldServer)
{
   _version = oldServer._version;
   _network = oldServer._network;
   _clients = oldServer._clients;
   //_xmlParser = oldServer._xmlParser;
   _parser = oldServer._parser;
   _idClients = oldServer._idClients;

      startServer();
      loopServer();
}

Server::~Server()
{
   // TODO : implement
}
