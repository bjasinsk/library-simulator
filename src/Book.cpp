#include "Book.h"
#include "ExceptionsLibrary.h"
#include <random>
#include <string>
#include <sstream>
#include <iomanip>

Book::Book(Author new_author, std::string new_title, double new_price, unsigned int publication)
    : author(new_author), title(new_title), price(new_price), publication_year(publication)
{
    int num1, num2, num3, num4, num5;
    if (new_price <= 0.0)
        throw ExceptionLibraryWrongValue("Price must be positive\n");
    std::random_device rng;
    std::uniform_int_distribution<int> dist(0, 999);
    num1 = dist(rng);
    dist.param(std::uniform_int_distribution<>::param_type(0, 9));
    num2 = dist(rng);
    num5 = dist(rng);
    dist.param(std::uniform_int_distribution<>::param_type(0, 99));
    num3 = dist(rng);
    dist.param(std::uniform_int_distribution<>::param_type(0, 999999));
    num4 = dist(rng);
    std::stringstream ss;
    ss << std::setw(3) << std::setfill('0') << num1 << "-";
    ss << std::setw(1) << std::setfill('0') << num2 << "-";
    ss << std::setw(2) << std::setfill('0') << num3 << "-";
    ss << std::setw(6) << std::setfill('0') << num4 << "-";
    ss << std::setw(1) << std::setfill('0') << num5;
    isbn = ss.str();
}

std::string Book::getCategory() const
{
    return "Unknown";
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

unsigned int Book::getNumberOfBooks() const
{
    return number;
}

void Book::set_price(double new_price)
{
    if (new_price <= 0.0)
        throw ExceptionLibraryWrongValue("Price must be positive\n");
    price = new_price;
}

unsigned int Book::get_publication_year() const
{
    return publication_year;
}

void Book::addBooks(unsigned int number)
{
    this->number += number;
}

unsigned int Book::removeBooks(unsigned int number)
{
    if (this->number >= number)
    {
        this->number -= number;
        return number;
    }
    else
    {
        this->number = 0;
        return this->number;
    }
}

bool Book::operator==(const Book &b) const
{
    return this->author == b.author && this->title == b.title;
}

std::ostream &operator<<(std::ostream &os, const Book &b)
{
    os << b.author << " \"" << b.title << "\" " << b.publication_year << " " << b.isbn << " " << b.price << "zl" << std::endl;
    return os;
}

std::string Book::BookType_to_string(BookType b)
{
    std::unordered_map<BookType, std::string> m{
        {ADVENTURE, "Adventure"},
        {COOKERY, "Cookery"},
        {CRIME, "Crime"},
        {HISTORY, "History"},
        {SCIFI, "Sci-fi"}};
    return m[b];
}