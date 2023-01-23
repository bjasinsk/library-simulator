#ifndef __BOOK_H__
#define __BOOK_H__

#include <iostream>
#include "Author.h"
#include <unordered_map>

/**
 * Klasa Book reprezentująca książke.
*/
class Book
{
public:
    enum BookType
    {
        ADVENTURE,
        COOKERY,
        CRIME,
        HISTORY,
        SCIFI, 
        POETRY
    };
 
private:
    Author author;
    std::string title;
    double price;
    unsigned int publication_year;
    BookType type;
    std::string isbn;
    unsigned int number;

public:
    Book(Author new_author, std::string new_title, double new_price, unsigned int publication_year, BookType type);
    Author get_author() const;
    std::string get_title() const;
    std::string get_isbn() const;
    double get_price() const;
    unsigned int get_publication_year() const;
    unsigned int getNumberOfBooks() const;
    void set_price(double price);
    BookType getCategoryEnum() const;
    std::string getCategory() const;
    friend std::ostream &operator<<(std::ostream &os, const Book &book);
    void addBooks(unsigned int number);
    unsigned int removeBooks(unsigned int number);
    bool operator==(const Book &b) const;
    static std::string BookType_to_string(BookType b);
    static Book::BookType string_to_BookType(std::string category);
    static std::unordered_map<BookType, std::string> type_map;
};

std::ostream &operator<<(std::ostream &os, const Book &book);

#endif