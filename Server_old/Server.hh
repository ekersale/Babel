/***********************************************************************
 * Module:  Server.h
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 6:31:47 PM
 * Purpose: Declaration of the class Server
 ***********************************************************************/

#if !defined(__Server_Server_hh)
#define __Server_Server_hh

#include "../Includes/Network.hh"

#include <XMLParser.h>
#include "Parser.hh"
#define	VERSION		"0.0.0"

#include <sys/select.h>
#include	<string>
#include	<map>
#include	"User.hh"
#include	"Serialize.hh"

class Server
{
public:
   bool startServer(void);
   bool endServer(void);
   bool loopServer(void);
   void print_error(void);
   std::string get_version(void) const;
  Network* get_network(void) const;
  Serialize* get_serialize(void) const;
   std::map<int, User *> get_users(void) const;
  XMLParser * get_xmlParser(void) const;
  IParser *get_parser(void) const;
   std::map<std::string, int> get_idUsers(void) const;
   void set_version(std::string new_version);
  void set_network(Network * new_network);
  //void set_serialize(Serialize *);
   void set_users(std::map<int, User *> new_users);
  void set_xmlParser(XMLParser* new_xmlParser);
  void set_parser(IParser*);
   void set_idUsers(std::map<std::string, int> new_idUsers);
  void    deleteUser(User *user);
  void	setFd(fd_set &setfd);
void	recvIsSet(fd_set &setfd);
  bool treatRecv(User *);
  bool newUser(void);
  int	init(void);
  std::map<int, User *> &get_users(); // getter & setter
   Server();
   Server(const Server& oldServer);
   ~Server();

protected:
private:
   std::string _version;
  Network * _network;
   std::map<int, User *> _users;
  XMLParser * _xmlParser;
  IParser *_parser;
  Serialize *_serialize;
   std::map<std::string, int> _idUsers;

int tmp_user;

};

#endif
