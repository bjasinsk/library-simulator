#include <iostream>

#include "Bookshelf.h"
#include "Author.h"
#include "Human.h"
#include "Customer.h"
#include "Seller.h"
#include "BookStore.h"
#include "JsonFile.h"
#include "Menu.h"

int main()
{   
    Bookshelf bookshelf;
    BookStore sklep1(bookshelf);
    JsonFile::getInstance().readData("src\\data.json", sklep1);
    Menu menu(sklep1);
    menu.mainMenu();    
    return 0;
}
