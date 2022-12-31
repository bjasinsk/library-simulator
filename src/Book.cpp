#include "Book.h"
#include "ExceptionsLibrary.h"

Book::Book(Author new_author, std::string new_title, std::string new_isbn, double new_price, unsigned int publication) 
    : author(new_author), title(new_title), isbn(new_isbn), price(new_price), publication_year(publication)
{
    if(new_price <= 0.0)
        throw ExceptionLibraryWrongValue("Price must be positive\n");
}

Author Book::get_author() const
{
    return author;
}

std::string Book::get_title() const
{
    return title;
}

std::string Book::get_isbn() const
{
    return isbn;
}

double Book::get_price() const
{
    return price;
}

void Book::set_price(double price)
{
    if(new_price <= 0.0)
        throw ExceptionLibraryWrongValue("Price must be positive\n");
}
unsigned int Book::get_publication_year() const
{
    return publication_year;
}

std::ostream& operator<<(std::ostream& os, const Book& b)
{
    os << b.author << " \"" << b.title << "\" " << b.publication_year << " " << b.price << "zl" << std::endl;
    return os;
}