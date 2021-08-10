#include <iostream>
#include <conio.h>

using namespace std;

struct Class
{
    string name;
    int rollno;
    string division;
    string program;
};

Class student[3];
int i;

void input(string name, int rollno, string division = "2", string program = "BTech CSBS")
{
    student[i].name = name;
    student[i].rollno = rollno;
    student[i].division = division;
    student[i].program = program;
}

void display()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Student Name: " << student[i].name << endl
             << "Rollno: " << student[i].rollno << endl
             << "Division: " << student[i].division << endl
             << "Program: " << student[i].program << endl
             << endl;
    }
}

int main()
{
    int rollno;
    string division, program, name;

    char c;
    while (i != 3)
    {
        cout << "Enter the student's name: ";
        cin >> name;
        cout << "Enter their roll number: ";
        cin >> rollno;
        cout << endl;
        input(name, rollno);
        i++;
    }
    display();
    _getch();
}
