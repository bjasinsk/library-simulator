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
    /**
     * Metoda zwracająca autora ksiażki
    */
    Author get_author() const;
    /**
     * Metoda zwracają tytuł książki
    */
    std::string get_title() const;

    std::string get_isbn() const;
    /**
     * Metoda zwracająca cenę książki
    */
    double get_price() const;
    /**
     * Metoda zwracająca datę publikacji książki
    */
    unsigned int get_publication_year() const;
    /**
     * Metoda zwracająca ilość danej książki
    */
    unsigned int getNumberOfBooks() const;
    /**
     * Metoda ustawiająca cene danej książki
    */
    void set_price(double price);
    /**
     * Metoda zwracająca kategorie książki w typie Enum
    */
    BookType getCategoryEnum() const;
    /**
     * Metoda zwracająca kategorie książki w typie string
    */
    std::string getCategory() const;
    friend std::ostream &operator<<(std::ostream &os, const Book &book);
    /**
     * Metoda dodająca ilość książki
     * @param number ilość książek
    */
    void addBooks(unsigned int number);
    /**
     * Metoda usuwająca daną ilość książek
     * @param number ilość książek
    */
    unsigned int removeBooks(unsigned int number);
    bool operator==(const Book &b) const;
    static std::string BookType_to_string(BookType b);
    static Book::BookType string_to_BookType(std::string category);
    static std::unordered_map<BookType, std::string> type_map;
};

std::ostream &operator<<(std::ostream &os, const Book &book);

#endif