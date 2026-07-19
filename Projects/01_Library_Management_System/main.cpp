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
    Book obj1;
    obj1.setData();
    obj1.displayBook();
    obj1.issueBook();
    obj1.displayBook();
    obj1.returnBook();
    obj1.displayBook();
    Book ::displayTotalBooks();
    return 0;
}