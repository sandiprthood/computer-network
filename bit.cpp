#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    cout << "Enter binary string: ";
    cin >> n;

    int count = 0;

    for (int i = 0; i < n.length(); i++) {
        // Print current character
        cout << n[i];

        // Track consecutive '1's
        if (n[i] == '1') {
            count++;
        } else {
            count = 0; // Reset counter if character is '0'
        }

        // Bit stuffing: insert '0' after five consecutive '1's
        if (count == 5) {
            cout << '0';
            count = 0; // Reset counter after stuffing
        }
    }

    cout << endl;
    return 0;
}