#include "LibraryBook.h"
#include "Functions.h"
#include <iostream>
using namespace std;
int main() {
    LibraryBook library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

   
    library[bookCount++] = LibraryBook(101, "Object Oriented Prog C++", "Kamate Katende");
    library[bookCount++] = LibraryBook(102, "Data Structures & Algos", "Robert Sedgewick");

    do {
        cout << "\n=========================================\n";
        cout << "     LIBRARY BOOK BORROWING SYSTEM       \n";
        cout << "=========================================\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book by ID\n";
        cout << "6. Display Overdue Books\n";
        cout << "7. Calculate Total Fines\n";
        cout << "8. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        switch(choice) {
            case 1:
                addBook(library, bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                borrowBookMenu(library, bookCount);
                break;
            case 4:
                returnBookMenu(library, bookCount);
                break;
            case 5:
                searchBook(library, bookCount);
                break;
            case 6:
                displayOverdueBooks(library, bookCount);
                break;
            case 7:
                calculateTotalFines(library, bookCount);
                break;
            case 8:
                cout << "Exiting system. Thank you for using our library!\n";
                break;
            default:
                cout << "Invalid Option! Please enter a number from 1 to 8.\n";
        }
    } while (choice != 8);

    return 0;
}