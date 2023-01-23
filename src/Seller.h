#ifndef __SELLER__
#define __SELLER__

#include <iostream>
#include <queue>
#include "Human.h"
#include "Customer.h"
#include "Bookshelf.h"
#include "Book.h"
#include "Orders.h"

class Seller : public Human
{
    private:
        //w księgarni pracuje pewna liczba sprzedawców, do każdego sprzedawcy ustawia się kolejka
        std::queue<std::shared_ptr<Customer>> q;
        Bookshelf books;
        std::shared_ptr<float> budgetOfStore;
    public:
        Seller(std::string name, std::string surname, Bookshelf& books, std::shared_ptr<float> budget) : Human(name, surname), books(books), budgetOfStore(budget) {};

        //obsługa klienta, wyliczanie rachunku 
        void addCustomerToQueue(std::shared_ptr<Customer> new_customer);
        void removeCustomerFromQueue();
        void serveFirstCustomerInQueue();


        //zapytaj sprzedawce o książke
        void checkAvailabilityByTitle (std::string title);
        void showBooksByAuthor (std::string name, std::string surname);
        void showBooksByCategory (std::string category);

        //porównania
        bool operator==(const Seller &seller) const;

        std::queue<std::shared_ptr<Customer>> getQueueOfCustomers() const;
        void printQueueOfCustomers();
};


#endif