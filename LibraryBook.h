#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <string>
using namespace std;
class LibraryBook {
private:
    int bookID;
    string title;
    string author;
    string borrowerName;
    int daysBorrowed;
    bool isBorrowed; 

public:
    
    LibraryBook();
    LibraryBook(int id, string t, string a);
    ~LibraryBook();

    
    int getBookID() const;
    string getTitle() const;
    string getAuthor() const;
    string getBorrowerName() const;
    int getDaysBorrowed() const;
    bool getBorrowStatus() const;

   
    void setBookID(int id);
    void setTitle(string t);
    void setAuthor(string a);
    void setBorrowerName(string name);
    void setDaysBorrowed(int days);
    void setBorrowStatus(bool status);

    
    void borrowBook(string name, int days);
    void returnBook();
    bool isOverdue() const;
    double calculateFine() const;
    void displayBookDetails() const;
};

#endif