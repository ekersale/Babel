#include	"../../Includes/UnixDllLoader.h"

UnixDllLoader::UnixDllLoader()
{
}

UnixDllLoader::UnixDllLoader(const UnixDllLoader& oldUnixDllLoader)
{
   _modules = oldUnixDllLoader._modules;
   _handle = oldUnixDllLoader._handle;
}

UnixDllLoader::~UnixDllLoader()
{
   // TODO : implement
}


void				*UnixDllLoader::open(const char *filename, int flag)
{
  void				*tmp;

  tmp = dlopen(filename, flag);
  if (tmp == NULL)
    {
      this->print_error("DLOpen");
      return NULL;
    }
  else
    return tmp;
}

char				*UnixDllLoader::error(void)
{
  return NULL;
   // TODO : implement
}

void				*UnixDllLoader::sym(void *handle, const char *symbol)
{
  return(dlsym(handle, symbol));
  
  
  
}

int				UnixDllLoader::close(void *handle)
{
  if (dlclose(handle) != 0)
    {
      this->print_error("DLClose");
      return (-1);
    }
  else
    return 0;
   // TODO : implement
}

int				UnixDllLoader::getNbrLibrary(void)
{
  return 0;
   // TODO : implement
}

std::vector<std::string>	UnixDllLoader::getNameLibrary(void)
{
  std::vector<std::string>	tab_tmp;
  std::string			tmp;

  tmp = "fuck g++";
  tab_tmp.push_back(tmp);

  return (tab_tmp);
    // TODO : implement
}

void				UnixDllLoader::print_error(void)
{
   // TODO : implement
}

IModule ** UnixDllLoader::get_modules(void) const
{
   return _modules;
}

void * UnixDllLoader::get_handle(void) const
{
   return _handle;
}

void UnixDllLoader::set_modules(IModule** new_modules)
{
   _modules = new_modules;
}

void UnixDllLoader::set_handle(void * new_handle)
{
   _handle = new_handle;
}

bool UnixDllLoader::print_error(const std::string &msg)
{
  std::cerr << "Fonction : " << msg << " a fail " << std::endl;
  return (true);
}
