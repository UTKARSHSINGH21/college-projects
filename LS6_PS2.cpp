#include <iostream>
#include <conio.h>
using namespace std;

class Employee
{
    string name;
    int id;
    string department;
    int salary;

    friend class Sales;
public:
    void readDetails()
    {
        cout << "<<<<<---------- Enter Employee Details ---------->>>>>\n" << endl;
        cout << "Enter Employee's name: ";
        cin >> name;
        cout << "Enter Employee's ID: ";
        cin >> id;
        cout << "Enter their Department: ";
        cin >> department;
        cout << "Enter their monthly salary: ";
        cin >> salary;
    }
};

class Sales
{
    int sales;
    float incentives;
    string pIndicator;

public:
    void readSalesDetails()
    {
        cout << "Enter Employee's monthly sales: ";
        cin >> sales;
    }
    void incentivesPerformance(Employee obj)
    {
        if (sales >= 150)
        {
            incentives = 0.3 * obj.salary;
            pIndicator = "Excellent";
        }
        else if (sales >= 100 && sales < 150)
        {
            incentives = 0.2 * obj.salary;
            pIndicator = "Good";
        }
        else if (sales >= 50 && sales < 100)
        {
            incentives = 0.1 * obj.salary;
            pIndicator = "Satisfactory";
        }
        else
        {
            pIndicator = "Poor";   
        }
        
    }
    void printDetails(Employee obj)
    {
        cout << "\n\n<<<<<---------- Employee Details ---------->>>>>\n" << endl;
        cout << "Empolyee Name: " << obj.name << endl;
        cout << "Employee ID: " << obj.id << endl;
        cout << "Department: " << obj.department << endl;
        cout << "Monthly salary: " << obj.salary << endl;
        cout << "Monthly sales: " << sales << endl;
        cout << "Incentives Acquired: " << incentives << endl;
        cout << "Performamce: " << pIndicator << endl << endl;
    }
};

int main()
{
    Employee E;
    Sales S;

    E.readDetails();

    S.readSalesDetails();
    S.incentivesPerformance(E);
    S.printDetails(E);
 
    _getch();
}