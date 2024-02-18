// Author: Christian Jeune, ID: 40279265

#include "Time.h" 
#include <iostream> 
#include <iomanip> 

// Define the array of months
const std::string Time::months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Time constructor initializes each data member to zero and ensures all Time objects start in a consistent state
Time::Time() : hour(0), minute(0), second(0), day(1), month(months[0]), year(1900) {}

// Time constructor initializes data members with user input
Time::Time(int h1, int m1, int s1, int d1, int mo1, int y1)
{
    hour = (h1 >= 0 && h1 < 24) ? h1 : 0;
    minute = (m1 >= 0 && m1 < 60) ? m1 : 0;
    second = (s1 >= 0 && s1 < 60) ? s1 : 0;
    day = (d1 >= 1 && d1 < 32) ? d1 : 1;
    month = (mo1 >= 1 && mo1 < 13) ? months[mo1 - 1] : months[0];
    year = (y1 >= 1900 && y1 < 2101) ? y1 : 1900;
}

// Copy constructor
Time::Time(const Time &other)
{
    hour = other.hour;
    minute = other.minute;
    second = other.second;
    day = other.day;
    month = other.month;
    year = other.year;
}

// Getter for hour
int Time::getHour() const
{
    return hour;
}

// Getter for minute
int Time::getMinute() const
{
    return minute;
}

// Getter for second
int Time::getSecond() const
{
    return second;
}

// Getter for day
int Time::getDay() const
{
    return day;
}

// Getter for month
std::string Time::getMonth() const
{
    return month;
}

// Getter for year
int Time::getYear() const
{
    return year;
}

// Set new Time value using universal time, perform validity checks on the data values and set invalid values to zero
void Time::setTime(int h, int m, int s, int d, int mo, int y)
{
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
    day = (d >= 1 && d < 32) ? d : 1;
    month = (mo >= 1 && mo < 13) ? months[mo - 1] : months[0];
    year = (y >= 1900 && y < 2101) ? y : 1900;
}

// Print Time
void Time::printTime() const
{
    // Set the fill character to '0' and the width for each field
    std::cout << std::setfill('0') << std::setw(2) << hour << "h" << std::setw(2) << minute << "m" << std::setw(2) << second << "s, " << day << " " << month << " " << year;
}


