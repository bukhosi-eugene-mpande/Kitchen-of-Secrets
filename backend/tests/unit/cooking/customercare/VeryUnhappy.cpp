#include "VeryUnhappy.h"
#include "Customer.h"
#include "Neutral.h"
#include "Unhappy.h"

VeryUnhappy::VeryUnhappy() : SatisfactionState("Very Unhappy",0.00) { }

VeryUnhappy::~VeryUnhappy() { }

double VeryUnhappy::getTipPercentage() {
    return SatisfactionState::getTipPercentage();
}

void VeryUnhappy::appease(Customer* customer) { 
    customer->changeMood(std::make_shared<Unhappy>());
}

void VeryUnhappy::upset(Customer* customer) { }