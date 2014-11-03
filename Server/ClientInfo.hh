/***********************************************************************
 * Module:  ClientInfo.h
 * Author:  urvoy_p
 * Modified: Monday, October 20, 2014 6:30:45 PM
 * Purpose: Declaration of the class ClientInfo
 ***********************************************************************/

#if !defined(__Server_ClientInfo_hh)
#define __Server_ClientInfo_hh

#include <string>

class ClientInfo
{
public:
   virtual int get_id(void) const;
   virtual std::string get_login(void) const;
   virtual std::string get_psw(void) const;
   virtual std::string get_birth(void) const;
   virtual std::string get_name(void) const;
   virtual std::string get_nickname(void) const;
   virtual std::string get_location(void) const;
   virtual std::string get_phone(void) const;
   virtual char get_status(void) const;
   virtual char get_module(void) const;
   virtual void set_id(int new_id);
   virtual void set_login(std::string new_login);
   virtual void set_psw(std::string new_psw);
   virtual void set_birth(std::string new_birth);
   virtual void set_name(std::string new_name);
   virtual void set_nickname(std::string new_nickname);
   virtual void set_location(std::string new_location);
   virtual void set_phone(std::string new_phone);
   virtual void set_status(char new_status);
   virtual void set_module(char new_module);
   ClientInfo();
   ClientInfo(const ClientInfo& oldClientInfo);
   virtual ~ClientInfo();

protected:
   int _id;
   std::string _login;
   std::string _psw;
   std::string _birth;
   std::string _name;
   std::string _nickname;
   std::string _location;
   std::string _phone;
   char _status;
   char _module;

private:

};

#endif
