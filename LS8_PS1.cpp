#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

class Account
{
public:
    string name;
    int number;
    string acctype;
    int balance;

    void readData()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Account Number: ";
        cin >> number;
        cout << "Enter balance: ";
        cin >> balance;
    }
    void deposit()
    {
        int bal;
        cout << "\nEnter the amount to be deposited: ";
        cin >> bal;
        balance += bal;
    }
    void displayBalance()
    {
        cout << "\nAvailable Balance: INR " << balance << endl;
    }
    void withdrawal()
    {
        int withdawAmt;
        cout << "Enter the amt to be withdrawn: ";
        cin >> withdawAmt;

        if (balance >= withdawAmt)
        {
            cout << "Withdrawal Granted\n\n";
            balance -= withdawAmt;
        }
        else
            cout << "Withdrawal Denied !!!\n\n";
    }
};

class curr_acct : public Account
{

    int minBalance = 10000;
    int checkBook;
    int penalty;

public:
    curr_acct()
    {
        acctype = "Current";
        balance = 0;
    }
    void displayData()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << number << endl;
        cout << "Account Type: " << acctype << endl;
        cout << "Account Balance: " << balance << endl;
    }
    void checMinBal()
    {
        if (balance < minBalance)
        {
            penalty = 0.1 * balance;
            balance -= penalty;
        }
    }
};
class sav_acct : public Account
{
    float r = 10.5;

public:
    sav_acct()
    {
        acctype = "Savings";
        balance = 0;
    }
    void displayData()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << number << endl;
        cout << "Account Type: " << acctype << endl;
        cout << "Account Balance: " << balance << endl;
    }
    void calculateCI()
    {
        float t, interest;
        cout << "\nEnter time(in year) to calculate Interest: ";
        cin >> t;
        interest = balance * (pow(((100 + r) / 100), t) - 1);
        balance += interest;
    }
};

int main()
{
    int f;
    curr_acct C;
    sav_acct S;

    cout << "<<<<<---------- Bank Account ---------->>>>>" << endl;
    cout << "Press 1: Savings A/C" << endl;
    cout << "Press 2: Current A/C" << endl;
    cin >> f;

    switch (f)
    {
    case 1:

        S.readData();
        S.deposit();
        S.displayBalance();
        S.calculateCI();
        S.displayBalance();
        S.withdrawal();
        S.displayData();
        break;

    case 2:

        C.readData();
        C.deposit();
        C.displayBalance();
        C.checMinBal();
        C.withdrawal();
        C.displayBalance();
        C.checMinBal();
        C.displayData();
        break;
    }
    _getch();
}
