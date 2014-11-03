/***********************************************************************
 * Module:  UNetwork.h
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 4:23:13 PM
 * Purpose: Declaration of the class UNetwork
 ***********************************************************************/

#if !defined(__Client_UNetwork_hh)
#define __Client_UNetwork_hh

//#include	"INetwork.h"
#include	"UClientInfo.hh"
#include	<arpa/inet.h>
#include	<netinet/in.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	<netdb.h>
#include	<stdbool.h>
#include	<map>

typedef struct	sockaddr saddr;
typedef struct	sockaddr_in saddrin; 

class UNetwork// : public INetwork
{
public:
  virtual bool	bindSocket(std::string);
  virtual void	closeSocket(int);
  virtual bool	createSocket(std::string, int &);
  virtual char	*& get_buffer(void);
  virtual UClientInfo * get_connected(int);
  //tronc commun
  
  virtual bool	listenSocket(int);
  virtual int	acceptSocket(void);
  virtual int	connectSocket(std::string, std::string);
  virtual bool	recvSocket(int);
  virtual bool	sendSocket(int , void *, size_t);
  //tcp
  
  virtual int	connectToSocket(std::string, std::string);
  virtual bool	sendToSocket(int, void *, size_t);
  virtual int	recvFromSocket(void);
  virtual int	UDPDuplicate(UClientInfo *, int &);
  //udp
  
  UNetwork(int, int, std::string, size_t = 512);
  UNetwork(const UNetwork& oldUNetwork);
  virtual ~UNetwork();

protected:
   int		_family;//tronc commun
   size_t	_len;
   int		_id;
   std::map<int, UClientInfo *> _connected; //<id, fd> //tcp

private:
};

#endif
