#ifndef TEST_LIB_C_H
#define TEST_LIB_C_H

#include <iostream>
#include <array>
#include <vector>

namespace LibC
{
    void Func1(void) { std::cout << "Lib C Func1 called!\n"; }
    // a customized template vector
    constexpr size_t DEFAULT_SIZE = 16;
    constexpr size_t DYNAMIC_SIZE = 0;
    template <typename T, size_t n = DEFAULT_SIZE>
    class MyContainer {
    public:
    MyContainer(void) { std::cout<<"container with fixed size is used!\n"; }
    void PushBack(T&& input) {
        // use placement new
        if (currSize >= maxSize) {
            return;
        }
        currSize++;
        data[currSize - 1] = std::forward<T>(input);
    }
    T& operator[](size_t i) {
        return data[i];
    }
    void PopBack(void) {
        if (currSize != 0) {
            currSize--;
        }
    }
    private:
    std::array<T, n> data;
    std::size_t currSize = 0; // actual size
    std::size_t maxSize = n; // max size
    };
    // partial specialization
    template<typename T>
    class MyContainer<T, DYNAMIC_SIZE> {
    public:

    private:
    std::vector<T> data;
    };
}

#endif