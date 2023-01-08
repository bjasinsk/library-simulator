#include "Orders.h"

void Orders:: addBookToOrder(const Book& book){
    std::shared_ptr<Book> orderedBook (new Book(book));
    booksToOrder.push_back(orderedBook);
};


