#include "LibraryBook.h"
#include <iostream>
#include <iomanip>
using namespace std;

LibraryBook::LibraryBook() {
    bookID = 0;
    title = "";
    author = "";
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}


LibraryBook::LibraryBook(int id, string t, string a) {
    bookID = id;
    title = t;
    author = a;
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}


LibraryBook::~LibraryBook() {
    if (bookID != 0) {
        cout << "[Destructor] Book ID " << bookID << " (\"" << title << "\") object destroyed.\n";
    }
}


int LibraryBook::getBookID() const { return bookID; }
string LibraryBook::getTitle() const { return title; }
string LibraryBook::getAuthor() const { return author; }
string LibraryBook::getBorrowerName() const { return borrowerName; }
int LibraryBook::getDaysBorrowed() const { return daysBorrowed; }
bool LibraryBook::getBorrowStatus() const { return isBorrowed; }


void LibraryBook::setBookID(int id) { bookID = id; }
void LibraryBook::setTitle(string t) { title = t; }
void LibraryBook::setAuthor(string a) { author = a; }
void LibraryBook::setBorrowerName(string name) { borrowerName = name; }
void LibraryBook::setDaysBorrowed(int days) { daysBorrowed = days; }
void LibraryBook::setBorrowStatus(bool status) { isBorrowed = status; }


void LibraryBook::borrowBook(string name, int days) {
    isBorrowed = true;
    borrowerName = name;
    daysBorrowed = days;
}

void LibraryBook::returnBook() {
    isBorrowed = false;
    borrowerName = "";
    daysBorrowed = 0;
}


bool LibraryBook::isOverdue() const {
    return (isBorrowed && daysBorrowed > 14);
}


double LibraryBook::calculateFine() const {
    if (isOverdue()) {
        int overdueDays = daysBorrowed - 14;
        return overdueDays * 500.0; 
    }
    return 0.0;
}

void LibraryBook::displayBookDetails() const {
    cout << left << setw(8) << bookID 
              << setw(25) << title 
              << setw(20) << author 
              << setw(15) << (isBorrowed ? "Borrowed" : "Available")
              << setw(18) << (isBorrowed ? borrowerName : "N/A")
              << setw(15) << daysBorrowed << "\n";
}