#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    srand(time(0));

    int n;
    cout << "Enter number of frames: ";
    cin >> n;

    // Random frame which will be lost
    int lostFrame = rand() % n;

    // Random timer between 1 and 3 seconds
    int timer = 1 + rand() % 3;

    int seq = 0;

    cout << "\n========== STOP AND WAIT ARQ ==========\n";
    cout << "Lost Frame : " << lostFrame + 1 << endl;
    cout << "Timer             : " << timer << " second(s)" << endl;
    cout << "=======================================\n";

    for (int i = 0; i < n; i++)
    {
        bool success = false;

        while (!success)
        {
            cout << "\n[Sender]   : Sending Frame "
                 << i + 1 << " (Seq " << seq << ")" << endl;

            cout << "[Timer]    : Timer Started ("
                 << timer << " sec)" << endl;

            // Only selected frame is lost ONCE
            if (i == lostFrame)
            {
                cout << "[Channel]  : *** Frame "
                     << i + 1 << " LOST ***" << endl;

                this_thread::sleep_for(
                    chrono::seconds(timer));

                cout << "[Timer]    : TIMEOUT!" << endl;
                cout << "[Sender]   : Retransmitting Frame "
                     << i + 1 << "..." << endl;

                // Make sure it is not lost again
                lostFrame = -1;
            }
            else
            {
                cout << "[Receiver] : Frame "
                     << i + 1 << " received." << endl;

                cout << "[Receiver] : Sending ACK "
                     << seq << endl;

                cout << "[Sender]   : ACK "
                     << seq << " received." << endl;

                cout << "[Timer]    : Timer Stopped." << endl;

                success = true;
            }
        }

        seq = 1 - seq;
    }

    cout << "\n=======================================" << endl;
    cout << "All Frames Successfully Transmitted!" << endl;
    cout << "=======================================" << endl;

    return 0;
}