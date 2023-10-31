#include "Customer.h"
#include "Happy.h"

Customer::Customer(){
    this->Mood = std::make_shared<Happy>();
    this->isMainGuest = false;
    this->totalBill = 0;
}

Customer::~Customer(){
}

std::shared_ptr<SatisfactionState> Customer::getMood(){
    return this->Mood;
}

void Customer::setMood(std::shared_ptr<SatisfactionState> Mood){
    this->Mood = Mood;
}

double Customer::getBill(double Bill){
    return this->Mood->calculateBill(Bill);
}

void Customer::setIsMainGuest(bool isMainGuest){
    this->isMainGuest = isMainGuest;
}

bool Customer::getIsMainGuest(){
    return this->isMainGuest;
}

void Customer::addGuest(Customer guest){
    this->guests.push_back(guest);
}

std::vector<Customer> Customer::getGuests(){
    return this->guests;
}



