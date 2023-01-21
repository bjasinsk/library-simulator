#ifndef __BOOKSTORE__
#define __BOOKSTORE__

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "BookShelf.h"
#include "Seller.h"
#include "Customer.h"


class BookStore
{
    private:
        Bookshelf Bookshelf;

        std::vector<std::shared_ptr<Customer> > customers;
        std::vector<std::shared_ptr<Seller> > sellers;

        int maxNumberOfSellers;
        int counterOfSellers;
        float budget;


    public:
        BookStore(): maxNumberOfSellers(3), counterOfSellers(0), budget(10000.00) {};
        BookStore(int numberOfSellers_, float bookstoreBudget_): 
        maxNumberOfSellers(numberOfSellers_), budget(bookstoreBudget_), counterOfSellers(0){};

        //pracownicy
        void addSeller(Seller &seller);
        void removeSeller(Seller &seller);

        //wchodzenie, wychodzenie klientów ze sklepu
        void customerEntersStore(Customer &customer);
        void customerLeavesStore(Customer &customer);

        float getBudget() const;
        void setBudget(float budget);

};


#endif