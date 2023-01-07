#ifndef __TIME_H__
#define __TIME_H__

#include <iostream>
#include "ExceptionsLibrary.h"

class Time
{
    private:
        int hour;
        int minute;
        int second;
    public:
        
        Time():hour(0), minute(0), second(0){};

        Time(int hour, int minte, int seconds);
        //default copy and assignment constructors
        bool operator==(const Time& other) const;
        bool operator!=(const Time& other) const;
        bool operator>(const Time& other) const;
        bool operator<(const Time& other) const;
        bool operator>=(const Time& other) const;
        bool operator<=(const Time& other) const;
        Time& operator++();
        Time operator++(int);
        int getHour() const;
        int getMinute() const;
        int getSeconds() const;
        void setHour(int hour);
        void setMinute(int minute);
        void setSecond(int second);
        friend std::ostream& operator <<(std::ostream& os, const Time& time);
};

std::ostream& operator<<(std::ostream& os, const Time& time);

#endif