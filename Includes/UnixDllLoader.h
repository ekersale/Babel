#ifndef	__UNIXDLLLOADER_H__
#define __UNIXDLLLOADER_H__

#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

#include	<dlfcn.h>

#include	"IDllLoader.hh"
#include	"IModule.hh"

class UnixDllLoader : public IDllLoader
{
private:
  IModule				**_modules;
  void					*_handle;
  std::map<std::string, IModule *>	_moduleMap;

public:
  UnixDllLoader();
  UnixDllLoader(const UnixDllLoader& oldUnixDllLoader);
  ~UnixDllLoader();
  void				*open(const char *, int);
  char				*error(void);
  void				*sym(void *, const char *);
  int				close(void *);
  int				getNbrLibrary(void);
  std::vector<std::string>	getNameLibrary(void);
  void				print_error(void);
  IModule			**get_modules(void) const;
  void				*get_handle(void) const;
  void				set_modules(IModule** new_modules);
  void				set_handle(void * new_handle);
  bool				print_error(const std::string &);
};

#endif
