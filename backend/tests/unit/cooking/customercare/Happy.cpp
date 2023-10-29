#include "Happy.h"
#include "Customer.h"
#include "Neutral.h"

Happy::Happy() : SatisfactionState("Happy",0.2) { }

Happy::~Happy() { }

double Happy::getTipPercentage() {
    return SatisfactionState::getTipPercentage();
}

void Happy::appease(Customer* customer) { }

void Happy::upset(Customer* customer) {
    customer->changeMood(std::make_shared<Neutral>());
}