/* Sam Matiishin
CSC 223
Description: This program tests the Clock object and it's implementation file*/

#include "Clock.h"

using namespace std;

int main()
{
    // Initialize objects and variables
    int hours, minutes, seconds;
    Clock currentTime(0,0,0), alarmTime(0,0,0);

    cout << "Welcome to the program!" << endl << "You will enter the current time, followed by the alarm time, and watch the " <<
        "alarm go off at the assigned time" << endl;

    // Obtain user input of current time
    cout << endl << "Please enter the current time (format: xx xx xx): " << endl;
    cin >> currentTime;

    // Obtain user input of alarm time
    cout << endl << "Please enter the alarm time (format: xx xx xx): " << endl;
    cin >> alarmTime;

    // Loop that increments the clock until the alarm has been triggered
    while (alarmTime != currentTime)
    {
        system("cls");
        Sleep(1);
        currentTime++;
        cout << endl << "Current Time: " << endl << currentTime << endl;
        cout << endl << "Alarm Time: " << endl << alarmTime << endl;
    }

    // Display active message once alarm has been triggered
    cout << endl << "***ALARM ACTIVE***";
}