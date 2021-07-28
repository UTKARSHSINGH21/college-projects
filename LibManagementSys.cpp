#include <iostream>
#include <string>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

void bookDetails(void); // Function Declaration
void printBookDetails(void);
void bookSearchByName(string);
void bookSearchByAuthor(string);
void sortBooksbyName(void);

typedef struct booksLib // Defining the struture named books and its attributes
{
    string bookName;
    string bookAuthor;
    float bookPrice;
    int bookCopies;
} bk;
bk books[3]; // 3 is the max no. of books
int i = 0;

void bookDetails()
{
    if (i < 3)
    {
        cin.ignore();
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
            cout << books[x].bookName << " ==> " << books[x].bookCopies << " copies" << endl;
        }
    }
}
void sortBooksByName()
{
    bk temp;
    for (int x = 0; x < 3 - 1; x++)
    {
        for (int j = 0; j < 3 - x - 1; j++)
        {
            if (books[j].bookName > books[j + 1].bookName) // bubble sort
            {
                swap(books[j], books[j + 1]);
            }
        }
    }
    cout << "List after sorting is: " << endl;
    printBookDetails();
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
        switch (f)
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
}
