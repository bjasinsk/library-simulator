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
#include "Date.h"

/**
 * Klasa Order reprezentująca zamówienie złożone przez klienta. Ma pola id zamówienia, data publikacji, książka dodana do zamówienia, ilość w jakiej została zamówiona oraz pole reprezentujące kto złożył zamówienie.
*/
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
        /**
         * Metoda zwracająca id zamówienia
        */
        int getOrderId() const;
        /**
         * Metoda zwracająca date złożenia zamówienia
        */
        Date getDateOfOrder() const;
        /**
         * Metoda zwracająca książke która została zamówiona
        */
        Book getOrderedBook() const;
        /**
         * Metoda zwracająca ile sztuk danej książki zostało zamówione
        */
        int getQuantity() const;
        /**
         * Metoda zwracająca klienta, który złożył dane zamówienie
        */
        Customer getCustomer() const;
        /**
         * Metoda ustawiająca ilość danej książki w złożonym zamówieniu
        */
        void setQuantity(int quantity_);
        
};

#endif