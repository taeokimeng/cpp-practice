#include <iostream>
#include <limits>
#include <random>

int sumTo(int num)
{
    int sum{0};

    for(int i{1}; i <= num; ++i)
    {
        sum += i;
    }

    return sum;
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a double value: ";
        double x{};
        std::cin >> x;

        // Check for failed extraction
        if (!std::cin) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
            std::cerr << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            ignoreLine(); // remove any extraneous input
            return x;
        }
    }
}

char getOperator()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;
        ignoreLine(); // // remove any extraneous input

        // Check whether the user entered meaningful input
        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation; // return it to the caller
        default: // otherwise tell the user what went wrong
            std::cerr << "Oops, that input is invalid.  Please try again.\n";
        }
    } // and try again
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    default: // Being robust means handling unexpected parameters as well, even though getOperator() guarantees operation is valid in this particular program
        std::cerr << "Something went wrong: printResult() got an invalid operator.\n";
    }
}

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    char ascii{'a'};

    while(ascii <= 'z')
    {
        cout << ascii << ": " << static_cast<int>(ascii) << '\n';
        ++ascii;
    }
    cout << endl;

    int start{5};
    int end{1};
    int current = start;

    while(start >= end)
    {
        while(current >= end)
        {
            cout << current << ' ';
            --current;
        }
        cout << '\n';
        --start;
        current = start;
    }

    int outer{5};
    int num_line{1};
    while(outer >= end)
    {
        int inner{5};
        while(inner >= end)
        {
            if(num_line >= inner)
                cout << inner << ' ';
            else
                cout << "  ";
            --inner;
        }
        cout << endl;
        ++num_line;
        --outer;
    }

    for(int i = 0; i <= 20; ++i)
    {
        if(i % 2 == 0)
            cout << i << endl;
    }

    cout << "sumTo(5): " << sumTo(5) << endl;

    // Calculator with error checkings
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);

    // PRNG
    std::random_device rd;
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // get 8 integers of random numbers from std::random_device for our seed
	std::mt19937 mt{ ss }; // initialize our Mersenne Twister with the std::seed_seq

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << die6(mt) << '\t'; // generate a roll of the die here

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}

    return 0; 
}