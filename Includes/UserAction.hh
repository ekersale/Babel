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
   virtual bool subscribe(void);
   virtual bool connect(void);
   virtual bool changeNick(void);
   virtual bool changeStatus(void);
   virtual bool changeBirth(void);
   virtual bool changeModule(void);
   virtual bool changeSurname(void);
   virtual bool changeName(void);
   virtual bool changeAddress(void);
   virtual bool changePhone(void);
   virtual bool addContact(void);
   virtual bool rmContact(void);
   virtual bool startCall(void);
   virtual bool endCall(void);

  virtual void isConnected(void);
  virtual void isDisconnected(void);
  virtual bool getConnected(void) const;

   UserAction();
   UserAction(const UserAction& oldUserAction);
   virtual ~UserAction();

protected:
  bool		_connected;
private:
};

#endif
