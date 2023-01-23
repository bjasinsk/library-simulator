#ifndef __MENU__
#define __MENU__

#include "BookStore.h"
#include <memory>

/**
 * Klasa Menu reprezentująca menu użytkownika, symulacji księgarni.
*/
class Menu
{
    private:
        BookStore* bookstore;

        
    public:
        Menu(const BookStore& bookstore);
        void mainMenu();
        void booksMenu();
        Book::BookType chooseBookCategory();
        std::string getStringFromUser();
        void sellersMenu();
        void customersMenu();
        void sellerOptionsMenu(std::shared_ptr<Seller> seller); //zamawianie ksiazek, albo wykorzystanie pointera z parametru, albo przekazywac jako wartosc. Do rozwazenia
        void customerOptionsMenu(std::shared_ptr<Customer> customer);
        std::shared_ptr<const Book> getBook();

        

};

#endif