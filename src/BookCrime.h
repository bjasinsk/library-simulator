#ifndef __CRIME__
#define __CRIME__

#include <iostream>
#include "Book.h"

class BookCrime : public Book
{
    private:

    public:
        BookCrime(Author new_author, std::string new_title, double new_price, unsigned int publication_year)
            : Book(new_author, new_title, new_price, publication_year){};
        std::string getCategory() const {return "Crime";};
};

#endif