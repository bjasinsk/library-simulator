#ifndef __SELLER__
#define __SELLER__

#include <iostream>
#include <queue>
#include "Human.h"
#include "Customer.h"
#include "Bookshelf.h"
#include "BookHistory.h"

class Seller : public Human
{
    private:
        //w księgarni pracuje pewna liczba sprzedawców, do każdego sprzedawcy ustawia się kolejka
        std::queue<std::shared_ptr<Customer>> q;
        Bookshelf books;
    public:
        Seller(std::string name, std::string surname, int age, Bookshelf& books) : Human(name, surname, age), books(books) {};

        //obsługa klienta, wyliczanie rachunku 
        void addCustomerToQueue(Customer &client);
        void removeCustomerFromQueue();
        double BillForFirstCustomerInQueue();


        //zapytaj sprzedawce o książke
        void checkAvailabilityByTitle (std::string title);
        void showBooksByAuthor (std::string name, std::string surname);
        void showBooksByCategory (std::string category);

        
        //porównania
        bool operator==(const Seller &seller) const;

};

#endif