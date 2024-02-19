// Author: Christian Jeune, ID: 40279265

#ifndef TIME_H
#define TIME_H

#include <string>

class Time
{
public:
    Time(); // constructor
    Time(int h, int min, int sec); // constructor 2
    Time(const Time&); // copy constructor

    void setTime(int h, int min, int sec); // set hour, minute, second
    void printTime() const; // print time
    int getHour() const; // get hour
    int getMinute() const; // get minute
    int getSecond() const; // get second
    
private:
    int hour; // 0 - 23 (24-hour clock format)
    int minute; // 0 - 59
    int second; // 0 - 59
};

#endif // TIME_H
