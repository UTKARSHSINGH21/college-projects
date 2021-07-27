#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

void bookDetails(void); // Function Declaration
void printBookDetails(void);
void bookSearchByName(string);
void bookSearchByAuthor(string);
void sortBooksbyName(void);

typedef struct books // Declaring the struture and its attributes
{
    string bookName;
    string bookAuthor;
    float bookPrice;
    int bookCopies;
} bk;
bk books[3]; // 3 is the max no. of books
int i = 0; // i, a global variable to count no. of books in library.

void bookDetails() 
{
    if (i < 3)
    {
        cin.ignore(); // to ignore the buffers
        cout << "<<<<<---Enter the Book " << i + 1 << " details--->>>>>" << endl
             << endl;
        cout << "Enter the book's name: ";
        getline(cin, books[i].bookName);

        cout << "Enter " << books[i].bookName << "'s author: ";
        getline(cin, books[i].bookAuthor);

        cout << "Enter " << books[i].bookName << "'s price: INR ";
        cin >> books[i].bookPrice;

        cout << "Enter no. of available copies of " << books[i].bookName << ": ";
        cin >> books[i].bookCopies;
        cout << endl;

        i++;
    }
    else
    {
        cout << "Library is out of space!" << endl;
    }
}
void printBookDetails()
{
    for (int j = 0; j < i; j++)
        cout << endl
             << "Book Name: " << books[j].bookName << endl
             << "Author: " << books[j].bookAuthor << endl
             << "No. of copies Available: " << books[j].bookCopies << endl
             << "Price: INR " << books[j].bookPrice << endl
             << endl;
}
void bookSearchByName(string bname)
{
    int c = 0;
    for (int x = 0; x < 3; x++)
    {
        if (bname == books[x].bookName)
        {
            cout << "No. of available copies of " << books[x].bookName << " are: " << books[x].bookCopies << endl
                 << endl;
            c++;
        }
    }
    if (c == 0)
    {
        cout << bname << " is out of Stock" << endl;
    }
}
void bookSearchByAuthor(string bauthor)
{
    cout << "Books by " << bauthor << " are:" << endl;
    for (int x = 0; x < 3; x++)
    {
        if (bauthor == books[x].bookAuthor)
        {
            cout << books[x].bookName << " ==> " << books[x].bookCopies << " copies available" << endl
                 << endl;
        }
    }
}
void sortBooksByName()
{
    for (int y = 0; y < i; y++)
    {
        string temp;
        if (books[y].bookName > books[y + 1].bookName)
        {
            temp = books[y].bookName;
            books[y].bookName = books[y + 1].bookName;
            books[y + 1].bookName = temp;
        }
    }
    cout << "List after sorting is: " << endl;
    for (int z = 0; z < i; z++)
    {
        cout << books[z].bookName << endl;
    }
}

int main()
{
    int f = 9;
    string bookssName, authorname;
    cout << "<<<<<<<<<<<<<<<----------------------Welcome to the Library !!!---------------------->>>>>>>>>>>>>>>" << endl
         << endl;
    while (f != 0)
    {
        cout << "Enter the operation you want to perform: " << endl
             << endl
             << "Press 1: Enter the book details" << endl
             << "Press 2: View list of available books" << endl
             << "Press 3: Search book by it's name" << endl
             << "Press 4: Filter books by author's name" << endl
             << "Press 5: Sort the books by name and display" << endl
             << "Press 0: Exit" << endl;
        cin >> f;
        switch (f) //menu driven
        {
        case 0:
            break;
            break; // first break to get out of switch and another to get out of while
        case 1:
            bookDetails();
            break;
        case 2:
            printBookDetails();
            break;
        case 3:
            cout << "Enter the book's name : ";
            cin.ignore();
            getline(cin, bookssName);
            bookSearchByName(bookssName);
            break;
        case 4:
            cout << "Enter the author's name: ";
            cin.ignore();
            getline(cin, authorname);
            bookSearchByAuthor(authorname);
            break;
        case 5:
            sortBooksByName();
            break;
        default:
            cout << "Enter a valid operation!";
        }
    }
    getchar();
}
