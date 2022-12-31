#include "Bookshelf.h"

Bo0kshelf& Bookshelf::getInstance()
{
    if(instance == NULL)
        instance = new Bookshelf();
    return *instance;
}

void Bookshelf::sortBooks()
{
    std::sort(books.begin(), books.end());
}

std::ostream& operator<<(std::ostream& os, const Bookshelf& b)
{
    for(Book book : b.books)
    {
       os << book.get_author().get_surname() << " " << book.get_author().get_name() 
            << " \"" << book.get_title() << "\"";
        return os;
    }
}