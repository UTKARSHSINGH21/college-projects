#include <iostream>
#include <conio.h>
using namespace std;

class TEE; // forward declaration
class ICA
{
    float math;
    float oop;
    float se;
    float ds;

public:
    void readIcaMarks(void)
    {
        cout << "\n\n<<<<<------------------- ENTER ICA MARKS (Out of 50) ------------------->>>>>" << endl;
        cout << "\nEnter ICA Marks in Maths: ";
        cin >> math;
        cout << "Enter ICA Marks in OOP: ";
        cin >> oop;
        cout << "Enter ICA Marks in SE: ";
        cin >> se;
        cout << "Enter ICA Marks in DS: ";
        cin >> ds;
    }
friend void calculate(ICA, TEE);
};

class TEE
{
    float math;
    float oop;
    float se;
    float ds;

public:
    void readTeeMarks()
    {
        cout << "\n\n<<<<<------------------- ENTER TEE MARKS (Out of 50) ------------------->>>>> " << endl;
        cout << "\nEnter TEE Marks in Maths: ";
        cin >> math;
        cout << "Enter TEE Marks in OOP: ";
        cin >> oop;
        cout << "Enter TEE Marks in SE: ";
        cin >> se;
        cout << "Enter TEE Marks in DS: ";
        cin >> ds;
    }
    friend void calculate(ICA, TEE);
};

void calculate(ICA I, TEE T)
{
    cout << "\n\n<<<<<------------------- MARKSHEET ------------------->>>>>" << endl;
    cout << "\nTotal marks in Maths: " << I.math + T.math << endl;
    cout << "Total marks in OOP: " << I.oop + T.oop << endl;
    cout << "Total marks in SE: " << I.se + T.se << endl;
    cout << "Total marks in DS: " << I.ds + T.ds << endl
         << endl;
}

int main()
{
    TEE T;
    ICA I;

    I.readIcaMarks();
    T.readTeeMarks();
    calculate(I, T);

    _getch();
}