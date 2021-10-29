#include <iostream>
#include <conio.h>
using namespace std;

class Employee
{

    string name;
    int id;
    string department;
    int basicSalary;

    int da;
    int hra;
    int ta;

public:
    Employee(string n, int ide, string dept, int bs); 
    Employee(int ide, string dept, int bs);
   
    ~Employee()             
    {
        cout << endl
             << "Destructor called" << endl;
    }

    void printCalculateSalary(void);
};

Employee ::Employee(string n, int ide, string dept, int bs)
{
    name = n;
    id = ide;
    department = dept;
    basicSalary = bs;
}
Employee ::Employee(int ide, string dept, int bs)
{
    name = "Baburao";
    id = ide;
    department = dept;
    basicSalary = bs;
}

void Employee ::printCalculateSalary()
{
    da  = 0.5 * basicSalary;
    hra = 0.3 * basicSalary;
    ta  = 0.1 * basicSalary;

    int grossSalary = basicSalary + da + hra + ta;

    cout << endl
         << "<<<<<<<<<<---------- EMPLOYEE DETAILS ---------->>>>>>>>>>" << endl;
    cout << "Employee Name: " << name << endl;
    cout << "Empoyee ID: " << id << endl;
    cout << "Department: " << department << endl;
    cout << "Basic Salary: " << basicSalary << endl;
    cout << "Dearness Allowance: " << da << endl;
    cout << "HRA: " << hra << endl;
    cout << "TA: " << ta << endl;
    cout << "Gross Salary: " << grossSalary << endl;
}

int main()
{
    Employee  E1("Utkarsh", 49, "cds", 35000), E2(451, "csbs", 15000);
    E1.printCalculateSalary();
    E2.printCalculateSalary();

    _getch();
    
}
