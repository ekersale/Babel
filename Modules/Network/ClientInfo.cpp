//
// ClienInfo.cpp for CI in /home/urvoy_p/Desktop/Babel_Studio/Client/Network/Unix
// 
// Made by Pierre-Antoine Urvoy
// Login   <urvoy_p@epitech.net>
// 
// Started on  Sat Nov  1 17:37:06 2014 Pierre-Antoine Urvoy
// Last update Sun Nov  2 18:24:41 2014 Elliot Kersalé
//

#include	"../../Includes/ClientInfo.h"

void		ClientInfo::setAddr(int family, char *port, char *host)
{
  bzero(&_info, sizeof(_info));
  _info.sin_family = family;
  if (port)
    _info.sin_port = htons(atoi(port));
  else
    _info.sin_port = -1;
  if (host == NULL)
    _info.sin_addr.s_addr = INADDR_ANY;
  else
   _info.sin_addr.s_addr = inet_addr(host);
}

int&		ClientInfo::get_socket(void)
{
  return (_socket);
}

int *&		ClientInfo::get_buffer(void)
{
  return (_buffer);
}

saddrin&	ClientInfo::get_info(void)
{
  return (_info);
}

int&		ClientInfo::get_len(void)
{
  return (_len);
}

ClientInfo::ClientInfo(int len)
{
  _socket = -1;
  _buffer = new int[len];
  _len = len;
  _buffer[0] = 0;
  bzero(&_info, sizeof(_info));
}

ClientInfo::~ClientInfo()
{
  delete[] _buffer;
}
