#include <bits/stdc++.h>
using namespace std;

class Book
{

private:
    int bookId;
    string title;
    string author;
    bool issued;

    static int totalBooks;

public:
    void setData();
    void displayBook();
    void issueBook();
    void returnBook();
    bool isIssued();
    int getBookId();

    static void displayTotalBooks();
};

void Book::setData()
{
    cout << "Enter book id :- ";
    cin >> bookId;

    cout << "Enter book title :- ";
    getline(cin >> ws, title);

    cout << "Enter book author :- ";
    getline(cin, author);

    issued = false;
    totalBooks++;
}

void Book ::displayBook()
{
    cout << "Book ID : " << bookId << endl;
    cout << "Title   : " << title << endl;
    cout << "Author  : " << author << endl;
    if (issued)
        cout << "Status : Issued\n";
    else
        cout << "Status : Available\n";
    cout << endl;
}

void Book ::issueBook()
{
    if (issued)
    {
        cout << "Book is already issued.\n";
    }
    else
    {
        cout << "Book issued successfully.\n";
        issued = true;
    }
}

void Book::returnBook()
{
    if (!issued)
    {
        cout << "Book is already available.\n";
    }
    else
    {
        cout << "Book returned successfully.\n";
        issued = false;
    }
}

bool Book ::isIssued()
{
    return issued;
}

int Book::getBookId()
{
    return bookId;
}

int Book::totalBooks = 0;

void Book::displayTotalBooks()
{
    cout << "Total Books : " << totalBooks << endl;
}

int main()
{
    Book books[100];
    int bookcount = 0;
    int choice;
    do
    {
        cout << "========== Library Management System ==========\n";
        cout << "Choose an option:\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Total Books\n";
        cout << "4. Exit\n\n";
        cout << "Enter Choice :";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Add Book
            break;

        case 2:
            // Display Books
            break;

        case 3:
            // Display Total Books
            break;

        case 4:
            // Exit
            break;

        default:
            // Invalid Choice
        }
    } while (choice != 4);
    return 0;
}