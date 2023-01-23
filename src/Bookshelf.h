#ifndef __BOOKSHELF__
#define __BOOKSHELF__

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "Book.h"

class Bookshelf
{
    private:
        std::vector<std::shared_ptr<Book>> books;
        void sortBooks();
        std::shared_ptr<Book> findBookIfExist(const Book& book) const;
    public:
        Bookshelf(){};
        void addBooks(const Book& book, unsigned int number);
        void removeBooks(const Book& book, unsigned int number);
        unsigned int checkBooksNumber(const Book& book) const;
        void printBooksByCategory(Book::BookType category);
        friend std::ostream& operator<<(std::ostream& os, const Bookshelf& b);
        std::vector<std::shared_ptr<const Book>> getBooks();
        std::vector<std::shared_ptr<const Book>> getBooksByAuthor(Author author);
        std::vector<std::shared_ptr<const Book>> getBooksByTytle(std::string title);
};

std::ostream& operator<<(std::ostream& os, const Bookshelf& b);

#endif