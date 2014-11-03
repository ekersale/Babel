/***********************************************************************
 * Module:  ClientInfo.cpp
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 6:30:45 PM
 * Purpose: Implementation of the class ClientInfo
 ***********************************************************************/

#include "ClientInfo.hh"

int ClientInfo::get_id(void) const
{
   return _id;
}

std::string ClientInfo::get_login(void) const
{
   return _login;
}

std::string ClientInfo::get_psw(void) const
{
   return _psw;
}

std::string ClientInfo::get_birth(void) const
{
   return _birth;
}

std::string ClientInfo::get_name(void) const
{
   return _name;
}

std::string ClientInfo::get_nickname(void) const
{
   return _nickname;
}

std::string ClientInfo::get_location(void) const
{
   return _location;
}

std::string ClientInfo::get_phone(void) const
{
   return _phone;
}

char ClientInfo::get_status(void) const
{
   return _status;
}

char ClientInfo::get_module(void) const
{
   return _module;
}

void ClientInfo::set_id(int new_id)
{
   _id = new_id;
}

void ClientInfo::set_login(std::string new_login)
{
   _login = new_login;
}

void ClientInfo::set_psw(std::string new_psw)
{
   _psw = new_psw;
}

void ClientInfo::set_birth(std::string new_birth)
{
   _birth = new_birth;
}

void ClientInfo::set_name(std::string new_name)
{
   _name = new_name;
}

void ClientInfo::set_nickname(std::string new_nickname)
{
   _nickname = new_nickname;
}

void ClientInfo::set_location(std::string new_location)
{
   _location = new_location;
}

void ClientInfo::set_phone(std::string new_phone)
{
   _phone = new_phone;
}

void ClientInfo::set_status(char new_status)
{
   _status = new_status;
}

void ClientInfo::set_module(char new_module)
{
   _module = new_module;
}

ClientInfo::ClientInfo()
{
   _id = 0;
   _status = 0;
   _module = 0;
}

ClientInfo::ClientInfo(const ClientInfo& oldClientInfo)
{
   _id = oldClientInfo._id;
   _login = oldClientInfo._login;
   _psw = oldClientInfo._psw;
   _birth = oldClientInfo._birth;
   _name = oldClientInfo._name;
   _nickname = oldClientInfo._nickname;
   _location = oldClientInfo._location;
   _phone = oldClientInfo._phone;
   _status = oldClientInfo._status;
   _module = oldClientInfo._module;
}

ClientInfo::~ClientInfo()
{
   // TODO : implement
}
