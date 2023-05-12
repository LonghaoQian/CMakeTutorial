#include <iostream>
#include "test_lib_a.h"

int main(void)
{
#ifdef MAIN_FEATURE_1
    std::cout<<"main feature 1 is defined!\n";
#endif

#ifdef MAIN_FEATURE_2
    std::cout<<"main feature 2 is defined!\n";
#endif
    LibA::Func1();
    return 0;
}