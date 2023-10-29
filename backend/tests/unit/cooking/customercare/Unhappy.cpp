#include "Unhappy.h"
#include "Customer.h"
#include "Neutral.h"
#include "VeryUnhappy.h"

Unhappy::Unhappy() : SatisfactionState("Unhappy",0.05) { }

Unhappy::~Unhappy() { }

double Unhappy::getTipPercentage() {
    return SatisfactionState::getTipPercentage();
}

void Unhappy::appease(Customer* customer) { 
    customer->changeMood(std::make_shared<Neutral>());
}

void Unhappy::upset(Customer* customer) {
    customer->changeMood(std::make_shared<VeryUnhappy>());
}