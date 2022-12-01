#include <iostream>

int sumTo(int num)
{
    int sum{0};

    for(int i{1}; i <= num; ++i)
    {
        sum += i;
    }

    return sum;
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

    return 0; 
}