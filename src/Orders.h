#ifndef __ORDERS__
#define __ORDERS__

#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Customer.h"
#include "Bookshelf.h"
// #include "BookStore.h"
#include "Date.h"

class Order
{
    private:
        int orderId;
        Date dateOfOrder;
        Book book;
        int quantity;
        Customer whoOrdered;


    public:
        Order(int orderId_, Date dateOfOrder_, Book book_, int quantity_, Customer whoOrdered_):
        orderId(orderId_), dateOfOrder(dateOfOrder_), book(book_), quantity(quantity_), whoOrdered(whoOrdered_) {}

        int getOrderId() const;
        Date getDateOfOrder() const;
        Book getOrderedBook() const;
        int getQuantity() const;
        Customer getCustomer() const;

        void setQuantity(int quantity_);
        
};

#endif