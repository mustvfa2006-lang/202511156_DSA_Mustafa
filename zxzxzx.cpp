#include <iostream>
using namespace std;


int totalMarks(int a, int b, int c) {
    return a + b + c;
}

int main() {

    string name;
    int s1, s2, s3, total;
    float average;
    char choice;

    do {

        cout << "Enter Student Name: ";
        cin >> name;

        cout << "Enter Subject 1 Marks: ";
        cin >> s1;

        cout << "Enter Subject 2 Marks: ";
        cin >> s2;

        cout << "Enter Subject 3 Marks: ";
        cin >> s3;

      
        total = totalMarks(s1, s2, s3);

       
        average = total / 3.0;

       
        cout << "\nStudent Name: " << name << endl;
        cout << "Total: " << total << endl;
        cout << "Average: " << average << endl;

       
        if (average >= 50) {
            cout << "Result: PASS" << endl;
        } else {
            cout << "Result: FAIL" << endl;
        }

        cout << "\nAdd another student? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}