#ifndef __SCI_FI__
#define __SCI_FI__

#include <iostream>
#include "Book.h"

class BookSciFi : public Book
{
    private:

    public:
        BookSciFi(Author new_author, std::string new_title, std::string new_isbn, double new_price, unsigned int publication_year)
            : Book(new_author, new_title, new_isbn, new_price, publication_year){};
        std::string getCategory() const {return "Sci-fi";};
};

#endif