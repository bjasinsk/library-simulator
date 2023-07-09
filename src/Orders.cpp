#include "Orders.h"

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
