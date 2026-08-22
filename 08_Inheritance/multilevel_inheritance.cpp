#include <bits/stdc++.h>
using namespace std;

class student
{
protected:
    int roll_number;

public:
    void setRollnumber(int);
    void getRollnumber();
};

void student ::setRollnumber(int r)
{
    roll_number = r;
}

void student ::getRollnumber()
{
    cout << "The roll number is " << roll_number << endl;
}

class Exam : public student
{
protected:
    float maths;
    float physics;

public:
    void set_marks(float, float);
    void get_marks(void);
};

void Exam ::set_marks(float m1, float m2)
{
    maths = m1;
    physics = m2;
}

void Exam ::get_marks()
{
    cout << "The marks obtained in maths are: " << maths << endl;
    cout << "The marks obtained in physics are: " << physics << endl;
}

class Result : public Exam
{
    float percentage;

public:
    void display_results()
    {
        getRollnumber();
        get_marks();
        cout << "Your result is " << (maths + physics) / 2 << "%" << endl;
    }
};

int main()
{
    Result harry;
    harry.setRollnumber(42);
    harry.set_marks(91.0, 90.0);
    harry.display_results();

    return 0;
}