/***********************************************************************
 * Module:  UserAction.cpp
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 10:55:09 AM
 * Purpose: Implementation of the class UserAction
 ***********************************************************************/

#include "UserAction.hh"

bool UserAction::subscribe(void)
{
   // TODO : implement
}

bool UserAction::connect(void)
{
   // TODO : implement
}

bool UserAction::changeNick(void)
{
   // TODO : implement
}

bool UserAction::changeStatus(void)
{
   // TODO : implement
}

bool UserAction::changeBirth(void)
{
   // TODO : implement
}

bool UserAction::changeModule(void)
{
   // TODO : implement
}

bool UserAction::changeSurname(void)
{
   // TODO : implement
}

bool UserAction::changeName(void)
{
   // TODO : implement
}

bool UserAction::changeAddress(void)
{
   // TODO : implement
}

bool UserAction::changePhone(void)
{
   // TODO : implement
}

bool UserAction::addContact(void)
{
   // TODO : implement
}

bool UserAction::rmContact(void)
{
   // TODO : implement
}

bool UserAction::startCall(void)
{
   // TODO : implement
}

bool UserAction::endCall(void)
{
   // TODO : implement
}

void UserAction::isConnected(void) {
  _connected = true;
}

void UserAction::isDisconnected(void) {
  _connected = false;
}

bool UserAction::getConnected(void) const {
  return (_connected);
}

UserAction::UserAction()
{
}

UserAction::UserAction(const UserAction& oldUserAction)
{
}

UserAction::~UserAction()
{
   // TODO : implement
}