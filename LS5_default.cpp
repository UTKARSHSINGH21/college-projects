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
    Employee(void);
    ~Employee()
    {
        cout << endl
             << "Destructor called" << endl;
    }

    void printCalculateSalary(void);
    void readEmployeeDetails(void);
};

Employee ::Employee(void)
{
    name = "Baburao";
    department = "StarGarage";
}
void Employee ::readEmployeeDetails()
{
    cout << "Enter Employee ID: ";
    cin >> id;

    cout << "Enter their Basic Salary: ";
    cin >> basicSalary;
}
void Employee ::printCalculateSalary()
{
    da = 0.5 * basicSalary;
    hra = 0.3 * basicSalary;
    ta = 0.1 * basicSalary;

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
    Employee E;
    E.readEmployeeDetails();
    E.printCalculateSalary();
    _getch();
}