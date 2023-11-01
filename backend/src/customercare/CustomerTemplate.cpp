#include "CustomerTemplate.h"
#include "SatisfactionState.h"
#include "Happy.h"
#include "../reservation/Reservation.h"
#include "../ordering/Waiter.h"
#include "../sudo_management/Management.h"

CustomerTemplate::CustomerTemplate(std::string name,std::shared_ptr<Management>) : name(name){
    this->Mood = std::make_shared<Happy>();
    this->readyToOrder = false;
    this->totalBill = 0;
    this->management = management;
}

CustomerTemplate::~CustomerTemplate(){
    
}

std::shared_ptr<SatisfactionState> CustomerTemplate::getMood(){
    return this->Mood;
}

double CustomerTemplate::calculateFinalBill(double bill){
    return this->Mood->calculateBill(bill);
}

void CustomerTemplate::setMood(std::shared_ptr<SatisfactionState> Mood){
    this->Mood = Mood;
}

std::unordered_map<std::string,int> CustomerTemplate::getOrder(){
    return this->order;
}

void CustomerTemplate::setOrder(std::unordered_map<std::string,int> order){
    this->order = order;
}

double CustomerTemplate::getTotalBill(){
    return this->totalBill;
}

void CustomerTemplate::setReadyToOrder(bool readyToOrder){
    this->readyToOrder = readyToOrder;
}

void CustomerTemplate::console(){
    this->Mood->console();
}

void CustomerTemplate::anger(){
    this->Mood->anger();
}

void CustomerTemplate::notifyManagement(){
    this->management->notifyPlayerOfChangeInMood();
}

void CustomerTemplate::leave(){
    this->management->clearOutTable(this->reservation->getTable());
}

