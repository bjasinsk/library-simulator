#ifndef __ORDERS__
#define __ORDERS__

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Bookshelf.h"

class Orders
{
    private:
        std::vector<std::shared_ptr<Book>> booksToOrder;
        Bookshelf Bookshelf;
        
    public:
        Orders(){};

        //złożenie zamówienia
        void addBookToOrder(const Book& book);
        
        //wycofanie zamówienia
        void removeBookFromOrder(const Book& book);

        //dostępność
        void checkDeliveryTime(const Book& book);



};

#endif