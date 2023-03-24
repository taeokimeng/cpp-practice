#include <iostream>
#include <typeinfo>
#include <cxxabi.h>
#include <string> // for std::string
#include <vector> // for std::vector
#include <utility> // for std::pair
#include <string_view>
#include "add.h" // import the function template definition

using VectPairSI = std::vector<std::pair<std::string, int>>; // make VectPairSI an alias for this crazy type

bool hasDuplicates(VectPairSI pairlist) // use VectPairSI in a function parameter
{
    // some code here
    return false;
}

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

template <typename T, typename U>
auto max(T x, U y)
{
    return (x < y) ? y : x;
}

int main()
{
    int i{2};
    double d{3.5};
    short a{4};
    short b{5};
    
    std::cout << typeid(i + d).name() << ' ' << i + d << '\n';
    std::cout << typeid(a + b).name() << ' ' << a + b << '\n';
    std::cout << typeid(5u-10).name() << ' ' << 5u - 10 << '\n';
    std::cout << std::boolalpha << (-3 < 5u) << '\n';

    char * name = abi::__cxa_demangle(typeid(5u-10).name(), 0, 0, 0);
    std::cout << name << std::endl;
    free(name);

    char c{'a'};
    std::cout << c << ' ' << static_cast<int>(c) << '\n';

    VectPairSI pairlist; // instantiate a VectPairSI variable

    // Type deduction
    auto d_d{5.0};

    const int x { 5 };  // x has type const int
    auto y { x };       // y will be type int (const is dropped)

    const auto z { x }; // z will be type const int (const is reapplied)

    using namespace std::literals; // easiest way to access the s and sv suffixes

    auto s1 { "goo"s };  // "goo"s is a std::string literal, so s1 will be deduced as a std::string
    auto s2 { "moo"sv }; // "moo"sv is a std::string_view literal, so s2 will be deduced as a std::string_view

    std::cout << max<int>(1, 2) << '\n'; // instantiates and calls function max<int>(int, int)
    std::cout << max<double>(1, 2) << '\n'; // instantiates and calls function max<double>(double, double)

    std::cout << addOne(1) << '\n';
    std::cout << addOne(2.3) << '\n';

    std::cout << max(static_cast<double>(2), 3.5) << '\n'; // convert our int to a double so we can call max(double, double)
    std::cout << max<double>(2, 3.5) << '\n'; // we've provided actual type double, so the compiler won't use template argument deduction

    std::cout << max(2, 3.5) << '\n';
    
    return 0;
}