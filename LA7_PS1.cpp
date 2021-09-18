#include <iostream>
#include <conio.h>
using namespace std;

class External1;
class Internal1
{
public:
    int math;
    int oop;
    int se;
    int ds;

    Internal1(int m,int o,int s,int d)
    {
        math = m;
        oop = o;
        se = s;
        ds = d;
    }

    friend void operator+(Internal1, External1);
};

class External1
{
    int math;
    int oop;
    int se;
    int ds;

public:
    External1(int m,int o,int s,int d)
    {
        math = m;
        oop = o;
        se = s;
        ds = d;
    }
    friend void operator+(Internal1, External1);
};
void grade(int tmath, int toop, int tds, int tse)
{
    cout << "\n<<<------------- Grade ------------->>>\n" << endl;
    if (tmath < 50)
        cout << "\nMaths: Fail" << endl;
    else
        cout << "Maths: Pass" << endl;

    if (toop < 50)
        cout << "OOP: Fail" << endl;
    else
        cout << "OOP: Pass" << endl;

    if (tse < 50)
        cout << "SE: Fail" << endl;
    else
        cout << "SE: Pass" << endl;

    if (tds < 50)
        cout << "DS: Fail" << endl;
    else
        cout << "DS: Pass" << endl;

    int totalMarks = tmath + toop + tse + tds;
    cout << "\nTotal Marks: " << totalMarks << endl;

    if (totalMarks / 4 >= 50)
        cout << "Percentage: " << totalMarks / 4 << "%"<< endl;
}
void operator+(Internal1 I, External1 E)
{
    int tmath = I.math + E.math;
    int toop = I.oop + E.oop;
    int tse = I.se + E.se;
    int tds = I.ds + E.ds;

    cout << "\n\n<<<------------- Total Marks (Out of 100) ------------->>>" << endl;
    cout << "\nMaths: " << tmath << endl;
    cout << "OOP: " << toop << endl;
    cout << "SE: " << tse << endl;
    cout << "DS: " << tds << endl
         << endl;

    grade(tmath, toop, tds, tse);
}

int main()
{
    External1 E(30,31,31,23);
    Internal1 I(23,22,10,30);

    operator+(I, E);
    _getch();
}