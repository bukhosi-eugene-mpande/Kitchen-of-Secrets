#include "OrderProcess.h"
#include <iostream>

void OrderProcess::visit(Waiter* waiter) {
    // Implementation for when the visitor visits a Waiter
    std::cout << "Processing order with waiter.\n"<<waiter<<std::endl;
}

void OrderProcess::visit(Customer* customer) {
    // Implementation for when the visitor visits a Customer
    std::cout << "Processing payment type: " << customer->getPaymentOfChoice() << "\n";
}
