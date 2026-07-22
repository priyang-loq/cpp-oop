#include <bits/stdc++.h>
using namespace std;

class Library;

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
    static void increaseTotalBooks();
    friend void compareBooks(Book, Book);
    friend class Library;
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

void Book::increaseTotalBooks()
{
    totalBooks++;
}

void compareBooks(Book b1, Book b2)
{
    if (b1.bookId < b2.bookId)
    {
        cout << "Book " << b1.bookId
             << " comes before Book "
             << b2.bookId << endl;
    }
    else if (b1.bookId > b2.bookId)
    {
        cout << "Book " << b2.bookId
             << " comes before Book "
             << b1.bookId << endl;
    }
    else
    {
        cout << "Both books have the same Book ID.\n";
    }
}

class Library
{
public:
    void showBook(Book b)
    {
        cout << "Book ID : " << b.bookId << endl;
        cout << "Title   : " << b.title << endl;
        cout << "Author  : " << b.author << endl;

        if (b.issued)
            cout << "Status : Issued\n";
        else
            cout << "Status : Available\n";

        cout << endl;
    }
};

int main()
{
    Library lib;
    Book books[100];
    int bookCount = 0;
    int choice;
    do
    {
        cout << "========== Library Management System ==========\n";
        cout << "Choose an option:\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Compare Books\n";
        cout << "6. Total Books\n";
        cout << "7. Exit\n\n";
        cout << "Enter Choice :";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (bookCount >= 100)
            {
                cout << "Library is full.\n";
                break;
            }

            books[bookCount].setData();

            bool duplicate = false;

            for (int i = 0; i < bookCount; i++)
            {
                if (books[i].getBookId() == books[bookCount].getBookId())
                {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate)
            {
                cout << "Book ID already exists. Book not added.\n";
            }
            else
            {
                bookCount++;
                Book::increaseTotalBooks();
                cout << "Book added successfully.\n";
            }

            break;
        }

        case 2:
            if (bookCount == 0)
            {
                cout << "No books available.\n";
            }
            else
            {
                for (int i = 0; i < bookCount; i++)
                {
                    books[i].displayBook();
                }
            }
            break;

        case 3:
        {
            if (bookCount == 0)
            {
                cout << "No books available.\n";
                break;
            }
            int id;
            cout << "Enter Book ID : ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < bookCount; i++)
            {
                if (books[i].getBookId() == id)
                {
                    books[i].issueBook();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Book not found.\n";
            }
            break;
        }

        case 4:
        {
            if (bookCount == 0)
            {
                cout << "No books available.\n";
                break;
            }
            int id;
            cout << "Enter Book ID : ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < bookCount; i++)
            {
                if (books[i].getBookId() == id)
                {
                    books[i].returnBook();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Book not found.\n";
            }
            break;
        }

        case 5:
        {
            if (bookCount < 2)
            {
                cout << "At least two books are required.\n";
                break;
            }

            int first, second;

            cout << "Enter first book number (1-" << bookCount << "): ";
            cin >> first;

            cout << "Enter second book number (1-" << bookCount << "): ";
            cin >> second;

            if (first >= 1 && first <= bookCount &&
                second >= 1 && second <= bookCount)
            {
                compareBooks(books[first - 1], books[second - 1]);
            }
            else
            {
                cout << "Invalid book number.\n";
            }

            break;
        }

        case 6:
            Book::displayTotalBooks();
            break;

        case 7:
            cout << "Thank you for using Library Management System.\n";
            break;

        default:
            cout << "Please enter a valid choice\n";
        }
    } while (choice != 7);

    lib.showBook(books[0]);

    return 0;
}