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

/**
 * Klasa Customer reprezentująca klienta w ksiegarni. Ma pola koszyk sklepowy, rachunek, czas wejścia do sklepu, czas wyjścia ze sklepu.
*/
class Customer : public Human
{
    private:
        std::vector<std::shared_ptr<Book>> shoppingCart;
        double bill;
        Time timeOfEntrance;
        Time timeOfLeave;
    public:
        Customer(std::string name, std::string surname) : Human(name, surname) {
        };

        //koszyk
        std::vector<std::shared_ptr<Book>> getShoppingCart() const;
        /**
         * Metoda wypisujaca aktualny koszyk klienta
        */
        void printActualShoppingCart();
        /**
         * Metoda dodająca książke do koszyka
         * @param book książka, którą chcemy dodać do koszyka
        */
        void addToShoppingCart(const Book &book);
        /**
         * Metoda usuwająca książke z koszyka
         * @param book książka, którą chcemy usunać
        */
        void removeFromShoppingCart(Book &book);
        /**
         * Metoda, odpowiadająca za wykonanie transakcji, opróżnienie koszyka i zapłacenie przez klienta
        */
        void buyShoppingCart();

        /**
         * Metoda zwracająca aktualny rachunek klienta
        */
        double getActualBill() const;
        /**
         * Metoda wyliczająca rachunek dla klienta
        */
        void calculateBill();

        /**
         * Metoda zwracająca czas wejścia klienta do księgarni
        */
        Time getTimeOfEntrance() const;
        /*
         * Metoda ustawiająca czas wejścia klienta do księgarni
        */
        void setTimeOfEntrance(Time t);
        /**
         * Metoda zwracająca czas wyjścia klienta z księgarni
        */
        Time getTimeOfLeave() const;
        /**
         * Metoda ustawiająca czas wyjścia klienta z księgarni
        */
        void setTimeOfLeave(Time t);
        
        //porównania
        bool operator==(const Customer &customer) const;
};

#endif