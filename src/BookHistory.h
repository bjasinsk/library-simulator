#ifndef __HISTORY__
#define __HISTORY__

#include <iostream>
#include "Book.h"

class BookHistory : public Book
{
    private:

    public:
        BookHistory(Author new_author, std::string new_title, double new_price, unsigned int publication_year)
            : Book(new_author, new_title, new_price, publication_year){};
        std::string getCategory() const {return "History";};
};

#endif