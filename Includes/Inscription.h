/*
** Factory.h for test in /home/napsters/Git/babel/Test
** 
** Made by Sliman Desmars
** Login   <desmar_s@epitech.net>
** 
** Started on  Tue Oct 28 03:17:10 2014 Sliman Desmars
// Last update Fri Oct 31 15:35:54 2014 Sliman Desmars
*/

#ifndef	__INSCRIPTION_H__
#define	__INSCRIPTION_H__

#include	<map>
#include	<string>

#include	<QMainWindow>
#include	<QWidget>

// #include	"View.h"

/* namespace Ui { */
/*   class Inscription; */
/* } */


//class		Inscription : public QMainWindow, public View //public View
class		Inscription : public QMainWindow
{
  Q_OBJECT

public:
  Inscription(QWidget *parent = 0);
  // Inscription();
  ~Inscription();
  // View		*Clone() const;
  void		load();
private:
  /* Ui::Inscription	*ui; */
};

#endif
