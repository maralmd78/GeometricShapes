#include "prism.h"
Prism::Prism(double h, _2Dshape* base)
    :_3Dshape{"Prism", h, base}
{
    std::cout << "Prism constructor" << std::endl;
}

double Prism::volume()
{
    double volume{};
    volume = (this->base->area()) * (this->height);
    return volume;

}

double Prism::area()
{
    std::cout << std::endl;
}


