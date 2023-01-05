#ifndef __COOKERY__
#define __COOKERY__

#include <iostream>
#include "Book.h"

class BookCookery : public Book
{
    private:

    public:
        BookCookery(Author new_author, std::string new_title, double new_price, unsigned int publication_year)
            : Book(new_author, new_title, new_price, publication_year){};
        std::string getCategory() const {return "Cookery";};
};

#endif