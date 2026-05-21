#include <iostream>
using namespace std;

// Function to display the menu
void showMenu() {
    cout << "\n--- Banking System Menu ---" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Funds" << endl;
    cout << "3. Withdraw Funds" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    int secretPIN = 6677; // Updated PIN
    int inputPIN;
    double balance = 5000.0;
    int choice;

    cout << "Enter your PIN: ";
    cin >> inputPIN;

    if (inputPIN == secretPIN) {
        bool isActive = true;
        while (isActive) {
            showMenu();
            cout << "Select an action: ";
            cin >> choice;

            switch (choice) {
                case 1: cout << "Current Balance: $" << balance << endl; break;
                case 2: balance += 500; cout << "Deposit successful." << endl; break;
                case 3: balance -= 100; cout << "Withdrawal successful." << endl; break;
                case 4: isActive = false; cout << "Thank you for using our service." << endl; break;
                default: cout << "Invalid choice, please try again." << endl;
            }
        }
    } else {
        cout << "Incorrect PIN. Access Denied." << endl;
    }
    return 0;
}