#include <bitset> // for std::bitset
#include <iostream>
#include <format> // C++20
// #include <print> // C++23

int main()
{
    std::bitset<8> bin1{ 0b1100'0101 };
    std::bitset<8> bin2{ 0xC5 };
    std::cout << std::bitset<4>{ 0b1010 } << '\n';
    std::cout << std::format("{:b}\n", 0b1010); // C++20
    std::cout << std::format("{:#b}\n", 0b1010); // C++20
    // std::println("{:b} {:#b}", 0b1010, 0b1010); // C++23

    return 0;
}