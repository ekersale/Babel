/*
** Factory.h for test in /home/napsters/Git/babel/Test
** 
** Made by Sliman Desmars
** Login   <desmar_s@epitech.net>
** 
** Started on  Tue Oct 28 03:17:10 2014 Sliman Desmars
// Last update Tue Oct 28 07:44:48 2014 Sliman Desmars
*/

#include	<iostream>

#include	"View.h"
#include	"Home.h"

View		*Home::Clone() const
{
  return new Home(*this);
}

void		Home::load()
{
  std::cout << "Fenêtre Home se load" << std::endl;
}
