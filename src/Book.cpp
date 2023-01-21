#include "Book.h"
#include "ExceptionsLibrary.h"
#include <random>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

std::unordered_map<Book::BookType, std::string> Book::type_map
{
    {ADVENTURE, "Adventure"},
    {COOKERY, "Cookery"},
    {CRIME, "Crime"},
    {HISTORY, "History"},
    {SCIFI, "Sci-fi"},
    {POETRY, "Poetry"}
};

Book::Book(Author new_author, std::string new_title, double new_price, unsigned int publication, BookType t)
    : author(new_author), title(new_title), price(new_price), publication_year(publication), type(t)
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
    return BookType_to_string(type);
}

Book::BookType Book::getCategoryEnum() const
{
    return type;
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
    return type_map[b];
}

template <typename T1, typename T2>
T1 find_key(std::unordered_map<T1, T2> &m, T2 value)
{
    auto it = std::find_if(m.begin(), m.end(),
                           [&](const std::pair<T1, T2> &p)
                           { return p.second == value; });
    if (it != m.end())
        return it->first;
    else
        throw std::invalid_argument("Value not found in map");
}

Book::BookType Book::string_to_BookType(std::string category)
{
    return find_key(type_map, category);
}