#include <iostream>
#include <conio.h>
using namespace std;

class DoctorList
{
    public:
        string doctorName;
        string area;
        void readData()
        {
            cout << "\nEnter the name of the Doctor: ";
            cin >> doctorName;
            cout << "Enter the name of the Area: ";
            cin >> area;
        }
        friend int operator<(string DA1, string DA2);
        static void printList();
};

int n = 3;
DoctorList DA[3];

int operator<(string DA1, string DA2)
{
    if (DA1 > DA2)
        return 1;
    else    
        return 0;
}

void DoctorList ::printList()
{
    cout << "\n\nDoctors list after sorting area wise is:\n" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Doctor Name: Dr. " << DA[i].doctorName << endl;
        cout << "Area: " << DA[i].area << endl
             << endl;
    }
}

int main()
{
    for (int i = 0; i < n; i++)
    {
        DA[i].readData();
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((operator<(DA[j].area, DA[j + 1].area)))
            {
                std::swap(DA[j], DA[j + 1]);
            }
        }
    } 
    DoctorList :: printList();
    _getch();
}
