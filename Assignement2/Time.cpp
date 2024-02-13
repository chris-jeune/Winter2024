// Author: Christian Jeune, ID: 40279265
#include "Time.h" // include definition of class Time from Time.h

// Time constructor initializes each data member to zero and
// ensures all Time objects start in a consistent state     
Time::Time()                                                
{                                                           
    hour = 0;
    minute = 0;
    second = 0;                              
} // end Time constructor            

// Time constructor initializes data members with user input
Time::Time(int h1, int m1, int s1)                                                
{                                                           
    hour = ( h1 >= 0 && h1 < 24 ) ? h1 : 0;                     
    minute = ( m1 >= 0 && m1 < 60 ) ? m1 : 0;                   
    second = ( s1 >= 0 && s1 < 60 ) ? s1 : 0;                   
} // end Time constructor                                   

// Copy constructor
Time::Time(const Time& other)
{
    hour = other.hour;
    minute = other.minute;
    second = other.second;
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

// set new Time value using universal time, perform validity
// checks on the data values and set invalid values to zero 
void Time::setTime( int h, int m, int s )                   
{                                                           
    hour = ( h >= 0 && h < 24 ) ? h : 0;                     
    minute = ( m >= 0 && m < 60 ) ? m : 0;                   
    second = ( s >= 0 && s < 60 ) ? s : 0;                   
} // end function setTime                                   

// print Time
void Time::printTime()
{
    cout << hour << ":" << minute << ":" << second;
} // end function printTime

