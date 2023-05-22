#include <iostream>
#include <string>

// Function-like macro that evaluates to true if the type (or object) uses 2 or fewer memory addresses worth of memory
#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))

struct S
{
    double a, b, c;
};

void printValue(std::string& y)
{
    std::cout << y << '\n';
}

void printValue(const int& y) // y is now a const reference
{
    std::cout << y << '\n';
}

int main()
{
    int x { 5 };
    int& ref { x }; // valid: lvalue reference bound to a modifiable lvalue

    const int y { 5 };
   // int& invalidRef { y };  // invalid: can't bind to a non-modifiable lvalue
   // int& invalidRef2 { 0 }; // invalid: can't bind to an r-value

    std::string s {"Hello"};
    printValue(s); // (inexpensive)

    const int z { 5 };
    printValue(z); // ok: z is a non-modifiable lvalue
    printValue(5); // ok: 5 is a literal rvalue

    std::cout << std::boolalpha; // print true or false rather than 1 or 0
    std::cout << isSmall(int) << '\n'; // true
    std::cout << isSmall(double) << '\n'; // true
    std::cout << isSmall(S) << '\n'; // false
    
    return 0;
}