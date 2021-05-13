#include <iostream>
// #include "2Dshape.h"
// #include "rectangle.h"
// #include "square.h"
// #include "triangle.h"
// #include "3Dshape.h"
// #include "prism.h"
// #include "pyramid.h"
#include "gtest/gtest.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "RUNNING TESTS ..." << std::endl;
    int ret{RUN_ALL_TESTS()};
    if (!ret)
        std::cout << "<<<SUCCESS>>>" << std::endl;
    else
        std::cout << "FAILED" << std::endl;
    return 0;
}

