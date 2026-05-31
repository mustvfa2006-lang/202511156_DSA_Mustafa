#include "Functions.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void addBook(LibraryBook books[], int &bookCount) {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library database full! Cannot add more books.\n";
        return;
    }

    int id;
    string title, author;

    cout << "Enter Book ID (integer): ";
    cin >> id;
    cin.ignore(); 

   
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            cout << "Error: A book with this ID already exists!\n";
            return;
        }
    }

    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);

    books[bookCount] = LibraryBook(id, title, author);
    bookCount++;
    cout << "Book added successfully!\n";
}

void displayBooks(const LibraryBook books[], int bookCount) {
    if (bookCount == 0) {
        cout << "No books available in the library.\n";
        return;
    }

    cout << "\n---------------------------------------------------------------------------------------\n";
    cout << left << setw(8) << "ID" << setw(25) << "Title" << setw(20) << "Author" 
              << setw(15) << "Status" << setw(18) << "Borrower" << setw(15) << "Days Borrowed" << "\n";
    cout << "---------------------------------------------------------------------------------------\n";
    for (int i = 0; i < bookCount; i++) {
        books[i].displayBookDetails();
    }
    cout << "---------------------------------------------------------------------------------------\n";
}

void borrowBookMenu(LibraryBook books[], int bookCount) {
    int id;
    cout << "Enter Book ID to borrow: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            if (books[i].getBorrowStatus()) {
                cout << "Sorry, this book is already borrowed by " << books[i].getBorrowerName() << ".\n";
                return;
            }
            string studentName;
            int days;
            cout << "Enter Student Name: ";
            getline(cin, studentName);
            cout << "Enter Number of Days to Borrow: ";
            cin >> days;

            books[i].borrowBook(studentName, days);
            cout << "Book successfully checked out to " << studentName << ".\n";
            return;
        }
    }
    cout << "Book ID not found.\n";
}

void returnBookMenu(LibraryBook books[], int bookCount) {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            if (!books[i].getBorrowStatus()) {
                cout << "This book is already sitting in the library shelf.\n";
                return;
            }
            
            if (books[i].isOverdue()) {
                cout << "ALERT: This book is overdue! Fine accrued: " << books[i].calculateFine() << " RWF.\n";
            }
            books[i].returnBook();
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book ID not found.\n";
}

void searchBook(const LibraryBook books[], int bookCount) {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            cout << "\nBook Found:\n";
            cout << "---------------------------------------------------------------------------------------\n";
            books[i].displayBookDetails();
            cout << "---------------------------------------------------------------------------------------\n";
            return;
        }
    }
    cout << "Book with ID " << id << " not found.\n";
}

void displayOverdueBooks(const LibraryBook books[], int bookCount) {
    bool foundAny = false;
    cout << "\n--- Overdue Books Report (Borrowed > 14 Days) ---\n";
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isOverdue()) {
            if (!foundAny) {
                cout << left << setw(8) << "ID" << setw(25) << "Title" 
                     << setw(18) << "Borrower" << setw(15) << "Days" << "Fine (RWF)\n";
                cout << "---------------------------------------------------------------------------------------\n";
            }
            cout << left << setw(8) << books[i].getBookID()
                      << setw(25) << books[i].getTitle()
                      << setw(18) << books[i].getBorrowerName()
                      << setw(15) << books[i].getDaysBorrowed()
                      << books[i].calculateFine() << "\n";
            foundAny = true;
        }
    }
    if (!foundAny) {
        cout << "Excellent! No overdue books at the moment.\n";
    }
}

void calculateTotalFines(const LibraryBook books[], int bookCount) {
    double totalFines = 0.0;
    for (int i = 0; i < bookCount; i++) {
        totalFines += books[i].calculateFine();
    }
    cout << "\nTotal Out-standing Fines Collected/Accrued: " << totalFines << " RWF\n";
}