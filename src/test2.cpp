// test the effect of lasan
#include <iostream>

int main(void)
{
    // invalid access: stack variable out of bound
    int32_t array[5] = {1, 2, 3, 4, 5};
    std::cout << "array[5] is " << array[5] << '\n';
    // invalid access: access deleted object
    int32_t *ptr1 = new int32_t(60);
    std::cout << *ptr1 << '\n';
    delete ptr1;
    std::cout << *ptr1 << '\n';
    *ptr1 = 2;
    std::cout << *ptr1 << '\n';
    // invalid access: heap variable out of bound
    int32_t *ptr2 = new int32_t[2]{60, 80};
    std::cout << ptr2[3] << '\n';
    // deleter mismatch
    delete ptr2;
    // delete[] ptr2;
    return 0;
}