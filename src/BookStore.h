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

/**
 * Klasa BookStore reprezentująca księgarnie.
*/
class BookStore
{
    private:
        Bookshelf bookshelf;
        int maxNumberOfSellers;
        int counterOfSellers;
        int idOfLastOrder;
        std::vector<std::shared_ptr<Order> > doneOrders;
        std::vector<std::shared_ptr<Customer> > customers;
        std::vector<std::shared_ptr<Seller> > sellers;
        std::shared_ptr<float> budget;


    public:
        BookStore(const Bookshelf& shelf): bookshelf(shelf), maxNumberOfSellers(3), counterOfSellers(0), idOfLastOrder(0){budget = std::make_shared<float>(10000);};
        BookStore(const Bookshelf& shelf, int numberOfSellers_, float storeBudget): bookshelf(shelf), maxNumberOfSellers(numberOfSellers_), counterOfSellers(0), idOfLastOrder(0){budget = std::make_shared<float>(storeBudget);};
        /**
         * Metoda dodająca Sprzedawce do księgarni
         * @param seller sprzedawca
        */
        void addSeller(Seller &seller);
        /**
         * Metoda usuwająca Sprzedawce z księgarni
         * @param seller sprzedawca
        */
        void removeSeller(Seller &seller);
        /**
         * Metoda, dzięki której klient wchodzi do księgarni
         * @param customer klient
        */
        void customerEntersStore(Customer &customer);
        /**
         * Metoda, dzięki której klient wychodzi z księgarni
         * @param customer klient
         */ 
        void customerLeavesStore(Customer &customer);
        Bookshelf& getBooshelfInstance();
        /**
         * Metoda wypisujaca sprzedawców bedących aktualnie w księgarni
        */
        int printSellers();
        /**
         * Metoda wypisująca klientów będących aktualnie w księgarni
        */
        int printCutomers();
        /**
         * Metoda, dzięki której możliwy jest wybór sprzedawcy po konkretnym numerze
        */
        std::shared_ptr<Seller> getSellerByNum(int num);
        /**
         * Metoda, dzięki której możliwy jest wybór klienta po konkretnym numerze
        */
        std::shared_ptr<Customer> getCustomerByNum(int num);
        /**
         * Metoda zwracająca budżet księgarni
        */
        float getBudget() const;
        /**
         * Metoda ustawiająca budżet księgarni
         * @param budget budżet księgarni
        */
        void setBudget(float budget);
        /**
         * Metoda dodająca określoną kwotę do budżetu księgarni
         * @param cash określona kwota
        */
        void addCash(float cash);
        /**
         * Metoda odejmująca określoną kwotę z budżetu księgarni
         * @param cash określona kwota
        */
        void getCash(float cash);
        /**
         * Metoda zwracająca budżet księgarni
        */
        std::shared_ptr<float> accessToBudget();
        /**
         * Metoda składająca zamówienie
         * @param book książka
         * @param quantity ilość książek
         * @param whoOrdered klient, który złożył zamówienie
        */
        void makeAnOrder(const Book& book, int quantity, const Customer& whoOrdered);
        
        /**
         * Metoda wycofująca zamówienie
         * @param idOfOrderToRemove id zamówienia, które chcemy usunać
        */
        void removeAnOrder(int idOfOrderToRemove);
        /**
         * Metoda modyfikująca zamówienie
         * @param idOfOrderToRemove id zamówienia, które chcemy zmodyfikować
         * @param newQuantity nowa ilość danej książki w zmodyfikowanym zamówieniu
        */
        void modifyAnOrder(int idOfOrderToRemove, int newQuantity);
        /**
         * Metoda wypisująca aktualny stan zamówień w księagrni
        */
        void printCurrentOrders();
        /**
         * Metoda wypisująca sprzedawców i ich kolejki
        */
        void showAvailableSellersWithQueues();

        void realizeOrders();

};


#endif