#include <iostream>
#include <string>
using namespace std;


string bitStuffing(string data)
{
    string stuffed = "";
    int count = 0;

    for (char bit : data)
    {
        stuffed += bit;

        if (bit == '1')
        {
            count++;

        
            if (count == 5)
            {
                stuffed += '0';
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    return stuffed;
}

int main()
{
    string sender;

    cout << "Enter  bit sender stream: ";
    cin >> sender;

    string output = bitStuffing(sender);

    cout << "Input : " << sender << endl;
    cout << "Output: " << output << endl;

    return 0;
}