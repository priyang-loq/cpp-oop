#include <bits/stdc++.h>
using namespace std;

class Employee
{
    int id;

public:
    void setId(){
        cout << "Enter the id of employee" << endl;
        cin >> id;
    }
    void getId(void)
    {
        cout << "The id of this employee is " << id << endl;
    }
};

int main()
{
    Employee GG[4];
    for (int i = 0; i < 4; i++)
    {
        GG[i].setId();
        GG[i].getId();
    }
    return 0;
}