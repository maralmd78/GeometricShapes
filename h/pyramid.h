#ifndef _PYRAMID_H_
#define _PYRAMID_H_

#include <iostream>
#include "3Dshape.h"

class Pyramid : public _3Dshape
{
public:
    Pyramid(double h, _2Dshape* base, size_t pharaoh);
    Pyramid(const Pyramid& p);
    Pyramid(Pyramid&& p);
    Pyramid() = default;
    ~Pyramid();
    double volume() override;
    double area() override;
    friend std::ostream& operator<<(std::ostream& os, const Pyramid& p);

private:
    char* pharaoh;
};

#endif
