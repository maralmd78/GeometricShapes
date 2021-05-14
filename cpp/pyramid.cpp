#include "pyramid.h"
#include "rectangle.h"
#include "triangle.h"
#include <cstring>
#include <cmath>

Pyramid::Pyramid(double h, _2Dshape* base, size_t _pharaoh)
    : _3Dshape{"Pyramid", h, base}
{
    std::cout << "Pyramid constructor" << std::endl;
    if(_pharaoh == 1 ){
       // this->pharaoh =  "Tutankhamun";
        this->pharaoh = new char[12];
        strcpy(pharaoh,"Tutankhamun");  
    }
    else if(_pharaoh == 2)
    {
        this->pharaoh = new char[9];
        strcpy(pharaoh,"Ramesses"); 
    }
    else if(_pharaoh == 3)
    {
        this->pharaoh = new char[10];
        strcpy(pharaoh,"Cleopatra"); 
    }
    
}

Pyramid::Pyramid(const Pyramid& p)
    : _3Dshape{"Pyramid", p.height, p.base }
{
    std::cout << "Pyramid copy constructor" << std::endl;

    if(! strcmp(p.pharaoh, "Tutankhamun"))
    {
        this->pharaoh = new char[12];
        strcpy(this->pharaoh, p.pharaoh);
    }
    else if(! strcmp(p.pharaoh, "Ramesses") )
    {
        this->pharaoh = new char[9];
        strcpy(this->pharaoh, p.pharaoh);
    }
    else if(! strcmp(p.pharaoh, "Cleopatra"))
    {
        this->pharaoh = new char[10];
        strcpy(this->pharaoh, p.pharaoh);
    }
}

Pyramid::Pyramid( Pyramid&& p)
    :_3Dshape{ std::move(p)}
{
    std::cout << "Pyramid move constructor" << std::endl;
    this->pharaoh = p.pharaoh;
    p.pharaoh = nullptr;
    
}

Pyramid::~Pyramid()
{
    std::cout << "Pyramid destructor" << std::endl;
    //if (pharaoh != nullptr)
        delete pharaoh;
    pharaoh = nullptr;
}

Pyramid& Pyramid::operator=(const Pyramid& p)
{
    std::cout << "operator = copy version" << std::endl;
    if(this == &p)
        return *this;
    delete pharaoh;
    if(! strcmp(p.pharaoh, "Tutankhamun"))
    {
        this->pharaoh = new char[12];
        strcpy(this->pharaoh, p.pharaoh);
    }
    else if(! strcmp(p.pharaoh, "Ramesses") )
    {
        this->pharaoh = new char[9];
        strcpy(this->pharaoh, p.pharaoh);
    }
    else if(! strcmp(p.pharaoh, "Cleopatra"))
    {
        this->pharaoh = new char[10];
        strcpy(this->pharaoh, p.pharaoh);
    }

    return *this;
}


double Pyramid::volume()
{
    return ((this->base->area()) * (this->height) / 3);
}


double Pyramid::area()
{
    double area{};
    if(! strcmp(this->base->getName(), "square"))
    {
        double h = sqrt(pow(this->base->perimeter()/8 , 2) + pow(this->height , 2));
        area = this->base->area() + 4 * ((this->base->perimeter()/4) * h / 2);
    }

    else if(! strcmp(this->base->getName(), "rectangle"))
    {
        Rectangle* temp = reinterpret_cast<Rectangle*>(this->base);
        double h1 = sqrt(pow(this->height,2) + pow(temp->length/2 , 2));
        std::cout << h1 << std::endl;
        double h2 = sqrt(pow(this->height , 2) + pow(temp->width/2 , 2));
        std::cout << h2 << std::endl;
        area = this->base->area() + (h1 * temp->width) + (h2 * temp->length);
    }

    else if(! strcmp(this->base->getName(),"triangle"))
    {
        Triangle* temp = reinterpret_cast<Triangle*>(this->base);
        
        double base_height = sqrt(pow(temp->side, 2) - pow(temp->base/2, 2));
        double N2 = ((temp->side/2) * (temp->base/2)) / base_height;
        double h2 = sqrt(pow(this->height, 2) + pow(N2, 2));
        double h3 { h2 };
        std::cout << h2 <<"        "<<N2 <<std::endl;
        double N = ((temp->side/2) * temp->side)/(base_height);
        double N1 = base_height - N;
        double h1 = sqrt(pow(this->height, 2) + pow(N1 , 2));

        area = this->base->area() + (temp->side) * h2/2 + (temp->side) * h3/2 + (temp->base) * h1/2;
 
    }

    return area;

}

std::ostream& operator<<(std::ostream& os, const Pyramid& p)
{
    os << "base of pyramid is" << " ";
    os << p.base->getName() << " ";
    os << "and its height is ";
    os << p.height;
    os << std::endl;

    return os;
}