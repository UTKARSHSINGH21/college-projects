#include <iostream>
#include <conio.h>
using namespace std;

class Staff
{
protected:
    int code;
    string name;
    void getBasicInfo()
    {
        cout << "Name: ";
        cin >> name;
        cout << "Code: ";
        cin >> code;
    }
    void printBasicInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
    }
};

class Teacher : public Staff
{
    string subject;
    string publication;

public:
    void getTeacherInfo()
    {
        getBasicInfo();
        cout << "Subject: ";
        cin >> subject;
        cout << "Publication: ";
        cin >> publication;
    }
    void printTeacherInfo()
    {
        printBasicInfo();
        cout << "Subject: " << subject << endl;
        cout << "Publication: " << publication << endl;
    }
};
class Typist : public Staff
{
    int speed;
protected:
    void getTypistInfo()
    {
        getBasicInfo();
        cout << "Speed: ";
        cin >> speed;
    }
    void printTypistInfo()
    {
        printBasicInfo();
        cout << "Speed: " << speed << " wpm" << endl;
    }
};
class Officer : public Staff
{
    char grade;

public:
    void getOfficerInfo()
    {
        getBasicInfo();
        cout << "Grade: ";
        cin >> grade;
    }
    void printOfficerInfo()
    {
        printBasicInfo();
        cout << "Grade: " << grade << endl;
    }
};

class Regular : public Typist
{
    int salary;

public:
    void getRegularInfo()
    {
        getTypistInfo();
        cout << "Enter Salary: ";
        cin >> salary;
    }
    void printRegularInfo()
    {
        printTypistInfo();
        cout << "Salary: " << salary << endl;
        ;
    }
};
class Casual : public Typist
{
    int wage;

public:
    void getCasualInfo()
    {
        getTypistInfo();
        cout << "Daily Wage: ";
        cin >> wage;
    }
    void printCasualInfo()
    {
        printTypistInfo();
        cout << "Daily Wage: " << wage << endl;
    }
};

int main()
{
    Teacher T;
    Regular R;
    Casual C;
    Officer O;

    int c = 0;
    cout << "<<<<<---------- Select Staff Type ---------->>>>>\n";
    cout << "Press 1: Teacher\n";
    cout << "Press 2: Typist\n";
    cout << "Press 3: Officer\n";
    cin >> c;
    switch (c)
    {
    case 1:
        cout << "<<<<<---------- Enter the Teacher's Details ---------->>>>>" << endl;
        T.getTeacherInfo();
        cout << "\n\n<<<<<---------- Teacher's Details ---------->>>>>" << endl;
        T.printTeacherInfo();
        break;
    case 2:
        char t;
        cout << "Regular Typist or Casual Typist?\n";
        cout << "Press C: Casual Typist\n";
        cout << "Press R: Regular Typist\n";
        cin >> t;
        if (t == 'R' || t == 'r')
        {
            cout << "<<<<<---------- Enter the Regular Typist's Details ---------->>>>>" << endl;
            R.getRegularInfo();
            cout << "\n\n<<<<<---------- Regular typist's details ---------->>>>>" << endl;
            R.printRegularInfo();
        }
        else if (t == 'C' || t == 'c')
        {
            cout << "<<<<<---------- Enter the Casual Typist's Details ---------->>>>>" << endl;
            C.getCasualInfo();
            cout << "\n\n<<<<<---------- Casual typist's details ---------->>>>>" << endl;
            C.printCasualInfo();
        }
        else
        {
            cout << "Invalid Choice!!!\n";
        }
        break;
    case 3:
        cout << "<<<<<---------- Enter the Officer's Details ---------->>>>>" << endl;
        O.getOfficerInfo();
        cout << "\n\n<<<<<---------- Officer's details ---------->>>>>" << endl;
        O.printOfficerInfo();
        break;
    }
    _getch();
}
