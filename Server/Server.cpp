/***********************************************************************
 * Module:  Server.cpp
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 6:31:47 PM
 * Purpose: Implementation of the class Server
 ***********************************************************************/

#include "Server.hh"

#define		PORT	"2000" // en dur
#define		LISTEN_VAL	20

Serialize* Server::get_serialize(void) const {
  return (_serialize);
}

bool Server::startServer(void)
{
  //ifndef
  _network = new Network(AF_INET, SOCK_STREAM, "TCP", sizeof(Packet));
  if (_network->bindSocket(PORT) < 0)
    {
      std::cerr << "Fatal Error : Bind Error" << std::endl;
      return (false);
    }
  if (_network->listenSocket(LISTEN_VAL) < 0)
    {
      std::cerr << "Fatal Error : Listen Error" << std::endl;
      return (false);
    }
  _serialize = new Serialize();
  _xmlParser = new XMLParser();
  _parser = new Parser(_xmlParser->getCommandArgs("commands.xml"));
  tmp_max = _xmlParser->countXmlFiles();
  return (true);
   // TODO : implement
}

bool Server::endServer(void)
{
   // TODO : implement
}

void Server::print_error(void)
{
   // TODO : implement
}

std::string Server::get_version(void) const
{
   return _version;
}

Network * Server::get_network(void) const
{
   return _network;
}

std::map<int, User *> Server::get_users(void) const
{
   return _users;
}

XMLParser * Server::get_xmlParser(void) const
{
   return _xmlParser;
}

IParser * Server::get_parser(void) const
{
   return _parser;
}

std::map<std::string, int> Server::get_idUsers(void) const
{
   return _idUsers;
}

void Server::set_version(std::string new_version)
{
   _version = new_version;
}

void Server::set_network(Network * new_network)
{
   _network = new_network;
}

void Server::set_users(std::map<int, User *> new_users)
{
   _users = new_users;
}

void Server::set_xmlParser(XMLParser* new_xmlParser)
{
   _xmlParser = new_xmlParser;
}

void Server::set_parser(IParser* new_parser)
{
   _parser = new_parser;
}

void Server::set_idUsers(std::map<std::string, int> new_idUsers)
{
   _idUsers = new_idUsers;
}

std::map<int, User *>& Server::get_users() { // getter & setter
  return (_users);
}

void		Server::increment_tmpMax() {
  tmp_max++;
}

int		&Server::get_tmpMax() {
  return (tmp_max);
}

int		Server::init(void)
{
  if (startServer())
    return (loopServer());
  return (false);
}

Server::Server()
{
   _version = VERSION;
   _network = NULL;
   _xmlParser = NULL;
   _parser = NULL;
   tmp_user = -1;
}

Server::Server(const Server& oldServer)
{
   _version = oldServer._version;
   _network = oldServer._network;
   _users = oldServer._users;
   _xmlParser = oldServer._xmlParser;
   _parser = oldServer._parser;
   _idUsers = oldServer._idUsers;
   tmp_user = -1;
}

Server::~Server()
{
   // TODO : implement
}
