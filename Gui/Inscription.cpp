/*
** Factory.h for test in /home/napsters/Git/babel/Test
** 
** Made by Sliman Desmars
** Login   <desmar_s@epitech.net>
** 
** Started on  Tue Oct 28 03:17:10 2014 Sliman Desmars
// Last update Thu Oct 30 19:16:15 2014 Sliman Desmars
*/


#include	<iostream>

#include	<QMainWindow>

#include	"../Includes/Inscription.h"

// #include	"ui_inscription.h"

//Inscription::Inscription(QWidget *parent) : QMainWindow(parent)  //, ui(new Ui::Inscription)

// Inscription::Inscription(QWidget *parent) : QMainWindow(parent)
// {
//   // ui->setupUi(this);
//   // std::cout << "On passe dans le constructeur d'Inscription après le setupUi " << std::endl;
// }

// View		*Inscription::Clone() const
// {
//   return new Inscription(*this);
// }

Inscription::Inscription(QWidget *parent) : QMainWindow(parent)
{
  //ui->setupUi(this);
  this->setWindowTitle("test");
}

Inscription::~Inscription()
{
}

// void		Inscription::load()
// {
//   std::cout << "on load la fenêtre d'inscription" << std::endl;
// }

