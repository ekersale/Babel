#ifndef	__IMODULE_H__
#define __IMODULE_H__

class IModule
{
public:
   virtual IModule * createObject(void)=0;

private:

};

#endif
