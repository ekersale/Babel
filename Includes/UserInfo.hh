#ifndef	__USERINFO_H__
#define __USERINFO_H__

#include	<string>

class UserInfo
{
public:
  UserInfo();
  UserInfo(const UserInfo &);
  ~UserInfo();
  virtual int		get_id(void) const;
  virtual std::string	get_phone(void) const;
  virtual std::string	get_birth(void) const;
  virtual std::string	get_name(void) const;
  virtual std::string	get_surname(void) const;
  virtual std::string	get_nickname(void) const;
  virtual std::string	get_adress(void) const;
  virtual char		get_status(void) const;
  virtual char		get_module(void) const;
  virtual std::string	get_login(void) const;
  virtual std::string	get_psw(void) const;
  virtual void		set_id(int new_id);
  virtual void		set_phone(std::string new_phone);
  virtual void		set_birth(std::string new_birth);
  virtual void		set_name(std::string new_name);
  virtual void		set_surname(std::string);
  virtual void		set_nickname(std::string new_nickname);
  virtual void		set_adress(std::string);
  virtual void		set_status(char new_status);
  virtual void		set_module(char new_module);
  virtual void		set_login(std::string new_login);
  virtual void		set_psw(std::string);

protected:
  int			_id;
  std::string		_phone;
  std::string		_birth;
  std::string		_name;
  std::string		_surname;
  std::string		_nickname;
  std::string		_adress;
  char			_status;
  char			_module;
  std::string		_login;
  std::string		_psw;
  
private:

};

#endif
