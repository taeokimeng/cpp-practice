#include <iostream>
#include <string>
#include <cassert>
#include <string_view>
#include <cstddef> // for std::nullptr_t

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

void print(const int* ptr)
{
    assert(ptr); // fail the program in debug mode if a null pointer is passed (since this should never happen)

    // (optionally) handle this as an error case in production mode so we don't crash if it does happen
	if (!ptr)
		return;

	std::cout << *ptr << '\n';
}

void print(std::nullptr_t)
{
    std::cout << "in print(std::nullptr_t)\n";
}

void print(int*)
{
    std::cout << "in print(int*)\n";
}

void printByReference(const int& ref) // The function parameter is a reference that binds to the argument
{
    std::cout << ref << '\n'; // print the value via the reference
}

void greet(std::string_view name)
{
    std::cout << "Hello " << name << '\n';
}

void greet()
{
    greet("guest");
}

void nullify(int*& refptr) // refptr is now a reference to a pointer
{
    refptr = nullptr; // Make the function parameter a null pointer
}

const std::string& firstAlphabetical(const std::string& a, const std::string& b)
{
    return (a < b) ? a : b;
}

int& max(int& x, int& y)
{
    return (x > y) ? x : y;
}

const std::string& getConstRef(); // some function that returns a const reference
const std::string* const getConstPtr(); // some function that returns a const pointer to a const value

int main()
{
    int x { 5 };
    int& ref { x }; // valid: lvalue reference bound to a modifiable lvalue
    int* ptr{ &x }; // ptr points to x

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

    int* n_ptr {}; // null pointer
    int* null_ptr {nullptr}; // null pointer

    const int c_x{5};
    const int* ptr2c{&x}; // pointer to a "const int"
    int* const c_ptr { &x }; // const pointer
    const int* const c_ptr2c { &x }; // a const pointer to a const value

    print(&x);
    // print(nullptr);

    printByReference(5); // valid (because the parameter is a const reference)

    greet();
    std::string joe{"Joe"};
    greet(joe);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    nullify(ptr);
    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    print(nullptr); // calls print(std::nullptr_t)
    print(ptr); // calls print(int*)
    ptr = nullptr;
    print(ptr); // calls print(int*) (since ptr has type int*)

    std::string hello {"Hello"};
    std::string world {"World"};

    std::cout << firstAlphabetical(hello, world) << '\n';

    int a{5};
    int b{6};

    max(a, b) = 7;

    std::cout << a << b << '\n';

/*
    const int x;    // this const applies to x, so it is top-level
    int* const ptr; // this const applies to ptr, so it is top-level

    const int& ref; // this const applies to the object being referenced, so it is low-level
    const int* ptr; // this const applies to the object being pointed to, so it is low-level

    const int* const ptr; // the left const is low-level, the right const is top-level

    auto ref1{ getConstRef() };        // std::string (top-level const and reference dropped)
    const auto ref2{ getConstRef() };  // const std::string (const reapplied, reference dropped)

    auto& ref3{ getConstRef() };       // const std::string& (reference reapplied, low-level const not dropped)
    const auto& ref4{ getConstRef() }; // const std::string& (reference and const reapplied)


    auto ptr1{ getConstPtr() };  // const std::string*
    auto* ptr2{ getConstPtr() }; // const std::string*

    auto const ptr3{ getConstPtr() };  // const std::string* const
    const auto ptr4{ getConstPtr() };  // const std::string* const

    auto* const ptr5{ getConstPtr() }; // const std::string* const
    const auto* ptr6{ getConstPtr() }; // const std::string*

    const auto const ptr7{ getConstPtr() };  // error: const qualifer can not be applied twice
    const auto* const ptr8{ getConstPtr() }; // const std::string* const

*/
    return 0;
}