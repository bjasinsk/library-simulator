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
        unsigned int number;

    public:
        Book(Author new_author, std::string new_title, std::string new_isbn, double new_price, unsigned int publication_year);
        Author get_author() const;
        std::string get_title() const;
        std::string get_isbn() const;
        double get_price() const;
        unsigned int get_publication_year() const;
        unsigned int getNumberOfBooks() const;
        void set_price(double price);
        virtual std::string getCategory() const;
        friend std::ostream& operator <<(std::ostream& os, const Book& book);
        void addBooks(unsigned int number);
        unsigned int removeBooks(unsigned int number);
};

std::ostream& operator<<(std::ostream& os, const Book& book);

#endif