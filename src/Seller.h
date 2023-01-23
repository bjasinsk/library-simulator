#ifndef __SELLER__
#define __SELLER__

#include <iostream>
#include <queue>
#include "Human.h"
#include "Customer.h"
#include "Bookshelf.h"
#include "Book.h"
#include "Orders.h"

/**
 * Klasa Seller reprezentująca sprzedawce w księgarni.
*/
class Seller : public Human
{
    private:
        ///w księgarni pracuje pewna liczba sprzedawców, do każdego sprzedawcy ustawia się kolejka
        std::queue<std::shared_ptr<Customer>> q;
        Bookshelf books;
        std::shared_ptr<float> budgetOfStore;
    public:
        Seller(std::string name, std::string surname, Bookshelf& books, std::shared_ptr<float> budget) : Human(name, surname), books(books), budgetOfStore(budget) {};

        
        /**
         * Metoda dodająca klienta do kolejki sprzedawcy
         * @param new_customer klient dodany do kolejki
        */
        void addCustomerToQueue(std::shared_ptr<Customer> new_customer);
        /**
         * Metoda usuwająca klient z kolejki sprzedawcy
        */
        void removeCustomerFromQueue();
        /**
         * metoda obsługująca pierwszego klienta w kolejce
        */
        void serveFirstCustomerInQueue();


        /**
         * Metoda sprawdzająca dostępność ksiązki po tytule
         * @param title tytuł książki
        */
        void checkAvailabilityByTitle (std::string title);
        /**
         * Metoda pokazaująca książki danego autora
         * @param name imie autora
         * @param surname nazwisko autora
        */
        void showBooksByAuthor (std::string name, std::string surname);
        /**
         * Metoda pokazująca książki z danej kategorii
         * @param category kategoria, z której mają być pokazane książki
        */
        void showBooksByCategory (std::string category);

        //porównania
        bool operator==(const Seller &seller) const;

        std::queue<std::shared_ptr<Customer>> getQueueOfCustomers() const;
        void printQueueOfCustomers();
};


#endif