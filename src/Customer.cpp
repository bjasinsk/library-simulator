#include "Customer.h"
#include <iostream>
#include <map>
#include "Book.h"
#include "Seller.h"
#include <algorithm>


std::vector<std::shared_ptr<Book>> Customer::getShoppingCart() const{
    return shoppingCart;
};


void Customer::printActualShoppingCart(){

    std::cout << "Aktualny koszyk Klienta: \n";

    for (auto i: shoppingCart){
        std::cout <<"Tytuł: " <<  i->get_title() << "\n";
    }
};


void Customer::addToShoppingCart(Book &book){

    std::shared_ptr<Book> new_book (new Book(book));
    shoppingCart.push_back(new_book);
};


void Customer::removeFromShoppingCart(Book &book){

    for(std::vector<std::shared_ptr<Book>>::iterator it = shoppingCart.begin(); it != shoppingCart.end(); ++it)
        {
            if(**it == book)
            {
                shoppingCart.erase(it);
                break;
            }
        }
};


double Customer::getActualBill() const {
    return bill;
};


void Customer::calculateBill(){
    bill = 0;
    for(std::shared_ptr<Book> b: shoppingCart){
        bill += b->get_price();
    }
};

Time Customer::getTimeOfEntrance() const{
    return timeOfEntrance;
};


void Customer::setTimeOfEntrance(Time t){
    this->timeOfEntrance = t;
};


Time Customer::getTimeOfLeave() const{
    return timeOfLeave;
};

void Customer::setTimeOfLeave(Time t){
    this->timeOfLeave = t;
};

bool Customer::operator==(const Customer &customer) const
{
    return this->getName() == customer.getName() && this->getSurname() == customer.getSurname();
}