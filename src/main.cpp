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

int main()
{   
    BookStore sklep1;
    Bookshelf bookshelf;

    Author author_karol_may = Author("Karol", "Maj");
    Author author_bernard_cornwell = Author("Bernard", "Cornwell");
    
    bookshelf.addBooks(Book(author_karol_may, "Skarb w srebrnym jeziorze", 29.99, 2014, Book::BookType::ADVENTURE), 10);
    bookshelf.addBooks(Book(author_karol_may, "Winnetou", 24.99, 2015, Book::BookType::ADVENTURE), 20);
    bookshelf.addBooks(Book(author_bernard_cornwell, "Ostatnie krolestwo", 39.99, 2018, Book::BookType::HISTORY), 15);
    bookshelf.addBooks(Book(author_bernard_cornwell, "Piesn miecza", 39.99, 2018, Book::BookType::HISTORY), 15);

    
    std::cout << bookshelf;

    Customer tomek = Customer("Tomek", "Kowalski", 30);
    Book b1 = Book(author_karol_may, "Skarb w srebrnym jeziorze", 29.99, 2014, Book::BookType::ADVENTURE);
    tomek.addToShoppingCart(b1);
    tomek.printActualShoppingCart();

    std::cout << "\n";
    Seller sprzedawca1 = Seller("Adam", "Kowalczyk", 30, bookshelf);
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
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));    
    sklep1.customerLeavesStore(tomek);
    

    
    return 0;
}
