#include <iostream>
#include "constants.h"

// using namespace std; // Not recommended

extern int g_a;

extern const int g_b;
//extern constexpr int g_c;

extern int g_d;
extern const int g_e;

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

    return 0;
}