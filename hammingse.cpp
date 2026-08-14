#include <iostream>
using namespace std;

int main()
{
    int h[12] = {0};

    cout << "Enter 7-bit data word: ";

    string data;
    cin >> data;

    if(data.length() != 7)
    {
        cout << "Please enter exactly 7 bits." << endl;
        return 0;
    }

    // Store data bits
    // Positions: 11 10 9 8 7 6 5 4 3 2 1
    //             D  D  D R D D D R D R R

    h[11] = data[0] - '0';
    h[10] = data[1] - '0';
    h[9]  = data[2] - '0';
    h[7]  = data[3] - '0';
    h[6]  = data[4] - '0';
    h[5]  = data[5] - '0';
    h[3]  = data[6] - '0';

    // Even parity

    // R1 checks positions 1,3,5,7,9,11
    h[1] = h[3] ^ h[5] ^ h[7] ^ h[9] ^ h[11];

    // R2 checks positions 2,3,6,7,10,11
    h[2] = h[3] ^ h[6] ^ h[7] ^ h[10] ^ h[11];

    // R4 checks positions 4,5,6,7
    h[4] = h[5] ^ h[6] ^ h[7];

    // R8 checks positions 8,9,10,11
    h[8] = h[9] ^ h[10] ^ h[11];

    cout << "\nData word: " << data << endl;

    cout << "Hamming Code: ";

    // Print from position 11 to 1
    for(int i = 11; i >= 1; i--)
    {
        cout << h[i];
    }

    cout << endl;

    return 0;
}

    //  Sender hamming output

// Enter 7-bit data word: 1011001

// Data word: 1011001
// Hamming Code: 10101001110
