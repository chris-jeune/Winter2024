// Author: Christian Jeune, ID: 40279265

#ifndef TIME_H
#define TIME_H

#include <string>

class Time
{
public:
    Time(); // constructor
    Time(int h, int min, int sec,int d, int m, int y); // constructor 2
    Time(const Time&); // copy constructor

    void setTime(int h, int min, int sec, int d, int m, int y); // set hour, minute, second
    void printTime() const; // print time
    int getHour() const; // get hour
    int getMinute() const; // get minute
    int getSecond() const; // get second
    int getDay() const; // get day
    std::string getMonth() const; // get month
    int getYear() const; // get year

private:
    static const std::string months[12];
    int day; // 1 - 31
    std::string month; // 1 - 12 (index for months)
    int year; // 1900 - 2100
    int hour; // 0 - 23 (24-hour clock format)
    int minute; // 0 - 59
    int second; // 0 - 59
};

#endif // TIME_H
