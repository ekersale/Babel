//
// main.cpp for testy in /home/napsters/Git/babel/Test
// 
// Made by Sliman Desmars
// Login   <desmar_s@epitech.net>
// 
// Started on  Tue Oct 28 03:31:44 2014 Sliman Desmars
// Last update Tue Oct 28 08:57:24 2014 Sliman Desmars
//


#include	"Factory.h"
#include	"View.h"
#include	"Inscription.h"
#include	"Home.h"

int		main()
{

  Factory	vue;
  View		*subscribe;
  View		*home;

  Factory::Register("Inscription", new Inscription);
  Factory::Register("Home", new Home);

  subscribe = vue.create("Inscription");

  subscribe->load();

  return (0);
}
