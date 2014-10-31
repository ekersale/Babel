#ifndef	__IGUI_H__
#define __IGUI_H__

#include "IModule.h"

class IGui : public IModule
{
public:
   virtual void Load(void)=0;
   virtual void Destroy(void)=0;

protected:
private:

};

#endif
