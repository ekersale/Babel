//
// main.cpp for Babel in /home/napsters/Git/babel/Client
// 
// Made by Sliman Desmars
// Login   <desmar_s@epitech.net>
// 
// Started on  Tue Oct 28 01:37:29 2014 Sliman Desmars
// Last update Thu Oct 30 18:33:04 2014 Sliman Desmars
//

#include		<QApplication>

#include		"../Includes/Client.h"
#include		"../Includes/View.h"
#include		"../Includes/Factory.h"
#include		"../Includes/Inscription.h"
#include		"../Includes/UnixDllLoader.h"
#include		"../Includes/IModule.h"

#include		<fstream>
#include		<iostream>

#include		<dirent.h>
#include		<dlfcn.h>
#include		<stdio.h>
#include		<stdlib.h>

void					loadLibrary(std::vector<std::string> _files, IDllLoader *loader)
{
  IModule				*(*external_creator)();
  
  for (std::vector<std::string>::iterator it = _files.begin() ; it != _files.end(); ++it)
    {
      void				*handle;
      std::string			tmp;
      std::map<std::string,IModule *>	moduleList;

      tmp = *it;
      handle = loader->open(tmp.c_str(), RTLD_LAZY);
      if (handle == NULL)
	{
	  loader->print_error("Open");
	  return; 
	}
      else
	{
	  external_creator = reinterpret_cast<IModule *(*)()>(loader->sym(handle, "create_module"));
	  IModule			*module;

	  module = external_creator();
	  moduleList.insert(std::pair<std::string, IModule *>(tmp, module));
	}
      std::cout << ' ' << *it;
    }
}

bool			getLibrary(char **argv, IDllLoader *loader)
{
  std::vector<std::string>	_files;  

  DIR			*folder;
  
  folder = opendir(argv[1]);
  if (folder != NULL)
    {
      struct	dirent	*ent;

      while ((ent = readdir(folder)) != NULL)
  	{
	  std::string	tmp;
	  
	  tmp = ent->d_name;
	  if (tmp.compare(".") == 0)
	    continue;
	  if (tmp.compare("..") == 0)
	    continue;
	  _files.push_back(tmp);
  	}
    }
  else
    {
      loader->print_error("Open Library Folder");
      return false;
    }
  
  loadLibrary(_files, loader);
  return true;
}

int			main(int argc, char **argv)
{
  QApplication a(argc, argv);
  Client		cli;
  // Factory		vues; // liste des vues !
  // View			*subscribe;
  
  // static_cast<void>(argc);
  // static_cast<void>(argv);
  // Factory::Register("Inscription", new Inscription);
  
  // subscribe = vues.create("Inscription");
  // subscribe->load();
  // IDllLoader	*loader = new UnixDllLoader();
  
  Inscription		view;
  view.show();
  
  // if (argc < 2)
  //   {
  //     std::cerr << "Bad number param" << std::endl;
  //     std::cout << "USAGE ! : [Babel][DOSSIER DES LIBRAIRIE]" << std::endl; 
  //     return -1;
  //   }
  // else
  //   {
  //     if (getLibrary(argv, loader) == false) //IF UNIX
  // 	loader->print_error("Load librairies");
  //   }
  // return 0;
  return a.exec();
}
