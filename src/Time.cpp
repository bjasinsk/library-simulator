#include "Time.h"

Time::Time(int hour, int minute, int seconds)
{
    setHour(hour);
    setMinute(minute);
    setSecond(seconds);
}

bool Time::operator==(const Time &other) const
{
    if(other.hour == this->hour && other.minute == this->minute && other.second == this->second)
        return true;
    else
        return false;
}

bool Time::operator!=(const Time &other) const
{
    return !(*this==other); 
}

bool Time::operator>(const Time &other) const
{
    if(hour != other.hour)
        return hour > other.hour;
    if(minute != other.minute)
        return minute>other.minute;
    return second > other.second;
}

bool Time::operator<(const Time &other) const
{
    if(hour != other.hour)
        return hour < other.hour;
    if(minute != other.minute)
        return minute < other.minute;
    return second < other.second;
}

bool Time::operator>=(const Time &other) const
{
    return !(*this<other);
}

bool Time::operator<=(const Time &other) const
{
    return !(*this>other);
}

Time& Time::operator++()
{
    if(second<59)
        second++;
    else
    {
        second = 0;
        if(minute < 59)
            minute++;
        else
        {
            minute = 0;
            if(hour < 23)
                hour++;
            else
            {
                hour = 0;
                //TODO: change date;
            }
        }
    }
    return *this;
}


Time Time::operator++(int)
{
    Time old_time(*this);
    ++(*this);
    return old_time;
}

int Time::getHour() const
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}

int Time::getSeconds() const
{
    return second;
}

void Time::setHour(int hour)
{
    if (hour < 0)
        throw ExceptionLibraryWrongValue("Hour must be 0-23\n");
    if (hour > 23)
        throw ExceptionLibraryWrongValue("Hour must be 0-23\n");
    this->hour = hour;
}

void Time::setMinute(int minute)
{
    if (minute < 0)
        throw ExceptionLibraryWrongValue("Minutes must be 0-59\n");
    if (hour > 59)
        throw ExceptionLibraryWrongValue("Minutes must be 0-59\n");
    this->minute = minute;
}

void Time::setSecond(int second)
{
    if (second < 0)
        throw ExceptionLibraryWrongValue("Seconds must be 0-59\n");
    if (second > 59)
        throw ExceptionLibraryWrongValue("Seconds must be 0-59\n");
    this->second = second;
}

std::ostream& operator<<(std::ostream& os, const Time& time)
{
    os << time.hour << "." << time.minute << "." << time.second;
    return os;
}

Time Time::TimeBetweenOtherTime(const Time& other){
    int timeBeetwenInSeconds;
    int otherTimeInSeconds = other.getHour() * 3600 + other.getMinute() * 60 + other.getSeconds();
    int thisTimeInSeconds = this->getHour() * 3600 + this->getMinute() * 60 + this->getSeconds();
    

    if(*this >= other){
        timeBeetwenInSeconds = thisTimeInSeconds - otherTimeInSeconds;
    }else{
        timeBeetwenInSeconds = otherTimeInSeconds - thisTimeInSeconds;
    }
    
    int h = timeBeetwenInSeconds/3600;
    int m = (timeBeetwenInSeconds - h*3600) /60;
    int s = timeBeetwenInSeconds - h*3600 -m*60;
    return Time(h,m,s);
};
