#include <iostream>
#include <string>
using namespace std;

string divide(string code, string div)
{
    int n = code.length();
    int m = div.length();

    for (int i = 0; i <= n - m; i++)
    {
        if (code[i] == '1')
        {
            for (int j = 0; j < m; j++)
            {
                if (code[i + j] == div[j])
                    code[i + j] = '0';
                else
                    code[i + j] = '1';
            }
        }
    }

    return code.substr(n - m + 1);
}

int main()
{
    string code, div, rem;
    cout << "Enter Received Code Word: ";
    cin >> code;
    cout << "Enter Divisor: ";
    cin >> div;
    rem = divide(code, div);
    cout << "\nReceived Code Word : " << code << endl;
    cout << "Divisor            : " << div << endl;
    cout << "Remainder          : " << rem << endl;
    bool error = false;
    for (char x : rem)
    {
        if (x == '1')
        {
            error = true;
            break;
        }
    }

    if (error)
        cout << "Result             : ERROR DETECTED!" << endl;
    else
        cout << "Result             : NO ERROR" << endl;

    return 0;
}