#include <iostream>

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

    return 0; 
}