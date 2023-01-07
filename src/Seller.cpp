#include "Seller.h"

void Seller::addCustomerToQueue(Customer client){
    q.push(client);
};

void Seller::removeCustomerFromQueue(){
    q.pop();
};

double Seller::BillForFirstCustomerInQueue(){
    Customer clientToServe = q.front();
    clientToServe.calculateBill();
    removeCustomerFromQueue();

    return clientToServe.getActualBill();
};


//zapytaj sprzedawce o książke
void Seller::checkAvailabilityByTitle (std::string title){

    for(auto i: books.getBooks()){
        if(i->get_title() == title){
            std::cout << "Tak, jest książka o podanym tytule\n";
            return;
        }
    }
    std:: cout << "Nie ma książki o podanym tytule\n";
};


void Seller::showBooksByAuthor (std::string name, std::string surname){

    std::cout << "Książki napisane przez autora: " << name << " " << surname << " to: \n";
    for(auto i: books.getBooks()){
        if(i->get_author().get_name() == name && i->get_author().get_surname() == surname){
            std::cout << i->get_title() <<"\n";
        }
    }
    std::cout << "\n";
};

void Seller::showBooksByCategory (std::string category){
    // std::vector<std::shared_ptr<Book>> booksCopy = books.getBooks();

    std::cout << "Książki z kategorii " << category << " to: \n";
    for(auto i: books.getBooks()){
        // std::cout << i->getCategory() <<"\n";
        if(i->getCategory() == category){
            std::cout << i->get_title() <<"\n";
        }
    }
    std::cout << "\n";
};