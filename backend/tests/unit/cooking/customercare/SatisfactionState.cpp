#include "SatisfactionState.h"

SatisfactionState::SatisfactionState(std::string name,double tipPercentage) {
    this->tipPercentage = tipPercentage;
    this->name = name;
}

SatisfactionState::~SatisfactionState() { }

double SatisfactionState::getTipPercentage() {
    return this->tipPercentage;
}
