/***********************************************************************
 * Module:  Server.h
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 6:31:47 PM
 * Purpose: Declaration of the class Server
 ***********************************************************************/

#if !defined(__Server_Server_hh)
#define __Server_Server_hh

#include "UNetwork.hh"

//#include <XMLParser.h>
#include "Parser.hh"
#define	VERSION		"0.0.0"

#include	<string>
#include	<map>
#include	"Client.hh"

class Server
{
public:
   bool startServer(void);
   bool endServer(void);
   bool loopServer(void);
   void print_error(void);
   std::string get_version(void) const;
  UNetwork * get_network(void) const;
   std::map<int, Client *> get_clients(void) const;
  //XMLParser * get_xmlParser(void) const;
  IParser *get_parser(void) const;
   std::map<std::string, int> get_idClients(void) const;
   void set_version(std::string new_version);
  void set_network(UNetwork * new_network);
   void set_clients(std::map<int, Client *> new_clients);
  //void set_xmlParser(XMLParser* new_xmlParser);
  void set_parser(IParser*);
   void set_idClients(std::map<std::string, int> new_idClients);
   Server();
   Server(const Server& oldServer);
   ~Server();

protected:
private:
   std::string _version;
  UNetwork * _network;
   std::map<int, Client *> _clients;
  //XMLParser * _xmlParser;
  IParser *_parser;
   std::map<std::string, int> _idClients;

};

#endif
