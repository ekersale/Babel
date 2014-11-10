/***********************************************************************
 * Module:  UserAction.h
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 10:55:09 AM
 * Purpose: Declaration of the class UserAction
 ***********************************************************************/

#if !defined(__Server_UserAction_hh)
#define __Server_UserAction_hh

class UserAction
{
public:
  void authAnswer(char &);
  void connectContactLoop(void);
  void contactLoop(int &);
  void contactNick(int &);
  void contactStatus(int &);
  void contactBirth(int &);
  void contactModule(int &);
  void contactSurname(int &);
  void contactName(int &);
  void contactAddress(int &);
  void contactPhone(int &);
 
  void removeAnswer(char &);
  void removeRequest(int &);

  void addAnswer(char &);

  /*
   void startCall(void);
   void endCall(void);
  */
  virtual void isConnected(void);
  virtual void isDisconnected(void);
  bool getConnected(void) const;

   UserAction();
   UserAction(const UserAction& oldUserAction);
   virtual ~UserAction();

protected:
  bool		_connected;
private:
};

#endif
