/*
** Factory.h for test in /home/napsters/Git/babel/Test
** 
** Made by Sliman Desmars
** Login   <desmar_s@epitech.net>
** 
** Started on  Tue Oct 28 03:17:10 2014 Sliman Desmars
** Last update Tue Oct 28 03:37:01 2014 Sliman Desmars
*/

#ifndef	__VIEW_H__
#define	__VIEW_H__

#include	<map>
#include	<string>

template <class	T> class Prototype
{
 public:
  virtual	~Prototype(){}
  virtual	T *Clone() const = 0;
};

class	View : public Prototype<View>
{
 public:
  virtual	void	load() =0;
};

#endif
