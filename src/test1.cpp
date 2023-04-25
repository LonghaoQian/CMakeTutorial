// test the effect of compiler optimization
#include <iostream>
#include <vector>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <random>

int main(void)
{
    std::vector<int32_t> a(10, 3);
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // sort a random sequence
    constexpr uint32_t SIZE = 1000000; // 1 million random numbers
    std::vector<int32_t> b;
    b.reserve(SIZE);
    std::default_random_engine generator;
    std::uniform_int_distribution<int32_t> distrubution(1, 100);
    for (uint32_t i = 0; i < SIZE; i++)
    {
        b.emplace_back(distrubution(generator));
    }
    auto t1 = std::chrono::steady_clock::now();
    std::sort(b.begin(), b.end(), std::greater<int32_t>());
    auto t2 = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
              << " ns has passed.\n";
    return 0;
}