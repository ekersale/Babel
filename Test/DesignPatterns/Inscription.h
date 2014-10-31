/*
** Factory.h for test in /home/napsters/Git/babel/Test
** 
** Made by Sliman Desmars
** Login   <desmar_s@epitech.net>
** 
** Started on  Tue Oct 28 03:17:10 2014 Sliman Desmars
** Last update Tue Oct 28 03:34:27 2014 Sliman Desmars
*/

#ifndef	__INSCRIPTION_H__
#define	__INSCRIPTION_H__

#include	<map>
#include	<string>

#include	"View.h"

class		Inscription : public View
{
 public:
  View		*Clone() const;
  void		load();
};

#endif
