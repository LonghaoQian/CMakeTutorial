// test branch prediction
#include <iostream>
#include <vector>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <random>

int64_t GetSum(const std::vector<int32_t>& input)
{
    int64_t res = 0;
    for(uint32_t i = 0; i < 20; i++) {
        for(auto& t : input) {
            if(t < 10) {
                res++;
            }
        }
    }
    return res;
}

int main(void)
{
    constexpr uint32_t SIZE = 20000000; // 1 million random numbers
    std::vector<int32_t> b;
    b.reserve(SIZE);
    std::default_random_engine generator;
    std::uniform_int_distribution<int32_t> distrubution(1, 100);
    for(uint32_t i = 0; i < SIZE; i++) {
        b.emplace_back(distrubution(generator));
    }
    auto c = b; // make a copy
    // sort b from smallest to greatest
    std::sort(b.begin(), b.end());
    auto t1 = std::chrono::steady_clock::now();
    auto res1 = GetSum(b);
    auto t2 = std::chrono::steady_clock::now();
    std::cout<<"vector b counting res: "<<res1<<". "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
    <<" ns has passed.\n";
    auto t3 = std::chrono::steady_clock::now();
    auto res2 = GetSum(c);
    auto t4 = std::chrono::steady_clock::now();
    std::cout<<"vector c counting res: "<<res2<<". "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count()
    <<" ns has passed.\n";
    return 0;
}