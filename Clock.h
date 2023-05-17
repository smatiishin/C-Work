/* Sam Matiishin
CSC 223
Description: This is a base class that creates a clock object*/


#pragma once
#include <iostream>
#include <stdlib.h>
#include <windows.h>

#ifndef H_Clock 
#define H_Clock

using namespace std;

class Clock
{
    // Allow iostream variables access to clock members
    friend ostream& operator<< (ostream&, const Clock&);
    friend istream& operator>> (istream&, Clock&);

// Initialize protected members
protected:
    int hours;
    int minutes;
    int seconds;

// Initialize public members
public:
    Clock(int hour, int minute, int second);
    int getHours();
    int getMinutes();
    int getSeconds();
    void setHours(int hour);
    void setMinutes(int minute);
    void setSeconds(int second);
    bool operator<(const Clock&) const;
    bool operator>(const Clock&) const;
    bool operator==(const Clock&) const;
    bool operator<=(const Clock&) const;
    bool operator>=(const Clock&) const;
    bool operator!=(const Clock&) const;
    Clock operator++();
    Clock operator++(int);

};

#endif