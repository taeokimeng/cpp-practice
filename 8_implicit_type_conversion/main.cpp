#include <iostream>
#include <typeinfo>
#include <cxxabi.h>
#include <string> // for std::string
#include <vector> // for std::vector
#include <utility> // for std::pair

using VectPairSI = std::vector<std::pair<std::string, int>>; // make VectPairSI an alias for this crazy type

bool hasDuplicates(VectPairSI pairlist) // use VectPairSI in a function parameter
{
    // some code here
    return false;
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

    return 0;
}