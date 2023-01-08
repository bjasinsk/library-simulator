#ifndef __CUSTOMER__
#define __CUSTOMER__

#include <memory>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "Human.h"
#include "Book.h"
#include "Time.h"


#include <ctime>

class Customer : public Human
{
    private:
        std::vector<std::shared_ptr<Book>> shoppingCart;
        double bill;
        Time timeOfEntrance;
        Time timeOfLeave;
    public:
        Customer(std::string name, std::string surname, int age) : Human(name, surname, age) {
        };

        //koszyk
        std::vector<std::shared_ptr<Book>> getShoppingCart() const;
        void printActualShoppingCart();
        void addToShoppingCart(Book &book);
        void removeFromShoppingCart(Book &book);

        //rachunek
        double getActualBill() const;
        void calculateBill();

        //czas pobytu
        Time getTimeOfEntrance() const;
        void setTimeOfEntrance(Time t);

        Time getTimeOfLeave() const;
        void setTimeOfLeave(Time t);
        
        //porównania
        bool operator==(const Customer &customer) const;
};

#endif