#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Transaction history log
    vector<string> logs = {"User Login", "Account Inquiry", "Profile Update"};
    
    cout << "--- Transaction History ---" << endl;
    
    for (const string& record : logs) {
        cout << "Logged Activity: " << record << endl;
    }
    
    return 0;
}