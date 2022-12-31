#ifndef __Date_H__
#define __Date_H__

#include <iostream>

class Date
{
    private:
        int day{1};
        unsigned month{1};
        unsigned year{1900};
    public:
        Date(); //kons. domyślny
        //~Date(); //dest. nieuzywany
        Date(unsigned day, unsigned month, int year); // konstruktor argumentowy
        Date(const Date& source); //konstruktor kopiujacy
        Date& operator=(const Date& source); //operator przypisania

        unsigned get_day();
        unsigned get_month();
        int get_year();
        void set_day(unsigned day);
        void set_year(int year);
        void set_month(unsigned month);

        Date& operator++(); //preinkrementacja
        Date operator++(int); //postinkrementacja
        bool operator==(const Date& other) const;
        bool operator!=(const Date& other) const;
        bool operator>(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator>=(const Date& other) const;
        bool operator<=(const Date& other) const;

        static bool is_leap_year(int year);
        friend std::ostream& operator <<(std::ostream& os, const Date& date);
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif