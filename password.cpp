#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string generatePassword(int length, bool useDigits, bool useSymbols) {
    const string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string digits = "0123456789";
    const string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    string chars = letters;
    if (useDigits) chars += digits;
    if (useSymbols) chars += symbols;

    srand(time(0));
    string password;
    for (int i = 0; i < length; ++i) {
        password += chars[rand() % chars.size()];
    }
    return password;
}

int main() {
    int length;
    bool digits, symbols;

    if (length < 6) {
        cout << "Password must be at least 6 characters long!" << endl;
        return 1;
    }
    cout << "Password length: ";
    cin >> length;
    cout << "Digits (1/0): ";
    cin >> digits;
    cout << "Symbols (1/0): ";
    cin >> symbols;

    string password = generatePassword(length, digits, symbols);
    cout << "Your password: " << password << endl;

    return 0;
}