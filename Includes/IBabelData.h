#ifndef	__IBABELDATA_H__
#define __IBABELDATA_H__

class IBabelData
{
public:
   virtual bool initStructure(void)=0;
   virtual bool initBits(void)=0;
   virtual bool setQuality(void)=0;
   virtual bool resetBits(void)=0;
   virtual int destroyState(void)=0;
   virtual int destroyStruct(void)=0;

protected:
private:

};

#endif
