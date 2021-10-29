#include <iostream>
#include<conio.h>
using namespace std;

class electricityBill
{

    string consumerName;
    long consumerNumber;
    string consumerType;
    long currentMeterReading;
    long lastMeterReading;
    string billMonth;
    float bill;

public:
    void readData(void);
    void calculateBill(void);
    void printBill(void);
};
electricityBill consumer[3];
int i;

void electricityBill :: readData()
{
    cout << "Enter the Consumer's Name: ";
    getline(cin, consumer[i].consumerName);

    cout << "Enter the Consumer's Number: ";
    cin >> consumer[i].consumerNumber;

    cout << "Enter the Consumer Type: ";
    cin >> consumer[i].consumerType;

    cout << "Enter Current Meter Reading: ";
    cin >> consumer[i].currentMeterReading;

    cout << "Enter last Meter Reading: ";
    cin >> consumer[i].lastMeterReading;

    cout << "Enter the Bill month: ";
    cin >> consumer[i].billMonth;
    cin.ignore();
}
void electricityBill :: calculateBill()
{
    long unit = consumer[i].currentMeterReading - consumer[i].lastMeterReading;
    if (consumer[i].consumerType == "commercial")
    {
        if (unit > 200)
        {
            consumer[i].bill = 200 * 5 + (unit - 200) * 10;
        }
        else
        {
            consumer[i].bill = unit * 5;
        }
    }
    if (consumer[i].consumerType == "non-commercial")
    {
        if (unit > 100)
        {
            consumer[i].bill = 200 * 3 + (unit - 200) * 5;
        }
        else
        {
            consumer[i].bill = unit * 5;
        }
    }
}
void electricityBill :: printBill()
{
    cout << endl
         << "Consumer Name: " << consumer[i].consumerName << endl;
    cout << "Consumer Number: " << consumer[i].consumerNumber << endl;
    cout << "Consumer Type: " << consumer[i].consumerType << endl;
    cout << "Current Meter Reading: " << consumer[i].currentMeterReading << endl;
    cout << "Last Meter Reading: " << consumer[i].lastMeterReading << endl;
    cout << "Bill month: " << consumer[i].billMonth << endl;
    cout << "Bill: INR " << consumer[i].bill << endl
         << endl;
}

int main()
{
    while (i != 3)
    {
        consumer[i].readData();
        consumer[i].calculateBill();
        consumer[i].printBill();
        i++;
    }
    _getch();
}
