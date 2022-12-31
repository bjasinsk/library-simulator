#ifndef __BOOKSHELF__
#define __BOOKSHELF__

#include <iostream>
#include <memory>
#include <vector>
#include<algorithm>
#include "Book.h"

class Bookshelf
{
    private:
        std::vector<std::shared_ptr<Book>> books;
        Bookshelf(){};
        static Bookshelf* instance;
        void sortBooks();
    public:
        static Bookshelf& getInstance();
        void addBooks(const Book& book, unsigned int number);
        void removeBooks(const Book& book, unsigned int number);
        bool checkBookExist(const Book& book);
        unsigned int checkBooksNumber(const Book& book);
        friend std::ostream& operator<<(std::ostream& os, const Bookshelf& b);
};

std::ostream& operator<<(std::ostream& os, const Bookshelf& b);

#endif