/*
** ClientInfo.h for CI in /home/urvoy_p/Desktop/Babel_Studio/Client/Network/Unix
** 
** Made by Pierre-Antoine Urvoy
** Login   <urvoy_p@epitech.net>
** 
** Started on  Sat Nov  1 17:39:04 2014 Pierre-Antoine Urvoy
** Last update Sun Nov  2 16:38:28 2014 Pierre-Antoine Urvoy
*/

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

typedef struct	sockaddr saddr;
typedef struct	sockaddr_in saddrin; 

class		ClientInfo
{
 private:
  int		_socket;
  saddrin	_info;
  int *		_buffer;
  int		_len;
 public:
  void		setAddr(int, char *, char *);
  int&		get_socket(void);
  saddrin&	get_info(void);
  int *&	get_buffer(void);
  int&		get_len(void);

  ClientInfo(int = 512);
  ~ClientInfo();
};
