/*
** ClientInfo.h for CI in /home/urvoy_p/Desktop/Babel_Studio/Client/Network/Unix
** 
** Made by Pierre-Antoine Urvoy
** Login   <urvoy_p@epitech.net>
** 
** Started on  Sat Nov  1 17:39:04 2014 Pierre-Antoine Urvoy
// Last update Wed Nov  5 16:26:24 2014 Pierre-Antoine Urvoy
*/

#include	<Windows.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<string>

typedef struct	sockaddr saddr;
typedef struct	sockaddr_in saddrin;

class		ClientInfo
{
 protected:
  SOCKET	_socket;
  saddrin	_info;
  char *	_buffer;
  int		_len;
  int		_filled;
 public:
  void		setAddr(int, std::string, std::string);
  int&		get_socket(void);
  int&		get_filled(void);
  saddrin&     	get_info(void);
  char *&	get_buffer(void);
  int&		get_len(void);

  ClientInfo(int = 512);
  ~ClientInfo();
};
