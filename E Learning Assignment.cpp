#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <regex>
using namespace std;
class User {
private:
    string name;
    string email;
    string phone;
public:
    User() {}
    User(string n, string e, string p) {
        name = n;
        email = e;
        phone = p;
    }
    string getName() { return name; }
    string getEmail() { return email; }
    string getPhone() { return phone; }
    void setName(string n) { name = n; }
    void setEmail(string e) { email = e; }
    void setPhone(string p) { phone = p; }
};
class VehicleOwner : public User {
public:
    VehicleOwner() {}
    VehicleOwner(string n, string e, string p)
        : User(n, e, p) {}
};
class Vehicle {
private:
    string plateNumber;
    string vehicleType;
    int year;
    VehicleOwner owner;
public:
    Vehicle() {}
    Vehicle(string plate, string type, int y, VehicleOwner o) {
        plateNumber = plate;
        vehicleType = type;
        year = y;
        owner = o;
    }
    string getPlateNumber() { return plateNumber; }
    string getVehicleType() { return vehicleType; }
    int getYear() { return year; }
    VehicleOwner getOwner() { return owner; }
    string toCSV() {
        stringstream ss;
        ss << plateNumber << ","
           << vehicleType << ","
           << year << ","
           << owner.getName() << ","
           << owner.getEmail() << ","
           << owner.getPhone();
        return ss.str();
    }
};
bool validEmail(string email) {
    return email.find('@') != string::npos &&
           email.find('.') != string::npos;
}
bool validPhone(string phone) {
    regex pattern("^\\+250[0-9]{9}$");
    return regex_match(phone, pattern);
}
bool validPlate(string plate) {
    regex pattern("^[A-Z]{3}[0-9]{3}[A-Z]$");
    return regex_match(plate, pattern);
}
void addRecord() {
    string plate, type, name, email, phone;
    int year;
    do {
        cout << "Plate Number (RAA123A): ";
        cin >> plate;
    } while (!validPlate(plate));
    cout << "Vehicle Type: ";
    cin >> type;
    cout << "Year: ";
    cin >> year;
    cin.ignore();
    cout << "Owner Name: ";
    getline(cin, name);
    do {
        cout << "Email: ";
        getline(cin, email);
    } while (!validEmail(email));
    do {
        cout << "Phone (+250xxxxxxxxx): ";
        getline(cin, phone);
    } while (!validPhone(phone));
    VehicleOwner owner(name, email, phone);
    Vehicle vehicle(plate, type, year, owner);
    ofstream file("records.txt", ios::app);
    if (file.is_open()) {
        file << vehicle.toCSV() << endl;
        file.close();
        cout << "\nRecord Saved Successfully.\n";
    }
}
void displayRecords() {
    ifstream file("records.txt");
    string line;
    cout << left
         << setw(12) << "Plate"
         << setw(12) << "Type"
         << setw(8) << "Year"
         << setw(20) << "Owner"
         << setw(25) << "Email"
         << setw(15) << "Phone" << endl;
    cout << string(90, '-') << endl;
    while (getline(file, line)) {
        stringstream ss(line);
        string plate, type, year, name, email, phone;
        getline(ss, plate, ',');
        getline(ss, type, ',');
        getline(ss, year, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        cout << left
             << setw(12) << plate
             << setw(12) << type
             << setw(8) << year
             << setw(20) << name
             << setw(25) << email
             << setw(15) << phone
             << endl;
    }
    file.close();
}
void searchVehicle() {
    string target;
    cout << "Enter Plate Number: ";
    cin >> target;
    ifstream file("records.txt");
    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string plate, type, year, name, email, phone;
        getline(ss, plate, ',');
        getline(ss, type, ',');
        getline(ss, year, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        if (plate == target) {
            cout << "\nVehicle Found\n";
            cout << "Plate: " << plate << endl;
            cout << "Type: " << type << endl;
            cout << "Year: " << year << endl;
            cout << "Owner: " << name << endl;
            cout << "Email: " << email << endl;
            cout << "Phone: " << phone << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Vehicle Not Found.\n";
    file.close();
}
int main() {
    int choice;
    do {
        cout << "\n===== Vehicle Registration System =====\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            displayRecords();
            break;
        case 3:
            searchVehicle();
            break;
        case 4:
            cout << "Goodbye\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }
    } while (choice != 4);
    return 0;
}