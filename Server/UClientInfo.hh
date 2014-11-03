/*
** ClientInfo.h for CI in /home/urvoy_p/Desktop/Babel_Studio/Client/Network/Unix
** 
** Made by Pierre-Antoine Urvoy
** Login   <urvoy_p@epitech.net>
** 
** Started on  Sat Nov  1 17:39:04 2014 Pierre-Antoine Urvoy
// Last update Sun Nov  2 22:27:53 2014 Damien Giraudet
*/

#if !defined(__UClientInfo_hh)
#define __UClientInfo_hh

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
#include	<string>

typedef struct	sockaddr saddr;
typedef struct	sockaddr_in saddrin; 

class		UClientInfo
{
 private:
  int		_socket;
  saddrin	_info;
  char *	_buffer;
  int		_len;
 public:
  void		setAddr(int, std::string, std::string);
  int&		get_socket(void);
  saddrin&	get_info(void);
  char *&	get_buffer(void);
  int&		get_len(void);

  UClientInfo(int = 512);
  ~UClientInfo();
};

#endif
