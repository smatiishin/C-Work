/* Sam Matiishin
CSC 223
Description: This is the implementation file used to create the functions for the Clock class*/

#pragma once
#include "Clock.h"
#include <iostream>

using namespace std;


/* Function name: Clock()
   Return: None
   Description: This is a constructor function that takes custom parameters and creates a clock object
 */
Clock::Clock(int hour = 0, int minute = 0, int second = 0)
{
    hours = hour;
    minutes = minute;
    seconds = second;
}

/* Function name: getHours()
   Return: Int
   Description: This is an accessor function that returns a clock object's hours
 */
int Clock::getHours()
{
    return hours;
}

/* Function name: getMinutes()
   Return: Int
   Description: This is an accessor function that returns a clock object's minutes
 */
int Clock::getMinutes()
{
    return minutes;
}

/* Function name: getSeconds()
   Return: Int
   Description: This is an accessor function that returns a clock object's seconds
 */
int Clock::getSeconds()
{
    return seconds;
}

/* Function name: setHours()
   Return: none
   Description: This is a modifier function that updates a clock object's hours
 */
void Clock::setHours(int hour)
{
    hours = hour;
}

/* Function name: setMinutes()
   Return: none
   Description: This is a modifier function that updates a clock object's minutes
 */
void Clock::setMinutes(int minute)
{
    minutes = minute;
}

/* Function name: setSeconds()
   Return: none
   Description: This is a modifier function that updates a clock object's seconds
 */
void Clock::setSeconds(int second)
{
    seconds = second;
}


/* Function name: operator<()
   Return: Bool
   Description: This is an overload function that returns true if an alarm digit is less than a current time digit
 */
bool Clock::operator< (const Clock& clock) const 
{
    // Check hour digits
    if (hours < clock.hours) 
    {
        return true;
    }
    else if (hours > clock.hours)
    {
        return false;
    }

    // Check minute digits
    if (minutes < clock.minutes)
    {
        return true;
    }
    else if (minutes > clock.minutes)
    {
        return false;
    }

    // Check second digits
    if (seconds < clock.seconds)
    {
        return true;
    }
    else if (seconds > clock.seconds)
    {
        return false;
    }

    return false;
}

/* Function name: operator>()
   Return: Bool
   Description: This is an overload function that returns true if an alarm digit is greater than a current time digit
 */
bool Clock::operator> (const Clock& clock) const 
{
    // Check hour digits
    if (hours > clock.hours)
    {
        return true;
    }
    else if (hours < clock.hours)
    {
        return false;
    }

    // Check minute digits
    if (minutes > clock.minutes)
    {
        return true;
    }
    else if (minutes < clock.minutes)
    {
        return false;
    }

    // Check second digits
    if (seconds > clock.seconds)
    {
        return true;
    }
    else if (seconds < clock.seconds)
    {
        return false;
    }

    return false;
}

/* Function name: operator==()
   Return: Bool
   Description: This is an overload function that returns true if all alarm digits are equal to a current time digits
 */
bool Clock::operator==(const Clock& clock) const 
{
    if (hours == clock.hours && minutes == clock.minutes && seconds == clock.seconds)
    {
        return true;
    } else {
        return false;
    }
}

/* Function name: operator<=()
   Return: Bool
   Description: This is an overload function that returns true if an alarm digit is less than or equal to a current time digit
 */
bool Clock::operator<=(const Clock& clock) const 
{
    if (*this < clock || *this == clock)
    {
        return true;
    }
    else {
        return false;
    }
}

/* Function name: operator<()
   Return: Bool
   Description: This is an overload function that returns true if an alarm digit is greater than or equal to a current time digit
 */
bool Clock::operator>=(const Clock& clock) const 
{
    if (*this > clock || *this == clock)
    {
        return true;
    }
    else {
        return false;
    }
}

/* Function name: operator!=()
   Return: Bool
   Description: This is an overload function that returns true if an alarm digit is not equal to a current time digit
 */
bool Clock::operator!=(const Clock& clock) const 
{
    if (*this == clock)
    {
        return false;
    }
    else {
        return true;
    }
}

/* Function name: operator++()
   Return: Object
   Description: This is an overload function that updates a clock object's seconds/minutes/hours
 */
Clock Clock::operator++() 
{
    (*this)++;
    return *this;
}

/* Function name: operator++()
   Return: Object
   Description: This is an overload function that updates a clock object's seconds/minutes/hours accepting a paramter (digit)
 */
Clock Clock::operator++(int) {

    // Initialize objects and variables
    Clock tempClock(hours, minutes, seconds);

    // Increment the time, using limits to begin counting the next set of digits if surpassed
    seconds++;
    if (seconds == 60) {
        minutes++;
        seconds = 0;
        if (minutes == 60) {
            minutes = 0;
            hours++;
            if (hours == 24) {
                hours = 0;
            }
        }
    }
    return tempClock;
};

/* Function name: operator<<()
   Return: Object
   Description: This is an overload function that uses the iostream interface to output the current time and alarm time
 */
ostream& operator << (ostream& out, const Clock& clock)
{
    // Output digits and include leading 0's if any digits are 9 or less
    if (clock.hours < 10 || clock.minutes < 10 || clock.seconds < 10)
    {
        if (clock.hours < 10)
        {
            out << "0" << clock.hours << ":";
        } else {
            out << clock.hours << ":";
        }
        if (clock.minutes < 10)
        {
            out << "0" << clock.minutes << ":";
        } else {
            out << clock.minutes << ":";
        }
        if (clock.seconds < 10)
        {
            out << "0" << clock.seconds;
        } else {
            out << clock.seconds;
        }
    } else {
        out << clock.hours << ":" << clock.minutes << ":" << clock.seconds;
    }

    return out;
}

/* Function name: operator>>()
   Return: Object
   Description: This is an overload function that uses the iostream interface to accept input for the current time and alarm time
 */
istream& operator >> (istream& in, Clock& clock)
{
    in >> clock.hours >> clock.minutes >> clock.seconds;
    return in;
}
