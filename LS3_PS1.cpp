#include <iostream>
#include <conio.h>
using namespace std;


inline float inches2Yards(int* n)
{
    return *n / 36.0;
}

inline float inches2Feet(int* n)
{
    return *n / 12.0;
}

int main()
{
    int n;
    cout << "Enter a number in inches" << endl;
    cin >> n;

    int *p = new int(n);
    cout << *(p) << " inches is " << inches2Yards(p) << " yards" << " and " << inches2Feet(p) << " feet" << endl;

    delete p;

    _getch();
}