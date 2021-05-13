#include "prism.h"
#include "triangle.h"
#include <cstring>
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
    double area{};
    if(! strcmp(this->base->getName(), "triangle"))
    {
        //area = 2*(this->base->area()) + 3*(this->height * (this->base->perimeter()/3));
        Triangle* temp1 = reinterpret_cast<Triangle*>(this->base);
        // char** temp2 = reinterpret_cast<char**>(&temp1);
        // // temp2++;
        // // size_t* temp3 = reinterpret_cast<size_t*>(temp2);
        // std::cout << *temp2 << std::endl;
        std::cout << temp1->base << std::endl;
        area = 2 * (this->base->area()) + 2 * (this->height * (temp1->side)) + (this->height * (temp1->base));


    }
   
    else if( ! strcmp(this->base->getName(), "square"))
    {
        area = 2 * (this->base->area()) + 4*(this->height * (this->base->perimeter()/4));
        std::cout << "ok" << std::endl;
    }
    else if(! strcmp(this->base->getName(), "rectangle"))
    {
        area = 2 * (this->base->area()) + 2 * (this->height) * (this->base->perimeter()/2);
    }

    return area;
    
        
}

std::ostream& operator<<(std::ostream& os, const Prism& p)
{
    os << "base of prism is" << " ";
    os << p.base->getName() << " ";
    os << "and its height is ";
    os << p.height;
    os << std::endl;

    return os;

}