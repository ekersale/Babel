//
// ClienInfo.cpp for CI in /home/urvoy_p/Desktop/Babel_Studio/Client/Network/Unix
// 
// Made by Pierre-Antoine Urvoy
// Login   <urvoy_p@epitech.net>
// 
// Started on  Sat Nov  1 17:37:06 2014 Pierre-Antoine Urvoy
// Last update Wed Nov 12 13:22:05 2014 Damien Giraudet
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifdef _WIN32

#else
#include	"UClientInfo.hh"

void		ClientInfo::setAddr(int family, std::string port, std::string host)
{
  memset(&_info, 0, sizeof(_info));
  _info.sin_family = family;
  _info.sin_port = htons(atoi(port.c_str()));
  if (host.empty())
    _info.sin_addr.s_addr = INADDR_ANY;
  else
    _info.sin_addr.s_addr = inet_addr(host.c_str());
  printf("IP address is: %s\n", inet_ntoa(_info.sin_addr));
}

#include <iostream>
char*		ClientInfo::get_ip(void)
{
  puts("INET");
  
  puts(inet_ntoa(_info.sin_addr));
  puts("INET");
  return (inet_ntoa(_info.sin_addr));
}

int&		ClientInfo::get_socket(void)
{
  return (_socket);
}

char *&		ClientInfo::get_buffer(void)
{
  return (_buffer);
}


saddrin&       	ClientInfo::get_info(void)
{
  return (_info);
}

int&		ClientInfo::get_len(void)
{
  return (_len);
}

int&		ClientInfo::get_filled(void)
{
  return (_filled);
}

ClientInfo::ClientInfo(int len)
{
  _socket = 0;
  _buffer = new char[len];
  _len = len;
  _buffer[0] = 0;
  _filled = 0;
  memset(&_info, 0, sizeof(_info));
}

ClientInfo::~ClientInfo()
{
  delete[] _buffer;
}
#endif
