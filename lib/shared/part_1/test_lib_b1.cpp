#include "test_lib_b1.h"
#include "test_lib_b4.h"
#include <iostream>

namespace LibB
{
    void Func1(void)
    {
        std::cout << "Lib B Func1 called!\n";
        Func6();
    }
}