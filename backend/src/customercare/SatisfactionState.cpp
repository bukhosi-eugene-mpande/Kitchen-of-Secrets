#include "SatisfactionState.h"

SatisfactionState::SatisfactionState(std::string stateName, std::shared_ptr<Customer> customer, double discount, double tip){
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
