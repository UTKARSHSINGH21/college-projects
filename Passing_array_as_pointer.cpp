#include <iostream>
#include <conio.h>
using namespace std;

int n;

int max(int *marks) //max function to print maximum marks
{
    int maxi = *(marks);
    for (int i = 1; i < n; i++)
    {
        if (*(marks + i) > maxi)
            maxi = *(marks + i);
    }
    return maxi;
}

int min(int *marks) //min function to print minimum marks
{
    int mini = *(marks);
    for (int i = 1; i < n; i++)
    {
        if (*(marks + i) < mini)
            mini = *(marks + i);
    }
    return mini;
}

int main()
{
    cout << "Total Students in the class? ";
    cin >> n;
    int marks[n];
    cout << "Enter the marks of the students:" << endl;

    for (int i = 0; i < n; i++)
        cin >> marks[i];

    int max1 = max(marks);
    int min1 = min(marks);

    cout << "The Highest Marks in the class is: " << max1 << endl
         << "The Lowest Marks in the class is: " << min1;
    _getch();
}
