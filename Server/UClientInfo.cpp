//
// ClienInfo.cpp for CI in /home/urvoy_p/Desktop/Babel_Studio/Client/Network/Unix
// 
// Made by Pierre-Antoine Urvoy
// Login   <urvoy_p@epitech.net>
// 
// Started on  Sat Nov  1 17:37:06 2014 Pierre-Antoine Urvoy
// Last update Sun Nov  2 22:28:17 2014 Damien Giraudet
//

#include	"UClientInfo.hh"

void		UClientInfo::setAddr(int family, std::string port, std::string host)
{
  bzero(&_info, sizeof(_info));
  _info.sin_family = family;
  _info.sin_port = htons(atoi(port.c_str()));
  if (host.empty())
    _info.sin_addr.s_addr = INADDR_ANY;
  else
    _info.sin_addr.s_addr = inet_addr(host.c_str());
}

int&		UClientInfo::get_socket(void)
{
  return (_socket);
}

char *&		UClientInfo::get_buffer(void)
{
  return (_buffer);
}

saddrin&	UClientInfo::get_info(void)
{
  return (_info);
}

int&		UClientInfo::get_len(void)
{
  return (_len);
}

UClientInfo::UClientInfo(int len)
{
  _socket = -1;
  _buffer = new char[len];
  _len = len;
  _buffer[0] = 0;
  bzero(&_info, sizeof(_info));
}

UClientInfo::~UClientInfo()
{
  delete[] _buffer;
}
