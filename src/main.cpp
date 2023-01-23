#include <iostream>
#include "Time.h"
#include "Bookshelf.h"
#include "Author.h"
#include <vector>
#include <list>
#include <utility>
#include <ctime>

#include <chrono>
#include <thread>

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
    JsonFile::getInstance().readData("C:\\Users\\danie\\Desktop\\PROI\\projekt\\src\\data.json", sklep1);
    Menu menu(sklep1);
    menu.mainMenu();    
    return 0;
}
