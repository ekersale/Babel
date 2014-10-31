#ifndef	__IBABELSOUND_H__
#define __IBABELSOUND_H__

class IBabelSound
{
public:
   virtual bool initializePA(void)=0;
   virtual bool initializeOutput(void)=0;
   virtual bool initializeInput(void)=0;
   virtual bool readStream(void)=0;
   virtual bool writeStream(void)=0;

protected:
private:

};

#endif
