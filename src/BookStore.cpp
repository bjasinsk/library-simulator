#include "BookStore.h"
#include "ExceptionsLibrary.h"

void BookStore::addSeller(Seller &seller)
{
    if (counterOfSellers == maxNumberOfSellers)
    {
        std::cout << "Jest już maksymalna liczba sprzedawców na zmianie\n";
        return;
    }
    else
    {
        std::shared_ptr<Seller> new_seller(new Seller(seller));
        sellers.push_back(new_seller);
        counterOfSellers++;
    }
};

void BookStore::removeSeller(Seller &seller)
{
    for (std::vector<std::shared_ptr<Seller>>::iterator it = sellers.begin(); it != sellers.end(); ++it)
    {
        if (**it == seller)
        {
            sellers.erase(it);
            break;
        }
    }
    counterOfSellers -= 1;
};

void BookStore::customerEntersStore(Customer &customer)
{
    std::shared_ptr<Customer> new_customer(new Customer(customer));
    customers.push_back(new_customer);

    time_t time_since_begin = time(0);
    tm *actual_time = localtime(&time_since_begin);

    customer.setTimeOfEntrance(Time(actual_time->tm_hour, actual_time->tm_min, actual_time->tm_sec));

    std::cout << "Klient wszedł ze skepu\n";
    std::cout << "Czas wejścia: " << customer.getTimeOfEntrance().getHour() << ":" << customer.getTimeOfEntrance().getMinute() << ":" << customer.getTimeOfEntrance().getSeconds() << "\n";
};

void BookStore::customerLeavesStore(Customer &customer)
{

    time_t time_since_begin = time(0);
    tm *actual_time = localtime(&time_since_begin);

    customer.setTimeOfLeave(Time(actual_time->tm_hour, actual_time->tm_min, actual_time->tm_sec));

    Time timeInStore = customer.getTimeOfLeave().TimeBetweenOtherTime(customer.getTimeOfEntrance());

    for (std::vector<std::shared_ptr<Customer>>::iterator it = customers.begin(); it != customers.end(); ++it)
    {
        if (**it == customer)
        {
            customers.erase(it);
            break;
        }
    }

    std::cout << "Klient wyszedł ze skepu\n";
    std::cout << "Czas wyjścia: " << customer.getTimeOfLeave().getHour() << ":" << customer.getTimeOfLeave().getMinute() << ":" << customer.getTimeOfLeave().getSeconds() << "\n";
    std::cout << "Klient przebywał w sklepie: " << timeInStore.getHour() << "h" << timeInStore.getMinute() << "min" << timeInStore.getSeconds() << "sec\n";
};

Bookshelf &BookStore::getBooshelfInstance()
{
    return bookshelf;
}

int BookStore::printSellers()
{
    int i = 1;
    for (auto seller : sellers)
    {
        std::cout << i++ << ". " << *seller;
    }
    return --i;
}

std::shared_ptr<Seller> BookStore::getSellerByNum(int num)
{
    if ((int)sellers.size() < num)
        throw ExceptionLibraryNoValue("Brak sprzedawcy o takim numerze");
    return sellers.at(num - 1);
}

float BookStore::getBudget() const
{
    return budget;
};

void BookStore::setBudget(float budget)
{
    this->budget = budget;
};

void BookStore::makeAnOrder(const Book &book, int quantity, const Customer &whoOrdered)
{
    double priceOfOrder = book.get_price() * quantity;
    if (budget > priceOfOrder)
    {
        time_t time_since_begin = time(0);
        tm *actual_time = localtime(&time_since_begin);
        Date dateOfOrder = Date(actual_time->tm_mday, actual_time->tm_mon + 1, actual_time->tm_year + 1900);
        idOfLastOrder++;
        std::shared_ptr<Order> newOrder = std::make_shared<Order>(idOfLastOrder, dateOfOrder, book, quantity, whoOrdered);
        doneOrders.push_back(newOrder);
        budget -= priceOfOrder;
        std::cout << "Złożono podane zamówienie\n";
    }
    else
    {
        std::cout << "Zamówienie nie może zostatać złożone, księgarnia nie jest w stanie zamówić tych książek\n";
    }
};

void BookStore::removeAnOrder(int idOfOrderToRemove)
{
    for (std::vector<std::shared_ptr<Order>>::iterator it = doneOrders.begin(); it != doneOrders.end(); ++it)
    {
        if ((*it)->getOrderId() == idOfOrderToRemove)
        {
            int quantityOfRemovedOrder = (*it)->getQuantity();
            float priceOfRemovedBook = (*it)->getOrderedBook().get_price();
            float removedOrderPrice = priceOfRemovedBook * quantityOfRemovedOrder;
            float newBookStoreBudget = budget + removedOrderPrice;
            budget = newBookStoreBudget;
            doneOrders.erase(it);
            break;
        }
    }
    std::cout << "Zamówienie o numerze: " << idOfOrderToRemove << " zostało anulowane\n";
};

void BookStore::modifyAnOrder(int idOfOrderToRemove, int newQuantity)
{
    if (newQuantity == 0)
    {
        removeAnOrder(idOfOrderToRemove);
    }
    for (std::vector<std::shared_ptr<Order>>::iterator it = doneOrders.begin(); it != doneOrders.end(); ++it)
    {
        if ((*it)->getOrderId() == idOfOrderToRemove)
        {
            int quantityOfModifiedOrder = (*it)->getQuantity();
            int differenceBeetwenQuantities = quantityOfModifiedOrder - newQuantity;
            double priceOfBook = (*it)->getOrderedBook().get_price();
            float costToAdd = std::abs(differenceBeetwenQuantities) * priceOfBook;
            if (differenceBeetwenQuantities < 0)
            {
                if (budget > costToAdd)
                {
                    float newBudget = budget - costToAdd;
                    budget = newBudget;
                    (*it)->setQuantity(newQuantity);
                }
                else
                {
                    std::cout << "Nie można zamówić takiej ilości książek, zamówienie nie zostało zmodyfikowane\n";
                }
            }
            else
            {
                float newBudget = budget + costToAdd;
                budget = newBudget;
                (*it)->setQuantity(newQuantity);
            };
            break;
        }
    }
};

void BookStore::printCurrentOrders()
{
    int counter = 1;

    if (doneOrders.empty())
    {
        std::cout << "Aktualnie nie ma żadnych zamówień\n";
        return;
    }
    std::cout << "Aktualna lista zamówień:" << std::endl;
    for (std::vector<std::shared_ptr<Order>>::iterator it = doneOrders.begin(); it != doneOrders.end(); ++it)
    {
        std::cout << "id_zamówienia: " << (*it)->getOrderId() << "| data_zamówienia: " << (*it)->getDateOfOrder() << "|\n";
        std::cout << "książka: " << (*it)->getOrderedBook().get_title() << "| ilość_sztuk: " << (*it)->getQuantity() << "|\n";
        std::cout << "zamówił: " << (*it)->getCustomer().getName() << " " << (*it)->getCustomer().getSurname() << "|\n";
        std::cout << "\n";
        counter++;
    }
};
