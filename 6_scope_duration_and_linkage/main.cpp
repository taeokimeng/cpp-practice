#include <iostream>
#include "constants.h"

// using namespace std; // Not recommended

extern int g_a;

extern const int g_b;
//extern constexpr int g_c;

extern int g_d;
extern const int g_e;

bool passOrFail()
{
    static int call = 0;

    return (call++ < 3 ? true : false);
}

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    cout << g_a << ' ' << g_b <<  ' ' << g_d << ' ' << g_e << endl;

    cout << "How many students are in your class? ";
    int students{};
    cin >> students;

    if(students > constants::max_class_size)
        cout << "There are too many students in this class";
    else
        cout << "This class isn't too large";

    std::cout << endl;
    std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");

    return 0;
}