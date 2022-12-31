#include "Date.h"
#include "ExceptionsLibrary.h"

Date::Date() : day{1}, month{1}, year{1900}
{}

Date::Date(unsigned day, unsigned month, int year)
{
    set_day(day);
    set_month(month);
    set_year(year);
}

Date::Date(const Date& source)
{
    this -> year = source.year;
    this -> month = source.month;
    this -> day = source.day;
}

Date& Date::operator=(const Date& source)
{
    if(this != &source)
    {
        year = source.year;
        month = source.month;
        day = source.day;
    }
    return *this;
}

Date& Date::operator++()
{
    switch(day)
    {
        case 31:
            day = 1;
            if(month == 12)
            {
                month = 1;
                year++;
            } else {
                month++;
            }        
            break;
        case 30:
            if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                day++;
            } else {
                day = 1;
                month++;
            }       
            break;
        case 29:
            if(month == 2)
            {
                day = 1;
                month++;
            } else {
                day++;
            }
            break;
        case 28:
            if(month != 2 || (month == 2 && is_leap_year(year)))
            {
                day++;
            } 
            if(month == 2 && !is_leap_year(year))
            {
                day = 1;
                month++;
            }
            break;
        default:
            day++;
    }
    return *this;
}


Date Date::operator++(int)
{
    Date old_date(*this);
    ++(*this);
    return old_date;
}

bool Date::operator==(const Date& other) const
{
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator!=(const Date& other) const
{
    return !(*this==other);
}

bool Date::operator<(const Date& other) const
{
    if(year != other.year)
        return year < other.year;
    if(month != other.month)
        return month < other.month;
    return day < other.day;
}

bool Date::operator>(const Date& other) const
{
    if(year != other.year)
        return year > other.year;
    if(month != other.month)
        return month > other.month;
    return day > other.day;
}

bool Date::operator<=(const Date& other) const
{
    return !(*this > other);
}

bool Date::operator>=(const Date& other) const
{
    return !(*this < other);
}

unsigned Date::get_day()
{
    return day;
}

unsigned Date::get_month()
{
    return month;
}

int Date::get_year()
{
    return year;
}

void Date::set_day(unsigned day)
{
    if(month == 2)
    {
        if(day < 1)
            throw ExceptionLibraryWrongValue("Day cannot be less than 1");
        else if(day > 28 && !is_leap_year(year))
            throw ExceptionLibraryWrongValue("Day is too high");
        else if(day > 29)
            throw ExceptionLibraryWrongValue("Day is too high");
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if(day > 31 || day < 1)
            throw ExceptionLibraryWrongValue("Day is too high or too low");
    }
    else
    {
        if(day > 30 || day < 1)
            throw ExceptionLibraryWrongValue("Day is too high or too low");
    }

    this->day = day;
}

void Date::set_month(unsigned month)
{
    if(month < 1 || month > 12)
        throw ExceptionLibraryWrongValue("Month not correct");
    if(day > 28 && month == 2 && is_leap_year(year))
        throw ExceptionLibraryWrongValue("Month not correct for leap year");
    if(day > 29 && month == 2)
        throw ExceptionLibraryWrongValue("Month not correct");
    if(day > 30 && (month==4 || month==6|| month==9 || month==11))
        throw ExceptionLibraryWrongValue("Month not correct");
    this->month = month;
}

void Date::set_year(int year)
{
    if(month == 2)
        if(day == 29 && !is_leap_year(year))
            throw ExceptionLibraryWrongValue("Leap year not correct due to set day");
    this->year = year;
}

bool Date::is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.day << "." << date.month << "." << date.year;
    return os;
}