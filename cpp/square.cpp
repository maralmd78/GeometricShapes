#include "square.h"
Square::Square(double s)
    : _2Dshape{"square", 4}
    , side { s }
{
    std::cout << "Square constructor" << std::endl;
}

void Square::disp()
{
    for(size_t i{}; i < static_cast<size_t>(side); i++)
        std::cout << "*"<<"\t";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    for (size_t i{}; i < static_cast<size_t>(side)-2; i++)
    {
        std::cout << "*";
        for (size_t i{}; i < static_cast<size_t>(side)-1; i++)
        {
            std::cout << "\t";
        }
        std::cout << "*" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

    }

     for(size_t i{}; i < static_cast<size_t>(side); i++)
        std::cout << "*"<<"\t";
    std::cout << std::endl;
    
}

double Square::perimeter()
{
    double perimeter = 4 * side;
    return perimeter;
}

double Square::area()
{
    double area = side * side;
    return area;
}