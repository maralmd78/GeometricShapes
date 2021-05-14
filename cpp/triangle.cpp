#include "triangle.h"

Triangle::Triangle(double b, double s)
    : _2Dshape{"triangle", 3}
    , base { b }
    , side { s }
{
    std::cout << "Triangle constructor" << std::endl;
}

void Triangle::disp()
{
    for(size_t i{1}; i <= side; i++)
    {
        for(size_t s{i}; s < side; s++)
            std::cout << " ";
        for(size_t j{1}; j <= (2*side -1); j++)
        {
            if(i == side || j ==1 || j== 2*i -1)
            {
                std::cout << "*";
            }
                
            else    
                std::cout << " ";
        }
        std::cout << std::endl;
    }


}

double Triangle::perimeter()
{  
   
   return (base + 2 * side);
}

double Triangle::area()
{
    
    return ((sqrt((side * side) - (base* base /4))) * base) /2;

}
