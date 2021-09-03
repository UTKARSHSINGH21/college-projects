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

    Employee(int ide, string dept, int bs);
    Employee(Employee &obj); 
    ~Employee()              
    {
        cout << endl
             << "Destructor called" << endl;
    }

    void printCalculateSalary(void);
};

Employee ::Employee(int ide, string dept, int bs)
{
    name = "John";
    id = ide;
    department = dept;
    basicSalary = bs;
}
Employee ::Employee(Employee &obj)
{
    name = "Wick";
    id = obj.id;
    department = obj.department;
    basicSalary = obj.basicSalary;
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
    Employee E3(451, "csbs", 15000), E3Copy(E3);

    E3.printCalculateSalary();
    E3Copy.printCalculateSalary();

    _getch();
}