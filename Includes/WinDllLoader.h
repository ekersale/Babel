#ifndef	__WINDLLLOADER_H__
#define __WINDLLLOADER_H__

#include "IDllLoader.h"
#include "IModule.h"

class WinDllLoader : public IDllLoader
{
public:
  void			*open(void);
  char			*error(void);
  void			*sym(void);
  int			close(void);
  int			getNbrLibrary(void);
  std::vector<std::string> GetNameLibrary(void);
  IModule		**get_modules(void) const;
  void			*get_handle(void) const;
  void			set_modules(IModule** new_modules);
  void			set_handle(void * new_handle);
  bool			print_error(const std::string &msg);
  WinDllLoader();
  WinDllLoader(const WinDllLoader& oldWinDllLoader);
  ~WinDllLoader();
private:
  IModule ** _modules;
  void * _handle; 
};

#endif
