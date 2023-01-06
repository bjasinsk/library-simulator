#ifndef __SELLER__
#define __SELLER__

#include <iostream>
#include <queue>
#include "Human.h"
#include "Customer.h"

class Seller : public Human
{
    private:
        //w księgarni pracuje pewna liczba sprzedawców, do każdego sprzedawcy ustawia się kolejka
        std::queue<Customer> q;
    public:
        Seller(std::string name, std::string surname) : Human(name, surname) {};

        //obsługa klienta, wyliczanie rachunku 
        void addCustomerToQueue(Customer client);
        void removeCustomerFromQueue();
        double BillForFirstCustomerInQueue();
};

#endif