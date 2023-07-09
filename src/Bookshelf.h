#ifndef __BOOKSHELF__
#define __BOOKSHELF__

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "Book.h"

/**
 * Klasa Bookshelf reprezentująca regał z książkami. Zawiera wektor wskaźników na książki.
*/
class Bookshelf
{
    private:
        std::vector<std::shared_ptr<Book>> books;
        void sortBooks();
        std::shared_ptr<Book> findBookIfExist(const Book& book) const;
    public:
        Bookshelf(){};
        /**
         * Metoda dodająca książki do regału
         * @param book książka którą chcemy dodać
         * @param number ilość książek jaką dodajemy
        */
        void addBooks(const Book& book, unsigned int number);
        /**
         * Metoda usuwająca książki z regału
         * @param book książka którą chcemy usunać
         * @param number ilość książek, którą chcemy usunąć
        */
        void removeBooks(const Book& book, unsigned int number);
        /**
         * Metoda sprawdzająca ilość książek
         * @param book książka, której ilość chcemy znaleźć
        */
        unsigned int checkBooksNumber(const Book& book) const;
        /**
         * Metoda wypisująca książki w danej kategorii
         * @param category kategoria, z której książki mają być wypisane
        */
        void printBooksByCategory(Book::BookType category);
        
        friend std::ostream& operator<<(std::ostream& os, const Bookshelf& b);
        /**
         * Metoda zwracająca wszystkie książki znajdujące się na regale
        */
        std::vector<std::shared_ptr<const Book>> getBooks();
        /**
         * Metoda zwracająca książki o danym autorze
         * @param author autor
        */
        std::vector<std::shared_ptr<const Book>> getBooksByAuthor(Author author);
        /**
         * Metoda zwracająca książki o danym tytule
         * @param title tytuł
        */
        std::vector<std::shared_ptr<const Book>> getBooksByTytle(std::string title);
};

std::ostream& operator<<(std::ostream& os, const Bookshelf& b);

#endif