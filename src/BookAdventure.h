#ifndef __ADVENTURE__
#define __ADVENTURE__

#include <iostream>
#include "Book.h"

class BookAdventure : public Book
{
    private:

    public:
        BookAdventure(Author new_author, std::string new_title, double new_price, unsigned int publication_year)
            : Book(new_author, new_title, new_price, publication_year){};
        std::string getCategory() const {return BookType_to_string(ADVENTURE);};
};

#endif