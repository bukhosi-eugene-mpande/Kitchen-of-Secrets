#include "Customer.h"

Customer::Customer(const std::string& name, const std::string& paymentOfChoice) : name(name), paymentOfChoice(paymentOfChoice) {}

void Customer::accept(Visitor* visitor) {
    visitor->visit(this);
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getPaymentOfChoice() const{
    return paymentOfChoice;
}
void Customer::eatFood()
{
    std::cout<<"Cusomer recives food and eats!"<<std::endl;
    std::cout<<std::endl;
}