#include <iostream>
#include <conio.h>
using namespace std;

float average()
{
    int n;
    float total;
    cout << "Total no. of students in the class? " << endl;
    cin >> n;
    cout << "Enter the marks of the students: " << endl;
    int *marks = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
        total += marks[i];
    }
    return total / (float)n;
    delete[] marks;
}
int main()
{
    cout << "The average marks of the class is: " << average();
    _getch();
}
