#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    int id;
    float salary = 5.55;
    Employee(int i)
    {
        id = i;
    }
    Employee() {}
};

class Programmer : Employee
{
public:
    int languageCode;
    Programmer(int inpId)
    {
        id = inpId;
        languageCode = 9;
    }
    void getData()
    {
        cout << id << endl;
    }
};

int main()
{
    Employee harry(1), rohan(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    Programmer skillF(10);
    cout << skillF.languageCode << endl;
    // cout << skillF.id << endl;
    skillF.getData();

    return 0;
}