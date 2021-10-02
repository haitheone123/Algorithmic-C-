#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

int CheckValidation(string Username) {
    int n = Username.length();
    for (int i = 0; i < n - 1; i++) {
        if (Username[i] == 'w' && Username[i + 1] == 'w') {
            return 0;
        }
    }

    return 1;


}


void CheckUsername(string Username) {
    int n = Username.length();
    if (n < 5) {
        cout << "Too short:" << n << endl;
    }
    if (CheckValidation(Username) == 0) {
        cout << "Invalid" << endl;
    }
    else if (CheckValidation(Username) == 1) {
        cout << "Valid" << endl;
    }


}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t - 1; i++) {
        string Username;
        cin >> Username;
        CheckUsername(Username);


    }
}