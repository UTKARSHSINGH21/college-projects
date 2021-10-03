#include <iostream>
#include <conio.h>
using namespace std;

class BankAccount
{
public:
    string name;
    string address;
    int age;
    long accno;
    int balance;

    void openacc()
    {
        cin.ignore();
        cout << "\nEnter name of the Customer: ";
        getline(cin, name);
        cout << "Enter their Address: ";
        getline(cin, address);
        cout << "Enter their age: ";
        cin >> age;
        cout << "Account Number: ";
        cin >> accno;
        cout << "Balance: ";
        cin >> balance;
    }
    void withdraw()
    {
        int withdawAmt;
        cout << "Enter the amt to be withdrawn: ";
        cin >> withdawAmt;

        if (balance >= withdawAmt)
        {
            cout << "Withdrawal Granted\n";
            balance -= withdawAmt;
        }
        else
            cout << "Withdrawal Denied !!!\n";
    }
    void deposit()
    {
        int bal;
        cout << "Enter the amount to be deposited: ";
        cin >> bal;
        balance += bal;
    }
    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << age << endl;
        cout << "Account Number: " << accno << endl;
        cout << "Balance: " << balance << endl;
    }
};

class LifeInsurance : virtual public BankAccount
{
protected:
    int policyNo;
    int sumAssured;
    int premium;
    int term;

public:
    void readLData()
    {
        cout << "\n<<<<<---------- Enter details for Life Insurance ---------->>>>>\n";
        openacc();
        cout << "Enter the Policy Number: ";
        cin >> policyNo;
        cout << "Enter Sum Assured: ";
        cin >> sumAssured;
        cout << "Enter term (in years) for the policy: ";
        cin >> term;
    }
    void calLPremium()
    {
        if (age <= 25)
        {
            premium = 3000 * (sumAssured / 100000) * term;
        }
        else if (age >= 26 && age <= 45)
        {
            premium = 4000 * (sumAssured / 100000) * term;
        }
        else if (age >= 46 && age <= 60)
        {
            premium = 5000 * (sumAssured / 100000) * term;
        }
        else
        {
            premium = -1;
        }

        cout << "\nYour Premium for a term of " << term << " year(s) is "
             << "INR " << premium;
    }
    void deductLPremium()
    {
        if (balance >= premium)
        {
            balance -= premium;
            cout << "\nDear Customer, Your Bank Account " << accno << " is debited with INR " << premium << ". The Available balance is INR " << balance << endl;
        }
        else
        {
            cout << "Insufficient Balance!!!\n";
        }
    }
    void displayLifeInsuranceInfo()
    {
        cout << "\n\n<<<<<---------- Life Insurance Details---------->>>>>\n\n";
        displayDetails();

        cout << "Policy Number: " << policyNo << endl;
        cout << "Term (in years): " << term << endl;
        cout << "Sum Assured: " << sumAssured << endl;
        cout << "Premium: " << premium << endl;
    }
};

class CarInsurance : virtual public BankAccount
{
protected:
    int policyNo;
    int carDetails;
    int premium;
    int duration;

public:
    void readCData()
    {
        cout << "\n\n<<<<<---------- Enter details for Car Insurance ---------->>>>>\n";
        openacc();
        cout << "Enter the Policy Number: ";
        cin >> policyNo;
        cout << "Enter duration (in years) for the policy: ";
        cin >> duration;
        cout << "Enter the age of car: ";
        cin >> carDetails;
    }
    void calCPremium()
    {
        if (carDetails <= 1)
        {
            premium = 5000 * 8 * duration;
        }
        else if (carDetails >= 2 && carDetails <= 4)
        {
            premium = 4000 * 8 * duration;
        }
        else if (carDetails >= 5 && carDetails <= 7)
        {
            premium = 5000 * 8 * duration;
        }
        else
        {
            premium = 0;
            cout << "No Insurance!!!\n";
        }
        cout << "\nYour Premium for a term of " << duration << " year(s) is "
             << "INR " << premium;
    }
    void deductCPremium()
    {
        if (balance >= premium)
        {
            balance -= premium;
            cout << "\nDear Customer, Your Bank Account " << accno << " is debited with INR " << premium << ". The Available balance is INR " << balance << endl;
        }
        else
        {
            cout << "Insufficient Balance!!!\n";
        }
    }
    void displayCarInsuranceInfo()
    {
        cout << "\n\n<<<<<---------- Car Insurance Details---------->>>>>\n\n";
        displayDetails();

        if (balance >= premium)
        {
            cout << "Policy Number: " << policyNo << endl;
            cout << "Car's Age: " << carDetails << endl;
            cout << "Sum Assured: 800000" << endl;
            cout << "Premium: " << premium << endl;
            cout << "Duration (in years): " << duration << endl;
        }
        else
        {
            cout << "Policy can't be opened due to insufficent Balance\n";
        }
    }
};

