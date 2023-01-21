#ifndef __ORDERS__
#define __ORDERS__

#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Seller.h"
#include "Book.h"
#include "Customer.h"
#include "Bookshelf.h"
#include "BookStore.h"
#include "Date.h"

struct order{
    int orderId;
    Date dateOfOrder;
    Book book;
    int quantity;
    Customer whoOrdered;
    order(int orderId_, Date dateOfOrder_, Book book_, int quantity_, Customer whoOrdered_):
    orderId(orderId_), dateOfOrder(dateOfOrder_), book(book_), quantity(quantity_), whoOrdered(whoOrdered_) {}

};

class Orders
{
    private:
        std::vector<std::shared_ptr<order>> doneOrders;
        BookStore bookStore;
        int idOfLastOrder;

    public:
        Orders(BookStore& bookStore_): bookStore(bookStore_), idOfLastOrder(0){};

        //złożenie zamówienia
        void makeAnOrder(const Book& book, int quantity, const Customer& whoOrdered);
        
        //wycofanie zamówienia
        void removeAnOrder(int idOfOrderToRemove);

        //modyfikacja zamówienia
        void modifyAnOrder(int idOfOrderToRemove, int newQuantity);

        //dostępność
        void checkDeliveryTime(const Book& book);
};

#endif