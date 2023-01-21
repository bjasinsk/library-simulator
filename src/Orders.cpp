#include "Orders.h"

// void Order:: makeAnOrder(const Book& book, int quantity, const Customer& whoOrdered){

//     double priceOfOrder = book.get_price() * quantity;

//     if (bookStore.getBudget() > priceOfOrder){

//         time_t time_since_begin = time(0);
//         tm *actual_time = localtime(&time_since_begin);

//         Date dateOfOrder = Date(actual_time->tm_mday,actual_time->tm_mon, actual_time->tm_year);

//         int idOfNewOrder = idOfLastOrder + 1;
//         idOfLastOrder = idOfNewOrder;

//         std::shared_ptr<order> newOrder = std::make_shared<order>(idOfNewOrder, dateOfOrder, book, quantity, whoOrdered);
//         doneOrders.push_back(newOrder);

//         float newBudget = bookStore.getBudget() - priceOfOrder;
//         bookStore.setBudget(newBudget);

//     }else{
//         std::cout << "Zamówienie nie może zostatać złożone, księgarnia nie jest w stanie zamówić tych książek\n";
//     }
// };


// void Order:: removeAnOrder(int idOfOrderToRemove){
//     for(std::vector<std::shared_ptr<order>>::iterator it = doneOrders.begin(); it != doneOrders.end(); ++it)
//         {
//             // (*it)->orderId
//             // (*(*it)).orderId
//             if((*it)->orderId == idOfOrderToRemove){

//                 int quantityOfRemovedOrder = (*it)->quantity;
//                 int priceOfRemovedBook = (*it)->book.get_price();
//                 float removedOrderPrice = priceOfRemovedBook*quantityOfRemovedOrder;
                
//                 float actualBookStoreBudget = bookStore.getBudget();
//                 float newBookStoreBudget = actualBookStoreBudget + removedOrderPrice;

//                 bookStore.setBudget(newBookStoreBudget);
//                 doneOrders.erase(it);
//                 break;
//             }
//         }
//     std::cout << "Zamówienie zostało anulowane\n";
// };

// void Order:: modifyAnOrder(int idOfOrderToRemove, int newQuantity){
//     for(std::vector<std::shared_ptr<order>>::iterator it = doneOrders.begin(); it != doneOrders.end(); ++it)
//         {
//             if((*it)->orderId == idOfOrderToRemove){
//                 int quantityOfModifiedOrder = (*it)->quantity;
//                 int differenceBeetwenQuantities = quantityOfModifiedOrder - newQuantity;
//                 double priceOfBook = (*it)->book.get_price();
//                 float costToAdd = std::abs(differenceBeetwenQuantities) * priceOfBook;

//                 if (differenceBeetwenQuantities < 0){
//                     if (bookStore.getBudget() > costToAdd){
//                         float newBudget = bookStore.getBudget() - costToAdd;
//                         bookStore.setBudget(newBudget);
//                         (*it)->quantity = newQuantity;
//                     }else{
//                         std::cout << "Nie można zamówić takiej ilości książek, zamówienie nie zostało zmodyfikowane\n";
//                     }
//                 }else{
//                     float newBudget = bookStore.getBudget() + costToAdd;
//                     bookStore.setBudget(newBudget);
//                     (*it)->quantity = newQuantity;
//                 };
//                 break;
//             }
//         }
// };




int Order::getOrderId() const{
    return orderId;
};

Date Order::getDateOfOrder() const{
    return dateOfOrder;
};

Book Order::getOrderedBook() const{
    return book;
};

int Order::getQuantity() const{
    return quantity;
};

Customer Order::getCustomer() const{
    return whoOrdered;
};



void Order::setQuantity(int quantity_){
    this->quantity = quantity_;
};
