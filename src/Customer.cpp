#include "Customer.h"
#include <iostream>
#include <map>
#include "Book.h"

std::map<std::string, double> Customer::getShoppingCart() const{
    return shoppingCart;
};


void Customer::printActualShoppingCart(){
    std::cout << "Aktualny koszyk Klienta: \n";

    for(std::map<std::string, double>::iterator itr = shoppingCart.begin(); itr != shoppingCart.end(); itr++){
        std::cout << "Książka: " << itr->first << " cena: " << itr->second << "\n";
    }
};


void Customer::addToShoppingCart(Book& b){
    shoppingCart.insert(std::make_pair(b.get_title(), b.get_price()));
};


void Customer::removeFromShoppingCart(Book& b){
    shoppingCart.erase(b.get_title());
}


double Customer::getActualBill() const {
    return bill;
};


void Customer::calculateBill(){
    bill = 0;
     for(std::map<std::string, double>::iterator itr = shoppingCart.begin(); itr != shoppingCart.end(); itr++){
        bill += itr->second;
     }
};

