#include "BookStore.h"

void BookStore::addSeller(Seller &seller){
    if(counterOfSellers == maxNumberOfSellers){
        std::cout << "Jest już maksymalna liczba sprzedawców na zmianie\n";
        return;
    }else{
        std::shared_ptr<Seller> new_seller (new Seller(seller));
        sellers.push_back(new_seller);
        counterOfSellers++;
    }
    
};


void BookStore::removeSeller(Seller &seller){
    for(std::vector<std::shared_ptr<Seller>>::iterator it = sellers.begin(); it != sellers.end(); ++it)
        {
            if(**it == seller)
                sellers.erase(it);
                break;
        }
};


void BookStore::customerEntersStore(Customer &customer){
    std::shared_ptr<Customer> new_customer (new Customer(customer));
    customers.push_back(new_customer);
    

    time_t time_since_begin = time(0);
    tm *actual_time = localtime(&time_since_begin);

    customer.setTimeOfEntrance(Time(actual_time->tm_hour,actual_time->tm_min, actual_time->tm_sec));
    
    std:: cout << "Klient wszedł ze skepu\n";
    std:: cout << "Czas wejścia: " << customer.getTimeOfEntrance().getHour() << ":" << customer.getTimeOfEntrance().getMinute() << ":" << customer.getTimeOfEntrance().getSeconds() <<"\n";
};


void BookStore::customerLeavesStore(Customer &customer){

    time_t time_since_begin = time(0);
    tm *actual_time = localtime(&time_since_begin);


    customer.setTimeOfLeave(Time(actual_time->tm_hour,actual_time->tm_min, actual_time->tm_sec));

    // int secInShop = actual_time->tm_sec - customer.getTime().getSeconds();
    // int minInShop = actual_time->tm_min - customer.getTime().getMinute();
    // int hourInShop = actual_time->tm_hour - customer.getTime().getHour();

    for(std::vector<std::shared_ptr<Customer>>::iterator it = customers.begin(); it != customers.end(); ++it)
        {
            if(**it == customer)
                customers.erase(it);
                break;
        }

    std:: cout << "Klient wyszedł ze skepu\n";
    std:: cout << "Czas wyjścia: " << customer.getTimeOfLeave().getHour() << ":" << customer.getTimeOfLeave().getMinute() << ":" << customer.getTimeOfLeave().getSeconds() <<"\n";
    // std:: cout << "Klient przebywał w sklepie: " << hourInShop << "h" << minInShop << "min" << secInShop << "sec\n";
};
