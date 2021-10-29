#include <iostream>
#include <conio.h>
using namespace std;

inline float cubeVolume(float l)
{
    return l * l * l;
}
inline float sphereVolume(float r)
{
    return ((float)4 / 3 * (float)22 / 7 * r * r * r);
}
inline float cylinderVolume(float r, float h)
{
    return (((float)22 / 7) * r * r * h);
}
inline float coneVolume(float r, float h)
{
    return (((float)1 / 3 * (float)22 / 7 * r * r * h));
}

int main()
{
    float totalVolume;
    totalVolume += cubeVolume(1) + sphereVolume(1) + cylinderVolume(1,1) + coneVolume(1,1);
    cout << "The total volume is " << totalVolume << endl; 
    _getch(); 
}
