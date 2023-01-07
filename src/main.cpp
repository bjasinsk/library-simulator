#include <iostream>
#include "Time.h"
#include "Bookshelf.h"
#include "Author.h"
#include <vector>
#include <list>
#include <utility>

int main()
{   
    Bookshelf bookshelf;

    Author author_karol_may = Author("Karol", "Maj");
    Author author_bernard_cornwell = Author("Bernard", "Cornwell");
    
    bookshelf.addBooks(Book(author_karol_may, "Skarb w srebrnym jeziorze", 29.99, 2014, Book::BookType::ADVENTURE), 10);
    bookshelf.addBooks(Book(author_karol_may, "Winnetou", 24.99, 2015, Book::BookType::ADVENTURE), 20);
    bookshelf.addBooks(Book(author_bernard_cornwell, "Ostatnie krolestwo", 39.99, 2018, Book::BookType::HISTORY), 15);
    bookshelf.addBooks(Book(author_bernard_cornwell, "Piesn miecza", 39.99, 2018, Book::BookType::HISTORY), 15);

    std::cout << bookshelf;

    return 0;
}
