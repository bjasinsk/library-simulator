#ifndef __BOOKSTORE__
#define __BOOKSTORE__

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "BookShelf.h"
#include "Seller.h"
#include "Customer.h"
#include "Orders.h"

class BookStore
{
    private:
        Bookshelf bookshelf;

        std::vector<std::shared_ptr<Order>> doneOrders;

        std::vector<std::shared_ptr<Customer> > customers;
        std::vector<std::shared_ptr<Seller> > sellers;

        int maxNumberOfSellers;
        int counterOfSellers;
        float budget;

        int idOfLastOrder;

    public:
        BookStore(const Bookshelf& shelf): bookshelf(shelf), maxNumberOfSellers(3), counterOfSellers(0), budget(10000.00), idOfLastOrder(0){};

        BookStore(const Bookshelf& shelf, int numberOfSellers_, float bookstoreBudget_): bookshelf(shelf), maxNumberOfSellers(numberOfSellers_),budget(bookstoreBudget_), counterOfSellers(0), idOfLastOrder(0){};
        void addSeller(Seller &seller);
        void removeSeller(Seller &seller);
        void customerEntersStore(Customer &customer);
        void customerLeavesStore(Customer &customer);

        //budżet sklepu
        float getBudget() const;
        void setBudget(float budget);
        Bookshelf& getBooshelfInstance();
        int printSellers();
        std::shared_ptr<Seller> getSellerByNum(int num);
        //zamówienia:
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