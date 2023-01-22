#ifndef __BOOKSTORE_H__
#define __BOOKSTORE_H__

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "Orders.h"
#include "BookShelf.h"
#include "Seller.h"
#include "Customer.h" 


class BookStore
{
    private:
        Bookshelf bookshelf;
        int maxNumberOfSellers;
        int counterOfSellers;
        float budget;
        int idOfLastOrder;
        std::vector<std::shared_ptr<Order>> doneOrders;
        std::vector<std::shared_ptr<Customer> > customers;
        std::vector<std::shared_ptr<Seller> > sellers;


    public:
        BookStore(const Bookshelf& shelf): bookshelf(shelf), maxNumberOfSellers(3), counterOfSellers(0), budget(10000.0), idOfLastOrder(0){};
        BookStore(const Bookshelf& shelf, int numberOfSellers_, float storeBudget): bookshelf(shelf), maxNumberOfSellers(numberOfSellers_), counterOfSellers(0), budget(storeBudget), idOfLastOrder(0){};
        void addSeller(Seller &seller);
        void removeSeller(Seller &seller);
        void customerEntersStore(Customer &customer);
        void customerLeavesStore(Customer &customer);
        Bookshelf& getBooshelfInstance();
        int printSellers();
        std::shared_ptr<Seller> getSellerByNum(int num);
        float getBudget() const;
        void setBudget(float budget);
        
        //złożenie zamówienia
        void makeAnOrder(const Book& book, int quantity, const Customer& whoOrdered);
        
        //wycofanie zamówienia
        void removeAnOrder(int idOfOrderToRemove);

        //modyfikacja zamówienia
        void modifyAnOrder(int idOfOrderToRemove, int newQuantity);

        //wypis aktualnego stanu księgarni
        void printCurrentOrders();
        void showAvailableSellersWithQueues();

};


#endif