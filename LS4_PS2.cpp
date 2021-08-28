#include <iostream>
#include <conio.h>
using namespace std;

class playerDetails
{

    string name;
    string region;
    float battingAvg;
    float bowlingAvg;

public:
    void readData();
    void generateList();
    static void sortList(playerDetails List[]);
    static void displayList(playerDetails List[]);
};

int i;
int j = 0;
playerDetails player[3], List[3];

void playerDetails ::readData()
{
    cout << "Enter player's name: ";
    getline(cin, player[i].name);

    cout << "Enter their region: ";
    cin >> player[i].region;

    cout << "Enter their batting average: ";
    cin >> player[i].battingAvg;

    cout << "Enter their bowling average: ";
    cin >> player[i].bowlingAvg;
    cin.ignore();
    cout << endl;
}
void playerDetails ::generateList()
{
    if (player[i].battingAvg > 30 && player[i].bowlingAvg < 25)
    {

        List[j].name = player[i].name;
        List[j].region = player[i].region;
        List[j].battingAvg = player[i].battingAvg;
        List[j].bowlingAvg = player[i].bowlingAvg;
        j++;
    }
}
void playerDetails ::sortList(playerDetails List[])
{
    cout << "Sorted List on the basis of batting avg:" << endl;
    for (int x = 0; x < j - 1; x++)
    {
        for (int y = 0; y < j - x - 1 ; y++)
        {
            if (List[y].battingAvg > List[y + 1].battingAvg)
            {
                swap(List[y], List[y + 1]);
            }
        }
    }
    displayList(List);

    cout << "Sorted List on the basis of bowling avg:" << endl;
    for (int x = 0; x < j - 1; x++)
    {
        for (int y = 0; y < j - x - 1 ; y++)
        {
            if (List[y].bowlingAvg > List[y + 1].bowlingAvg)
            {
                swap(List[y], List[y + 1]);
            }
        }
    }
    displayList(List);
}
void playerDetails ::displayList(playerDetails List[])
{
    for (int i = 0; i < j; i++)
    {
        cout << endl << "Player name: " << List[i].name << endl;
        cout << "Region: " << List[i].region << endl;
        cout << "Batting Average: " << List[i].battingAvg << endl;
        cout << "Bowling Average: " << List[i].bowlingAvg << endl << endl;
    }
}

int main()
{

    while (i != 3)
    {
        player[i].readData();
        player[i].generateList();
        i++;
    }
    playerDetails :: sortList(List);
    _getch();
}