#include <iostream>

using namespace std;

int readNumber();
void writeAnswer(int a);

int main()
{
    int x { readNumber() };
    int y { readNumber() };
    writeAnswer(x + y);

    return 0;
}