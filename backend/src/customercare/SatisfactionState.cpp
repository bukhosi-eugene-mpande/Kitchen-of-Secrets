#include "SatisfactionState.h"

SatisfactionState::SatisfactionState(std::string stateName,CustomerTemplate* customer, double discount, double tip){
    this->stateName = stateName;
    this->customer = customer;
    this->discount = discount;
    this->tip = tip;
}

double SatisfactionState::calculateBill(double bill){
    bill = bill - (bill * discount) + (bill * tip);
    return bill;
}

std::string SatisfactionState::getStateName(){
    return stateName;
}

void SatisfactionState::setCustomer(CustomerTemplate* customer){
    this->customer = customer;
}

CustomerTemplate* SatisfactionState::getCustomer(){
    return this->customer;
}
