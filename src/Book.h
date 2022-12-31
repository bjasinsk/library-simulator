#ifndef __BOOK_H__
#define __BOOK_H__

#include <iostream>
#include "Author.h"

class Book
{
    private:
        Author author;
        std::string isbn;
        unsigned int publication_year;
        double price;
        std::string title;

    public:
        Book(Author new_author, std::string new_title, std::string new_isbn, double new_price, unsigned int publication_year);
        Author get_author() const;
        std::string get_title() const;
        std::string get_isbn() const;
        double get_price() const;
        void set_price(double price);
        unsigned int get_publication_year() const;
        get_publication_year() const;
        friend std::ostream& operator <<(std::ostream& os, const Book& book);
};

std::ostream& operator<<(std::ostream& os, const Book& book);

#endif