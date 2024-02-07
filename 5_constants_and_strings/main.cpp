#include <iostream>
#include <string> // for std::string and std::getline
#include <string_view> // C++17
#include <bitset> // for std::bitset
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

    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    std::cout << "Your name is " << name << '\n';
    std::cout << name << " has " << name.length() << " characters\n";
    std::cout << name << " has " << std::ssize(name) << " characters\n";

    return 0;
}