#ifndef __MENU__
#define __MENU__

#include "BookStore.h"
#include <memory>

class Menu
{
    private:
        BookStore* bookstore;
        std::shared_ptr<Seller> seller;

        
    public:
        Menu(const BookStore& bookstore);
        void mainMenu();
        void booksMenu();
        Book::BookType chooseBookCategory();
        std::string getStringFromUser();
        void sellersMenu();
        void customersMenu();
        void sellerOptionsMenu(); //zamawianie ksiazek, albo wykorzystanie pointera z parametru, albo przekazywac jako wartosc. Do rozwazenia
        void customerOptionsMenu(std::shared_ptr<Customer> customer);
        const Book& getBook();

        

};

#endif