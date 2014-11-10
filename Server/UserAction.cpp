/***********************************************************************
 * Module:  UserAction.cpp
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 10:55:09 AM
 * Purpose: Implementation of the class UserAction
 ***********************************************************************/

#include "UserAction.hh"

void UserAction::authAnswer(char &ret_val) {
  /*
  PacketInfo	ret;

  ret.setCmd(3);
  ret.

  pushToSend();
  */
}

void UserAction::connectContactLoop(void) {

}

void UserAction::contactLoop(int &) {

}

void UserAction::contactNick(int &) {

}

void UserAction::contactStatus(int &) {

}

void UserAction::contactBirth(int &) {

}

void UserAction::contactModule(int &) {

}

void UserAction::contactSurname(int &) {

}

void UserAction::contactName(int &) {

}

void UserAction::contactAddress(int &) {

}

void UserAction::contactPhone(int &) {

}
 
void UserAction::removeAnswer(char &) {

}

void UserAction::removeRequest(int &) {

}

void UserAction::addAnswer(char &) {

}

/*
bool UserAction::startCall(void)
{
   // TODO : implement
}

bool UserAction::endCall(void)
{
   // TODO : implement
}
*/
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
