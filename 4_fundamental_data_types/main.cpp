#include <iostream>

int main()
{
    /* Size check */
    // std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
    // std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
    // std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";
    // std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n";
    // std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n";
    // std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
    // std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
    // std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
    // std::cout << "long long:\t" << sizeof(long long) << " bytes\n";
    // std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
    // std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
    // std::cout << "long double:\t" << sizeof(long double) << " bytes\n";

    /*
    The user is asked to enter 2 floating point numbers (use doubles). 
    The user is then asked to enter one of the following mathematical symbols: +, -, *, or /. 
    The program computes the answer on the two numbers the user entered and prints the results. 
    If the user enters an invalid symbol, the program should print nothing.

    std::cout << "Enter a dobule value: ";
    double x {};
    std::cin >> x;
    std::cout << "Enter a dobule value: ";
    double y {};
    std::cin >> y;
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char c {};
    std::cin >> c;

    if(c == '+')
    {
        std::cout << x << " + " << y << " is " << x + y << '\n';
    }
    else if(c == '-')
    {
        std::cout << x << " - " << y << " is " << x - y << '\n';
    }
    else if(c == '*')
    {
        std::cout << x << " * " << y << " is " << x * y << '\n';
    }
    else if(c == '/')
    {
        std::cout << x << " / " << y << " is " << x / y << '\n';
    }
    */

    /*
    Write a short program to simulate a ball being dropped off of a tower. 
    To start, the user should be asked for the height of the tower in meters. 
    Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start). 
    Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. 
    The ball should not go underneath the ground (height 0).

    Use a function to calculate the height of the ball after x seconds. 
    The function can calculate how far the ball has fallen after x seconds using the following formula: distance fallen = gravity_constant * x_seconds2 / 2
    */
    std::cout << "Enter the height of the tower in meters: ";
    double height {};
    std::cin >> height;
    double distance_fallen = height;
    double sec = 0;
    constexpr double gravity_constant = 9.8;

    while(distance_fallen > 0)
    {
        std::cout << "At " << sec << " seconds, the ball is at height: " << distance_fallen << " meters\n";
        sec += 1.0;
        distance_fallen = height - gravity_constant * sec * sec / 2.0;
    }
    std::cout << "At " << sec << " seconds, the ball is on the ground.\n";

    return 0;
}