/***********************************************************************
 * Module:  UserInfo.cpp
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 6:30:45 PM
 * Purpose: Implementation of the class UserInfo
 ***********************************************************************/

#include "UserInfo.hh"

int UserInfo::get_id(void) const
{
   return _id;
}

std::string UserInfo::get_login(void) const
{
   return _login;
}

std::string UserInfo::get_psw(void) const
{
   return _psw;
}

std::string UserInfo::get_birth(void) const
{
   return _birth;
}

std::string UserInfo::get_name(void) const
{
   return _name;
}

std::string UserInfo::get_surname(void) const
{
   return _surname;
}

std::string UserInfo::get_nickname(void) const
{
   return _nickname;
}

std::string UserInfo::get_address(void) const
{
   return _address;
}

std::string UserInfo::get_phone(void) const
{
   return _phone;
}

char UserInfo::get_status(void) const
{
   return _status;
}

char UserInfo::get_module(void) const
{
   return _module;
}

void UserInfo::set_id(int new_id)
{
   _id = new_id;
}

void UserInfo::set_login(std::string new_login)
{
   _login = new_login;
}

void UserInfo::set_psw(std::string new_psw)
{
   _psw = new_psw;
}

void UserInfo::set_birth(std::string new_birth)
{
   _birth = new_birth;
}

void UserInfo::set_name(std::string new_name)
{
   _name = new_name;
}

void UserInfo::set_surname(std::string new_surname)
{
   _surname = new_surname;
}

void UserInfo::set_nickname(std::string new_nickname)
{
   _nickname = new_nickname;
}

void UserInfo::set_adress(std::string new_address)
{
   _address = new_address;
}

void UserInfo::set_phone(std::string new_phone)
{
   _phone = new_phone;
}

void UserInfo::set_status(char new_status)
{
   _status = new_status;
}

void UserInfo::set_module(char new_module)
{
   _module = new_module;
}

UserInfo::UserInfo()
{
   _id = 0;
   _status = 0;
   _module = 0;
}

UserInfo::UserInfo(const UserInfo& oldUserInfo)
{
   _id = oldUserInfo._id;
   _login = oldUserInfo._login;
   _psw = oldUserInfo._psw;
   _birth = oldUserInfo._birth;
   _name = oldUserInfo._name;
   _surname = oldUserInfo._surname;
   _nickname = oldUserInfo._nickname;
   _address = oldUserInfo._address;
   _phone = oldUserInfo._phone;
   _status = oldUserInfo._status;
   _module = oldUserInfo._module;
}

UserInfo::~UserInfo() {
}
