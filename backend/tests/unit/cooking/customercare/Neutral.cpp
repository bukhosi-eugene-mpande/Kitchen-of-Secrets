#include "Neutral.h"
#include "Customer.h"
#include "Neutral.h"
#include "Happy.h"
#include "Unhappy.h"

Neutral::Neutral() : SatisfactionState("Neutral",0.1) { }

Neutral::~Neutral() { }

double Neutral::getTipPercentage() {
    return SatisfactionState::getTipPercentage();
}

void Neutral::appease(Customer* customer) { 
    customer->changeMood(std::make_shared<Happy>());
}

void Neutral::upset(Customer* customer) {
    customer->changeMood(std::make_shared<Unhappy>());
}