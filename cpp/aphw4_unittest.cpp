#include <limits.h>
#include <iostream>
#include "gtest/gtest.h"
#include "rectangle.h"
#include "triangle.h"
#include "square.h"
#include "prism.h"
#include "pyramid.h"

namespace
{


TEST(APHW4Test, Test1)
{
    Triangle t{8, 5};
    Rectangle r{4, 6};
    t.disp();
    r.disp();
    EXPECT_EQ(true, (r.perimeter() == 20) && (t.area() == 12));
}


TEST(APHW4Test, Test2)
{
    Square s{3};
    Prism p{5, &s};
    std::cout << p;
    EXPECT_EQ(true, (p.volume() == 45) && (p.area() == 78));    
}

TEST(APHW4Test, Test3)
{
    Triangle t{4, 6};
    Pyramid p1{3 , &t, 1};
    Rectangle r{6, 4};
    Pyramid p2{4, &r, 2};
    EXPECT_EQ(true, (p1.area() > 38)&&(p1.area() < 38.3));   //ans: 38.18
    EXPECT_EQ(true, (p2.area() < 71)&&(p2.area() > 70.5));   //ans: 70.83
    EXPECT_EQ(true, (p2.volume() == 32));   
}

TEST(APHW4Test, Test4)
{
    Square s{1};
    Pyramid p{2, &s, 3};
    Pyramid p2{p};
    p.~Pyramid();
    std::cout << p2;
    Pyramid p3{5, &s, 1};
    std::swap(p2, p3); 
    EXPECT_EQ(true, (2 == 1+1)); 
}




}
