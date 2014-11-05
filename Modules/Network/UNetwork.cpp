/***********************************************************************
 * Module:  AUnix.cpp
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 4:23:13 PM
 * Purpose: Implementation of the class AUnix
 ***********************************************************************/

#include		"../../Includes/UNetwork.h"

bool			UNetwork::createSocket(std::string proto, int &type)
{
  struct protoent       *pe;
  ClientInfo		*current;

  if (_connected.find(0) != _connected.end())
    return (false);
  if (!(current = (new ClientInfo(_len))))
    return (false);
  if (!(pe = getprotobyname(proto.c_str())))
    return (false);
  if ((current->get_socket() = socket(_family, type, pe->p_proto)) == -1)
    {
      delete current;
      return (false);
    }
  _connected[++_id] = current; //stockage de la socket
  return (true);
}

void			UNetwork::closeSocket(int id)
{
  if (_connected.find(id) == _connected.end())
    return ;
  close(_connected[id]->get_socket());
  if (id != 0)
    {
      delete _connected[id];
      _connected.erase(id);
    }
}

bool			UNetwork::bindSocket(std::string port)
{
  _connected[0]->setAddr(_family, port.c_str(), ""); //set addr SERVER, NULL car serveur
  if (bind(_connected[0]->get_socket(), (saddr *)(&(_connected[0]->get_info())), sizeof(saddrin)) < 0)
    return (false);
  return (true);
}

char *&			UNetwork::get_buffer(void)
{
  return (_connected[0]->get_buffer());
}

size_t &		UNetwork::get_filled(void)
{
  return (_connected[0]->get_filled());
}

/* * * */
/* TCP */
/* * * */
bool			UNetwork::listenSocket(int number)
{
  if (listen(_connected[0]->get_socket(), number) < 0)
    return (false);
  return (true);
}

int			UNetwork::acceptSocket(void)
{
  socklen_t		socklen;
  ClientInfo		*stranger = new ClientInfo(_len);

  if (!stranger)
    return (false);
  socklen = sizeof(saddrin);
  if ((stranger->get_socket() = accept(_connected[0]->get_socket(), (saddr *)&(stranger->get_info()), &socklen)) < 0)
    {
      delete stranger;
      return (false);
    }
  _connected[++_id] = stranger;
  return (_id);
}

int			UNetwork::connectSocket(std::string host, std::string port)
{
  struct protoent       *pe;
  ClientInfo		*stranger = new ClientInfo(_len);

  if (!stranger)
    return (false);
  if (!(pe = getprotobyname("TCP")))
    return (false);
  stranger->setAddr(_family, port.c_str(), host.c_str()); //prépare la connexion tcp vers un serveur
  if ((stranger->get_socket() = socket(_family, SOCK_STREAM, pe->p_proto)) == -1)
    return (false);
  if (connect(stranger->get_socket(), (saddr *)(&stranger->get_info()), sizeof(saddrin)) < 0)
    {
      close(stranger->get_socket());
      delete stranger;
      return (false);
    }
  _connected[++_id] = stranger;
  return (_id);
}

bool			UNetwork::recvSocket(int id)
{
  int len;

  if (_connected.find(id) == _connected.end())
    return (false);
  memset(_connected[0]->get_buffer(), 0, _connected[0]->get_len());
  len = recv(_connected[id]->get_socket(), _connected[0]->get_buffer(), _connected[0]->get_len(), 0);
  if (len < 0)
    {
      closeSocket(id);
      _connected[0]->get_buffer()[0] = 0;
      return (false);
    }
  _connected[0]->get_filled() = len;
  //  _connected[0]->get_buffer()[len] = 0;
  return (true);
}

bool			UNetwork::sendSocket(int id, void *buff, size_t len)
{
  if (_connected.find(id) == _connected.end())
    return (false);
  if (send(_connected[id]->get_socket(), buff, len, 0) < 0)
    {
      closeSocket(id);
      _connected[0]->get_buffer()[0] = 0;
      return (false);
    }
  return (true);
}

/* * * */
/* UDP */
/* * * */
int			UNetwork::connectToSocket(std::string host, std::string port)
{
  int			id;
  ClientInfo		*stranger = new ClientInfo(_len);

  if (!stranger)
    return (-1);
  stranger->setAddr(AF_INET, port.c_str(), host.c_str()); //prépare la connexion udp vers un serveur
  _connected[++_id] = stranger;
  return (_id);
}

bool			UNetwork::sendToSocket(int id, void *buff, size_t len)
{
  if (_connected.find(id) == _connected.end())
    return (false);
  if (sendto(_connected[0]->get_socket(), buff, len, //prend mon socket courant
	     0, (saddr *)(&(_connected[id]->get_info())),  //utilise les infos de l'autre
	     (socklen_t)sizeof(saddrin)) < 0) //envoie
    {
      closeSocket(id);
      _connected[0]->get_buffer()[0] = 0;
      return (false);
    }
  return (true);
}

int			UNetwork::UDPDuplicate(ClientInfo *stranger, int &id)
{
  id = -1;

  while (++id < (int)_connected.size())
    if (memcmp(&_connected[id]->get_info(), &stranger->get_info(), sizeof(saddrin)) == 0)
      return (true);
  return (false);
}

int			UNetwork::recvFromSocket(void)
{
  int                   len;
  int			id;
  socklen_t             socklen;
  static ClientInfo	stranger(1);
  ClientInfo		*nstranger;

  socklen = sizeof(saddrin); //bullshit
  memset(_connected[0]->get_buffer(), 0, _connected[0]->get_len());
  puts(_connected[0]->get_buffer());
  len = recvfrom(_connected[0]->get_socket(), _connected[0]->get_buffer(),
		 _connected[0]->get_len(), 0, (saddr *)&stranger.get_info(), &socklen);
  if (len < 0)
    {
      _connected[0]->get_buffer()[0] = 0;
      return (false);
    }
  _connected[0]->get_filled() = len;
  _connected[0]->get_buffer()[len] = 0;
  if (UDPDuplicate(&stranger, id)) // verificationd des duplicats
    return (id);
  if (!(nstranger = new ClientInfo(_len)))
    return (false);
  printf("sizemap %d\n", _connected.size());
  nstranger->get_info() = stranger.get_info();
  _connected[++_id] = nstranger; // en udp c'est le rcv qui dit qui vient de se connecter, on stocke ca
  return (_id);
}

UNetwork::UNetwork(int family, int type, std::string proto, size_t len)
{   
  _family = family;
  _id = -1;
  _len = len;
  createSocket(proto, type);
}

UNetwork::UNetwork(const UNetwork& oldUNetwork)
{
}

UNetwork::~UNetwork()
{
  int			id = -1;

  while (++id < (int)_connected.size())
    delete _connected[id];
}
