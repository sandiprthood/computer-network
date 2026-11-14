#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string ip;
    cout << "Enter IPv4 Address: ";
    cin >> ip;
    stringstream ss(ip);
    string part;
    vector<int> octet;

    while (getline(ss, part, '.')) {
        if (part.empty()) {
            cout << "Invalid IPv4 Address!" << endl;
            return 0;
        }
        for (char c : part) {
            if (!isdigit(c)) {
                cout << "Invalid IPv4 Address!" << endl;
                return 0;
            }
        }
        int value = stoi(part);
        if (value < 0 || value > 255) {
            cout << "Invalid IPv4 Address!" << endl;
            return 0;
        }
        octet.push_back(value);
    }
    if (octet.size() != 4) {
        cout << "Invalid IPv4 Address!" << endl;
        return 0;
    }
    if (octet[0] == 0) {
        cout << "Invalid IPv4 Address!" << endl;
        return 0;
    }
    int first = octet[0];
    string ipClass;
    string defaultMask;
    int networkBits;
    int hostBits;
    if (first >= 1 && first <= 126) {
        ipClass = "A";
        defaultMask = "255.0.0.0";
        networkBits = 8;
        hostBits = 24;
    }
    else if (first >= 128 && first <= 191) {
        ipClass = "B";
        defaultMask = "255.255.0.0";
        networkBits = 16;
        hostBits = 16;
    }
    else if (first >= 192 && first <= 223) {
        ipClass = "C";
        defaultMask = "255.255.255.0";
        networkBits = 24;
        hostBits = 8;
    }
    else if (first >= 224 && first <= 239) {
        cout << "\nValid IPv4 Address" << endl;
        cout << "Class D - Multicast Address" << endl;
        return 0;
    }
    else if (first >= 240 && first <= 255) {
        cout << "\nValid IPv4 Address" << endl;
        cout << "Class E - Experimental/Reserved Address" << endl;
        return 0;
    }
    else {
        cout << "Invalid IPv4 Address!" << endl;
        return 0;
    }
    int network[4];
    int host[4];

    if (ipClass == "A") {

        network[0] = octet[0];
        network[1] = 0;
        network[2] = 0;
        network[3] = 0;

        host[0] = 0;
        host[1] = octet[1];
        host[2] = octet[2];
        host[3] = octet[3];
    }
    else if (ipClass == "B") {

        network[0] = octet[0];
        network[1] = octet[1];
        network[2] = 0;
        network[3] = 0;

        host[0] = 0;
        host[1] = 0;
        host[2] = octet[2];
        host[3] = octet[3];
    }

    else {

        network[0] = octet[0];
        network[1] = octet[1];
        network[2] = octet[2];
        network[3] = 0;

        host[0] = 0;
        host[1] = 0;
        host[2] = 0;
        host[3] = octet[3];
    }
    cout << "\n------ IPv4 INFORMATION ------\n";

    cout << "IP Address       : "
         << octet[0] << "."
         << octet[1] << "."
         << octet[2] << "."
         << octet[3] << endl;

    cout << "Status           : Valid IPv4 Address" << endl;

    cout << "Class            : " << ipClass << endl;

    cout << "Default Mask     : " << defaultMask << endl;

    cout << "Network Bits     : " << networkBits << endl;

    cout << "Host Bits        : " << hostBits << endl;

    cout << "Network Address      : "
         << network[0] << "."
         << network[1] << "."
         << network[2] << "."
         << network[3] << endl;

    cout << "Host ID          : "
         << host[0] << "."
         << host[1] << "."
         << host[2] << "."
         << host[3] << endl;
    return 0;
}
