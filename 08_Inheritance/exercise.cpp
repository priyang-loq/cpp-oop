#include <bits/stdc++.h>
using namespace std;

class SimpleCalculator
{
protected:
    int n, m;

public:
    void SetData(int x, int y)
    {
        n = x;
        m = y;
    }

    int Addition()
    {
        return n + m;
    }

    int Subtraction()
    {
        return n - m;
    }

    int Multiplication()
    {
        return n * m;
    }

    int Division()
    {
        return n / m;
    }
};

class ScientificCalculator : public SimpleCalculator
{
public:
    double Power()
    {
        return pow(n, m);
    }

    double Sqrt()
    {
        return sqrt(n);
    }

    double Sin()
    {
        return sin(n);
    }

    double Log()
    {
        return log(n);
    }
};

class HybridCalculator : public ScientificCalculator
{
public:
    void display()
    {
        cout << "Addition: " << Addition() << endl;
        cout << "Subtraction: " << Subtraction() << endl;
        cout << "Multiplication: " << Multiplication() << endl;
        cout << "Division: " << Division() << endl;

        cout << "Power: " << Power() << endl;
        cout << "Square Root: " << Sqrt() << endl;
        cout << "Sin: " << Sin() << endl;
        cout << "Log: " << Log() << endl;
    }
};

int main()
{
    HybridCalculator H1;

    H1.SetData(10, 2);

    H1.display();

    return 0;
}