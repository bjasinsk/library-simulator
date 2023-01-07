#include <iostream>
#include "Time.h"
#include "Bookshelf.h"
#include "BookAdventure.h"
#include "BookCookery.h"
#include "BookCrime.h"
#include "BookHistory.h"
#include "BookSciFI.h"
#include "Author.h"
#include <vector>
#include <list>
#include <utility>


#include "Human.h"
#include "Customer.h"
#include "Seller.h"

int main()
{   
    Bookshelf bookshelf;

    Author author_karol_may = Author("Karol", "Maj");
    Author author_bernard_cornwell = Author("Bernard", "Cornwell");
    
    bookshelf.addBooks(BookAdventure(author_karol_may, "Skarb w srebrnym jeziorze", 29.99, 2014), 10);
    bookshelf.addBooks(BookAdventure(author_karol_may, "Winnetou", 24.99, 2015), 20);
    bookshelf.addBooks(BookHistory(author_bernard_cornwell, "Ostatnie krolestwo", 39.99, 2018), 15);
    bookshelf.addBooks(BookHistory(author_bernard_cornwell, "Piesn miecza", 39.99, 2018), 15);

    
    std::cout << bookshelf;

    Customer tomek = Customer("Tomek", "Kowalski", 30);
    BookAdventure b1 = BookAdventure(author_karol_may, "Skarb w srebrnym jeziorze", 29.99, 2014);
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
    return 0;
}
