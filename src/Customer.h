#ifndef __CUSTOMER__
#define __CUSTOMER__

#include <iostream>
#include <list>
#include <map>
#include "Human.h"
#include "Book.h"

class Customer : public Human
{
    private:
        std::map<std::string, double> shoppingCart;
        double bill;
    public:
        Customer(std::string name, std::string surname) : Human(name, surname) {};

        //koszyk
        std::map<std::string, double> getShoppingCart() const;
        void printActualShoppingCart();
        void addToShoppingCart(Book& b);
        void removeFromShoppingCart(Book& b);

        //rachunek
        double getActualBill() const;
        void calculateBill();
};

#endif