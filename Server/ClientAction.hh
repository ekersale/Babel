/***********************************************************************
 * Module:  ClientAction.h
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 10:55:09 AM
 * Purpose: Declaration of the class ClientAction
 ***********************************************************************/

#if !defined(__Server_ClientAction_hh)
#define __Server_ClientAction_hh

class ClientAction
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
   ClientAction();
   ClientAction(const ClientAction& oldClientAction);
   virtual ~ClientAction();

protected:
private:

};

#endif
