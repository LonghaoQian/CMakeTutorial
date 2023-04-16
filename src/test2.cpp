// test the effect of lasan
#include <iostream>

int main(void)
{
    int *ptr1 = new int(60);
    std::cout<<*ptr1<<'\n';
    delete ptr1;
    int *ptr2 = new int(70);
    std::cout<<*ptr1<<'\n';
    *ptr1 = 2;
    std::cout<<*ptr2<<'\n';
    return 0;
}