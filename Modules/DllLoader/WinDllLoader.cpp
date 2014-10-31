#include "WinDllLoader.h"

WinDllLoader::WinDllLoader()
{
}

WinDllLoader::WinDllLoader(const WinDllLoader& oldWinDllLoader)
{
   _modules = oldWinDllLoader._modules;
   _handle = oldWinDllLoader._handle;
}

WinDllLoader::~WinDllLoader()
{
   // TODO : implement
}

void		*WinDllLoader::open(void)
{   // TODO : implement
}

char		*WinDllLoader::error(void)
{
   // TODO : implement
}

void		*WinDllLoader::sym(void)
{
   // TODO : implement
}

int		WinDllLoader::close(void)
{
   // TODO : implement
}

int		WinDllLoader::getNbrLibrary(void)
{
   // TODO : implement
}

std::vector<std::string>	WinDllLoader::GetNameLibrary(void)
{
   // TODO : implement
}

bool				WinDllLoader::print_error(void)
{
   // TODO : implement
}

IModule				**WinDllLoader::get_modules(void) const
{
   return _modules;
}

void				*WinDllLoader::get_handle(void) const
{
   return _handle;
}

void				WinDllLoader::set_modules(IModule** new_modules)
{
   _modules = new_modules;
}

void				WinDllLoader::set_handle(void * new_handle)
{
   _handle = new_handle;
}

