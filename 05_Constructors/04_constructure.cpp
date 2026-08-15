#include <bits/stdc++.h>
using namespace std;

class simple
{
    int d1, d2, d3;

public:
    simple(int x, int y = 23, int z = 24)
    {
        d1 = x;
        d2 = y;
        d3 = z;
    }
    void print();
};

void simple ::print()
{
    cout << "THE DATA'S ARE : " << d1 << ", " << d2 << "and " << d3 << endl;
}

int main()
{
    simple c1(10,12);
    c1.print();
    return 0;
}