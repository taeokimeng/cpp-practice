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

    return 0;
}