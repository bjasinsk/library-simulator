#include "Seller.h"

void Seller::addCustomerToQueue(Customer client){
    q.push(client);
};

void Seller::removeCustomerFromQueue(){
    q.pop();
};

double Seller::BillForFirstCustomerInQueue(){
    Customer clientToServe = q.front();
    removeCustomerFromQueue();
    clientToServe.calculateBill();
    return clientToServe.getActualBill();
};