class Claim : public LifeInsurance, public CarInsurance
{
    int Amount, year;

public:
    int c;
    void settlement()
    {
        cout << "Which policy do you want to Close?\n";
        cout << "Press 1: Life Insurance\n";
        cout << "Press 2: Car Insurance\n";
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "You chose to close Life Insurance\n";
            cout << "Enter the no. of years for which the policy has been active: ";
            cin >> year;
            if (year <= 5)
                Amount = 0;
            else if (year >= 6 && year <= 12)
                Amount = 0.25 * sumAssured;
            else if (year >= 13 && year <= 20)
                Amount = 0.7 * sumAssured;
            else
                Amount = 2 * sumAssured;
            break;

        case 2:
            cout << "You have chose to close  Car Insurance\n";
            cout << "Enter the amount spent on repairing of Car: ";
            cin >> Amount;
            break;

        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
    void depositAmtInSavAcc()
    {
        balance += Amount;
    }
    void displayInfo()
    {
        int k;
        cout << "Press 0: View Life Insurance Info\n";
        cout << "Press 1: View Car Insurance Info\n";
        cout << "Press E: Exit\n";
        cin >> k;

        switch (k)
        {
        case 0:
            displayLifeInsuranceInfo();
            cout << "Term For which policy has been active: " << year << endl;
            cout << "Settlement Amount: " << Amount << endl;
            cout << "Available Balance: " << balance << endl;
            break;
        case 1:
            displayCarInsuranceInfo();
            cout << "Settlement Amount: " << Amount << endl;
            cout << "Available Balance: " << balance << endl;
            break;
        }
    }
};

int main()
{
    Claim C1;
    int d = 654, n;

    while (d != 0)
    {
        cout << "\n<<<<< ---------- Insurance ---------- >>>>>\n\n";
        cout << "Press 1: Life Insurance\n";
        cout << "Press 2: Car Insurance\n";
        cout << "Press 3: Claim\n";
        cout << "Press 0: Exit\n";
        cin >> d;

        switch (d)
        {
        case 1:
            while (n != 14)
            {
                cout << "\n\n<<<<<---------- Life Insurance ---------->>>>>\n";
                cout << "Press 10: Open account\n";
                cout << "Press 11: Calculate Premium\n";
                cout << "Press 12: Open Insurance\n";
                cout << "Press 13: Display Policy Details\n";
                cout << "Press 14: Exit\n";
                cin >> n;
                switch (n)
                {
                case 10:
                    C1.readLData();
                    break;
                case 11:
                    C1.calLPremium();
                    break;
                case 12:
                    C1.deductLPremium();
                    break;
                case 13:
                    C1.displayLifeInsuranceInfo();
                    break;
                case 14:
                    break;
                    break;

                default:
                    cout << "Invalid Choice\n";
                    break;
                }
            }
            break;
        case 2:

            while (n != 24)
            {
                cout << "\n\n<<<<<---------- Car Insurance ---------->>>>>\n";
                cout << "Press 20: Open account\n";
                cout << "Press 21: Calculate Premium\n";
                cout << "Press 22: Open Insurance\n";
                cout << "Press 23: Display Policy Details\n";
                cout << "Press 24: Exit\n";
                cin >> n;
                switch (n)
                {
                case 20:
                    C1.readCData();
                    break;
                case 21:
                    C1.calCPremium();
                    break;
                case 22:
                    C1.deductCPremium();
                    break;
                case 23:
                    C1.displayCarInsuranceInfo();
                    break;
                case 24:
                    break;
                    break;
                default:
                    cout << "Invalid Choice !!!\n";
                    break;
                }
            }
            break;

        case 0:
            break;
            break;

        case 3:
            cout << "\n\n<<<<<---------- Claim ----------->>>>>\n\n";
            C1.settlement();
            C1.depositAmtInSavAcc();
            C1.displayInfo();
            break;

        default:
            cout << "Invalid Choice !!!\n";
            break;
        }
    }
    _getch();
}