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

    Author author_karol_may = Author("Karol", "Maj");
    Author author_bernard_cornwell = Author("Bernard", "Cornwell");
    std::cout << bookshelf;

    Customer tomek = Customer("Tomek", "Kowalski");
    Book b1 = Book(author_karol_may, "Skarb w srebrnym jeziorze", 29.99, 2014, Book::BookType::ADVENTURE);
    tomek.addToShoppingCart(b1);
    tomek.printActualShoppingCart();

    std::cout << "\n";
    Seller sprzedawca1 = Seller("Adam", "Kowalczyk", bookshelf);
    sprzedawca1.addCustomerToQueue(tomek);
    std::cout << sprzedawca1.BillForFirstCustomerInQueue();

    std::cout << "\n";
    sprzedawca1.showBooksByAuthor("Karol", "Maj");
    std::cout << "\n";
    sprzedawca1.checkAvailabilityByTitle("Winnetou");
    std::cout << "\n";
    sprzedawca1.showBooksByCategory("History");

    sklep1.customerEntersStore(tomek);
    std:: cout << "\n";
    // czas pobytu 20 sekund
    // std::this_thread::sleep_for(std::chrono::milliseconds(20000));    
    sklep1.customerLeavesStore(tomek);
    

    

    
    return 0;
}
