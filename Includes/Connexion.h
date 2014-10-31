#ifndef	__CONNEXION_H__
#define __CONNEXION_H__

#include "IGui.h"
#include "IModule.h"

class Connexion : public IGui
{
public:
   IModule * createObject(void);
   void Load(void);
   void Destroy(void);
   char Connect(void);
   void print_error(void);
   QLineEdit * get_name(void) const;
   QLineEdit * get_password(void) const;
   QPushButton * get_btnSubscribe(void) const;
   void set_name(QLineEdit * new_name);
   void set_password(QLineEdit * new_password);
   void set_btnSubscribe(QPushButton * new_btnSubscribe);
   Connexion();
   Connexion(const Connexion& oldConnexion);
   ~Connexion();

protected:
private:
   QLineEdit * _name;
   QLineEdit * _password;
   QPushButton * _btnSubscribe;


};

#endif
