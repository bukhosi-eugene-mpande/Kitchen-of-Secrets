#include "Customer.h"

Customer::Customer(Engine* engine) : GameComponent(engine) {}

Customer::~Customer() {}

SatisfactionState* Customer::getMood() {
    return mood;
}

void Customer::setMood(SatisfactionState* mood) {
    this->mood = mood;
}

std::string Customer::getComplaint() {
    return complaint;
}

void Customer::setComplaint(std::string complaint) {
    this->complaint = complaint; 
}

bool Customer::getCheckIn() {
    return checkIn;
}

void Customer::setCheckIn(bool checkIn) {
    this->checkIn = checkIn;
}

bool Customer::getCheckOut() {
    return checkOut;
}

void Customer::setCheckOut(bool checkOut) {
    this->checkOut = checkOut;
}

void Customer::helpMe() {

}

void Customer::directMe() {
}

void Customer::sendNotification()
{
}

void Customer::receiveNotification(std::string message)
{
}
