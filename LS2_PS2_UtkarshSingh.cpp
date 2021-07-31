#include <iostream>
#include <conio.h>
using namespace std;

float volume(float l) // vol of cube
{
    float v = l * l * l;
    return v;
}
double volume(double r) // volume of sphere
{
    double v = ((double)4 / 3 * 22 / 7 * r * r * r);
    return v;
}
double volume(double r, float h) // volume of cylinder
{
    double v = (((double)22 / 7) * r * r * h);
    return v;
}
double volume(float l, double h) // volume of cone
{
    double v = (((double)1 / 3 * (double)22 / 7 * l * l * h));
    return v;
}

int main()
{
    cin.clear();
    float len, h;
    double r, totalVolume;

    cout << "Enter length of side of Cube: ";
    cin >> len;
    totalVolume += volume(len);

    cout << "Enter length of radius of Sphere: ";
    cin >> r;
    totalVolume += volume(r);

    cout << "Enter radius of the base of Cylinder: ";
    cin >> r;
    cout << "Enter the height of the Cylinder: ";
    cin >> len;
    totalVolume += volume(r, len);

    cout << "Enter radius of the base of Cone: ";
    cin >> len;
    cout << "Enter the height of Cone: ";
    cin >> r;
    totalVolume += volume(len, r);

    cout << endl << "Total Volume is " << totalVolume;
    _getch();
}