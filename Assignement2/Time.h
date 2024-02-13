// Author: Christian Jeune, ID: 40279265

#ifndef TIME_H
#define TIME_H

#include <iostream>

using std::cout;
using std::endl;

#include <iomanip>

// Time abstract data type (ADT) definition
class Time
{

public:
    Time();                      // constructor
    Time(int, int, int);         // constructor 2
    Time(const Time&);           // copy constructor
                       
    void setTime(int, int, int); // set hour, minute, second
    void printTime();            // print time
    int getHour() const;         // get hour
    int getMinute() const;       // get minute
    int getSecond() const;       // get second
private:
    int hour;   // 0 - 23 (24-hour clock format)
    int minute; // 0 - 59
    int second; // 0 - 59

}; // end class Time

#endif // TIME_H