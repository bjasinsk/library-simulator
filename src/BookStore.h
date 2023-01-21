#ifndef __BOOKSTORE_H__
#define __BOOKSTORE_H__

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
        Bookshelf bookshelf;

        std::vector<std::shared_ptr<Customer> > customers;
        std::vector<std::shared_ptr<Seller> > sellers;

        int maxNumberOfSellers;
        int counterOfSellers;
        float budget;

    public:
        BookStore(const Bookshelf& shelf): bookshelf(shelf), maxNumberOfSellers(3), counterOfSellers(0), budget(10000.0){};
        BookStore(const Bookshelf& shelf, int numberOfSellers_, float storeBudget): bookshelf(shelf), maxNumberOfSellers(numberOfSellers_), counterOfSellers(0), budget(storeBudget){};
        void addSeller(Seller &seller);
        void removeSeller(Seller &seller);
        void customerEntersStore(Customer &customer);
        void customerLeavesStore(Customer &customer);
        Bookshelf& getBooshelfInstance();
        int printSellers();
        std::shared_ptr<Seller> getSellerByNum(int num);
        float getBudget() const;
        void setBudget(float budget);
};


#endif