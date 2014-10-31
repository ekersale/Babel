/*
** Factory.h for test in /home/napsters/Git/babel/Test
** 
** Made by Sliman Desmars
** Login   <desmar_s@epitech.net>
** 
** Started on  Tue Oct 28 03:17:10 2014 Sliman Desmars
// Last update Tue Oct 28 08:15:00 2014 Sliman Desmars
*/


#include	"../Includes/Factory.h"


std::map<std::string, View *>Factory::m_map = std::map<std::string, View *>();

void		Factory::Register(const std::string &key, View *obj)
{
  if (m_map.find(key) == m_map.end())
    m_map[key] = obj;
}

View		*Factory::create(const std::string &key) const
{
  View		*tmp;

  tmp = 0;
  std::map<std::string, View *>::const_iterator it;

  it = this->m_map.find(key);
  
  if (it != m_map.end())
    tmp = ((*it).second)->Clone();
  
  return tmp;
}

