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
        /**
         * Metoda wyświetlające podstawowe menu symulacji księgarni
        */
        void mainMenu();
        /**
         * Metoda wyświetlająca menu po przejściu do zakładki Książki w podstawowym menu
        */
        void booksMenu();

        Book::BookType chooseBookCategory();
        /**
         * Metod pobierająca wprowadzony tekst przez użytkownika
        */
        std::string getStringFromUser();
        /**
         * Metoda wyświetlająca menu sprzedawcy, po przejściu do zakładki Sprzedawcy w podstawowym menu
        */
        void sellersMenu();
        /**
         * Metoda wyświetlająca menu klienta, po przejściu do zakładki Klienci w podstawowym menu
        */
        void customersMenu();
        /**
         * Metoda wyświetlająca menu konkretnego sprzedawcy, pokazująca czynności jakie może wykonać
         * @param seller sprzedawca
        */
        void sellerOptionsMenu(std::shared_ptr<Seller> seller); //zamawianie ksiazek, albo wykorzystanie pointera z parametru, albo przekazywac jako wartosc. Do rozwazenia
        /**
         * Metoda wyświetlająca menu konkretnego klienta, pokazująca czynności jakie może wykonać
         * @param customer klient
        */
        void customerOptionsMenu(std::shared_ptr<Customer> customer);
        std::shared_ptr<const Book> getBook();

        

};

#endif