#include "rectangle.h"


Rectangle::Rectangle(double l, double w)
    : _2Dshape{"rectangle", 4}
    , length { l }
    , width { w }
{
    std::cout << "Rectangle constructor" << std::endl;
}

void Rectangle::disp()
{
    std::cout << "disp" << std::endl;
    for(size_t i{}; i < static_cast<size_t>(length); i++ )
        std::cout << "*" << "  ";
    std::cout << std::endl;
    for (size_t i{}; i < static_cast<size_t>(width)-2; i++)
    {
        std::cout << "*";
        for (size_t i{}; i < static_cast<size_t>(length)-2; i++)
        {
            std::cout<< "    ";
        }
        std::cout << "*" << std::endl;        
    }

    for(size_t i{}; i < static_cast<size_t>(length); i++ )
        std::cout << "*" << "  ";
    std::cout << std::endl;
}

double Rectangle::perimeter()
{
    double perimeter = (length + width) * 2;
    return perimeter;
}

double Rectangle::area()
{
    double area = length * width;
    return area;
}