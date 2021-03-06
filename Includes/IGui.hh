#ifndef IGUI_H
#define IGUI_H

class   IGui
{
public:
    virtual bool    init() = 0;
    virtual void    load() = 0;
    virtual void    destroy() = 0;
};

#endif // IGUI_H
