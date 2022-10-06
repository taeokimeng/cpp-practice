#include <iostream>

int readNumber()
{
    int x {};

	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}

void writeAnswer(int x, int y)
{
	std::cout << "The sum is: " << x << '\n';
    std::cout << "The quotient is: " << y << '\n';
}

int main()
{
	int x { readNumber() };
    int y { readNumber() };
	
	x = x + readNumber();
	writeAnswer(x, x/y);

	return 0;
}