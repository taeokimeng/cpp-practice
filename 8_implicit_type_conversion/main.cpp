#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

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

    return 0;
}