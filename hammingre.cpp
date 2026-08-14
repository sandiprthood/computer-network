#include <iostream>
#include <string>
using namespace std;
int main()
{
    int h[12] = {0};
    string code;
    cout << "Enter 11-bit received Hamming code: ";
    cin >> code;
    for (int i = 0; i < 11; i++)
    {
        h[11 - i] = code[i] - '0';
    }
    int R1, R2, R4, R8;
    int count1 = h[1] + h[3] + h[5] + h[7] + h[9] + h[11];

    if (count1 % 2 == 0)
        R1 = 0;      
    else
        R1 = 1;  

    int count2 = h[2] + h[3] + h[6] + h[7] + h[10] + h[11];
    if (count2 % 2 == 0)
        R2 = 0;      
    else
        R2 = 1;      

    int count4 = h[4] + h[5] + h[6] + h[7];

    if (count4 % 2 == 0)
        R4 = 0;       
    else
        R4 = 1;    

    int count8 = h[8] + h[9] + h[10] + h[11];
    if (count8 % 2 == 0)
        R8 = 0;       
    else
        R8 = 1;

    cout << "\nR1 = " << R1;
    if (R1 == 0)
        cout << " (Even)";
    else
        cout << " (Odd)";
    cout << "\nR2 = " << R2;
    if (R2 == 0)
        cout << " (Even)";
    else
        cout << " (Odd)";
    cout << "\nR4 = " << R4;
    if (R4 == 0)
        cout << " (Even)";
    else
        cout << " (Odd)";
    cout << "\nR8 = " << R8;
    if (R8 == 0)
        cout << " (Even)";
    else
        cout << " (Odd)";


    int errorPosition = R1 * 1 + R2 * 2 + R4 * 4 + R8 * 8;

    if (errorPosition == 0)
    {
        cout << "\n\nNo error detected.";
    }
    else
    {
        cout << "\n\nError detected at position: "
             << errorPosition;
        if (h[errorPosition] == 0)
            h[errorPosition] = 1;
        else
            h[errorPosition] = 0;
        cout << "\nCorrected Hamming code: ";
        for (int i = 11; i >= 1; i--)
        {
            cout << h[i];
        }
    }
    cout << endl;

    return 0;
}

//                   output receiver hamming

// Enter 11-bit received Hamming code: 10101101110

// R1 = 0 (Even)
// R2 = 1 (Odd)
// R4 = 1 (Odd)
// R8 = 0 (Even)

// Error detected at position: 6
// Corrected Hamming code: 10101001110