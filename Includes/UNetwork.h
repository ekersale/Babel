/***********************************************************************
 * Module:  UNetwork.h
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 4:23:13 PM
 * Purpose: Declaration of the class UNetwork
 ***********************************************************************/

#if !defined(__Client_UNetwork_h)
#define __Client_UNetwork_h

#include	"INetwork.h"
#include	"ClientInfo.h"
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

class UNetwork : public INetwork
{
public:
   virtual bool	bindSocket(char *);
   virtual void closeSocket(int);
   virtual bool createSocket(char *proto, int type);
   virtual int *& get_buffer(void);
   virtual char *& get_string(void);
   //tronc commun

   virtual bool listenSocket(int);
   virtual int  acceptSocket(void);
   virtual int  connectSocket(char *, char *);
   virtual bool recvSocket(int);
   virtual bool sendSocket(int, void *, int);
   //tcp

   virtual int connectToSocket(char *, char *);
   virtual bool sendToSocket(int, void *, int);
   virtual int recvFromSocket(void);
   virtual int UDPDuplicate(ClientInfo *, int &);
   //udp

   UNetwork(int family, int type, char *proto);
   UNetwork(const UNetwork& oldUNetwork);
   virtual ~UNetwork();

protected:
   int		_family;//tronc commun

   ClientInfo	_itself;//UDP
   ClientInfo	_other;//UDP

   int		_id;
   std::map<int, ClientInfo *> _connected; //<id, fd> //tcp

private:
};

#endif
