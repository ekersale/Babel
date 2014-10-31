/*
** Factory.h for test in /home/napsters/Git/babel/Test
** 
** Made by Sliman Desmars
** Login   <desmar_s@epitech.net>
** 
** Started on  Tue Oct 28 03:17:10 2014 Sliman Desmars
// Last update Tue Oct 28 07:35:53 2014 Sliman Desmars
*/


#include	<iostream>

#include	"Inscription.h"

View		*Inscription::Clone() const
{
  return new Inscription(*this);
}

void		Inscription::load()
{
  std::cout << "on load la fenêtre d'inscription" << std::endl;
}

