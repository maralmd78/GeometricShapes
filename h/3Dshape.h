#ifndef _3DSHAPE_H_
#define _3DSHAPE_H_

#include <iostream>
#include "2Dshape.h"

class _3Dshape
{
public:
    _3Dshape(const char* type, double h, _2Dshape* base);
    virtual double volume() = 0;
    virtual double area() = 0;
    
protected:
    _2Dshape* base;
    double height;
    const char* type;
};

#endif
