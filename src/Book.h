#ifndef __BOOK_H__
#define __BOOK_H__

#include <iostream>
#include "Author.h"

class Book
{
    protected:
        Author author;
        std::string isbn;
        unsigned publication_year;
        double base_price;

    public:
        Book(Author new_author, std::string new_tittle, std::string new_isbn, double new_price);
        void print() const;
        virtual double calculate_price() const;
        virtual ~Book();

        Author get_author() const;
        std::string get_title() const;
        std::string get_isbn() const;
        unsigned get_publication_year() const;
        double get_publication_year() const;
};

#endif