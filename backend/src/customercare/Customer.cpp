#include "Customer.h"
#include "Happy.h"

Customer::Customer(std::shared_ptr<PlayerInteraction> management) : CustomerTemplate( "Main Character", management) {
    this->hasGuests = false;
    this->isMain = true;
}

Customer::~Customer() {}
