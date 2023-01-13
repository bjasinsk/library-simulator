#ifndef __MENU__
#define __MENU__

#include "BookStore.h"

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
};

#endif