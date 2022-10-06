#include "io.h"
#include <iostream>

using namespace std;

int readNumber()
{
    int a {};

    cout << "Input: ";
    cin >> a;

    return a;
}

void writeAnswer(int a)
{
    cout << "The answer is " << a << '\n';
}