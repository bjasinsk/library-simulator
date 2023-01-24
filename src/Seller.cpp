#include "Seller.h"

void Seller::addCustomerToQueue(std::shared_ptr<Customer> new_customer){
    q.push(new_customer);
};

void Seller::removeCustomerFromQueue(){
    q.pop();
};

void Seller::serveFirstCustomerInQueue(){
    if(q.size() == 0)
    {
        std::cout << "Brak klientow w kolejce" << std::endl;
        return;
    }
    auto clientToServe = q.front();
    auto books = clientToServe->getShoppingCart();
    for (auto book : books)
        this->books.removeBooks(*book, 1);
    clientToServe->calculateBill();
    *budgetOfStore += clientToServe->getActualBill();
    clientToServe->buyShoppingCart();
    removeCustomerFromQueue();
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
        if(i->get_author().getName() == name && i->get_author().getSurname() == surname){
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


bool Seller::operator==(const Seller &seller) const
{
    return this->getName() == seller.getName() && this->getSurname() == seller.getSurname();
}

void Seller::printQueueOfCustomers()
{
    auto queueOfCustomers = getQueueOfCustomers();
    int counter = 1;
    while (!queueOfCustomers.empty()){
        std::cout << "-----" << counter << ". " << queueOfCustomers.front()->getName() << " " << queueOfCustomers.front()->getSurname() << "\n";
        counter++;
        queueOfCustomers.pop();
    }
}

std::queue<std::shared_ptr<Customer>> Seller::getQueueOfCustomers() const{
    return q;

};
