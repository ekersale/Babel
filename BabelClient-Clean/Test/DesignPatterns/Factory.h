/*
** Factory.h for test in /home/napsters/Git/babel/Test
** 
** Made by Sliman Desmars
** Login   <desmar_s@epitech.net>
** 
** Started on  Tue Oct 28 03:17:10 2014 Sliman Desmars
** Last update Tue Oct 28 03:34:41 2014 Sliman Desmars
*/

#ifndef	__FACTORY_H__
#define	__FACTORY_H__

#include	<map>
#include	<string>

#include	"View.h"

class	Factory
{
 public:
  static	std::map<std::string, View *> m_map;
  static	void Register(const std::string &key, View *obj);
  View		*create(const std::string &key) const;
};

#endif
