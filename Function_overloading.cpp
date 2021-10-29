#include <iostream>
#include <conio.h>
using namespace std;

void add(short a, short b)
{
    cout << "Sum of " << a << " and " << b << " is " << a + b << endl;
}
void add(int a, int b)
{
    cout << "Sum of " << a << " and " << b << " is " << a + b << endl;
}
void add(float a, float b)
{
    cout << "Sum of " << a << " and " << b << " is " << a + b << endl;
}
void add(double a, double b)
{
    cout << "Sum of " << a << " and " << b << " is " << a + b << endl;
}
void add(long a, long b)
{
    cout << "Sum of " << a << " and " << b << " is " << a + b << endl;
}
void add(long double a, long double b)
{
    cout << "Sum of " << a << " and " << b << " is " << a + b << endl;
}
void add(char a, char b)
{
    cout << "Sum of " << a << " and " << b << " is " << (char)(a + b) << endl;
}

int main()
{
    short s1, s2;
    int i1, i2;
    float f1, f2;
    double d1, d2;
    long l1, l2;
    long double ld1, ld2;
    char c1, c2;

    cout << "Enter two short numbers:" << endl;
    cin >> s1;
    cin >> s2;
    add(s1, s2);

    cout << "Enter two integer numbers:" << endl;
    cin >> i1;
    cin >> i2;
    add(i1, i2);

    cout << "Enter two float numbers:" << endl;
    cin >> f1;
    cin >> f2;
    add(f1, f2);

    cout << "Enter two double numbers:" << endl;
    cin >> d1;
    cin >> d2;
    add(d1, d2);

    cout << "Enter two long numbers:" << endl;
    cin >> l1;
    cin >> l2;
    add(l1, l2);    

    cout << "Enter two long double numbers:" << endl;
    cin >> ld1;
    cin >> ld2;
    add(ld1, ld2);

    cout << "Enter two characters:" << endl;
    cin >> c1;
    cin >> c2;
    add(c1, c2);

    _getch();
}
