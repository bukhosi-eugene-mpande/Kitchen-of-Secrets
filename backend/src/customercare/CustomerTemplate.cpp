#include "CustomerTemplate.h"
#include "SatisfactionState.h"
#include "Happy.h"
#include "../reservation/Reservation.h"
#include "../ordering/Waiter.h"
#include "../sudo_management/Management.h"

CustomerTemplate::CustomerTemplate(std::string name,std::shared_ptr<Management> management) : name(name){
    this->Mood = std::make_shared<Happy>(this);
    this->readyToOrder = false;
    this->totalBill = 0;
    this->management = management;
    this->reservation = nullptr;
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
    this->guests.clear();
    this->management->clearOutTable(this->reservation->getTable());
}

std::string CustomerTemplate::getName(){
    return this->name;
}

bool CustomerTemplate::IsReadyToOrder(){
    return this->readyToOrder;
}

std::shared_ptr<Reservation> CustomerTemplate::getReservation(){
    return this->reservation;
}

void CustomerTemplate::setReservation(std::shared_ptr<Reservation> reservation){
    this->reservation = reservation;
}

std::shared_ptr<Management> CustomerTemplate::getManagement(){
    return this->management;
}

void CustomerTemplate::setManagement(std::shared_ptr<Management> management){
    this->management = management;
}

std::shared_ptr<CustomerTemplate> CustomerTemplate::this_to_shared(){
    return std::shared_ptr<CustomerTemplate>(this);
}

void CustomerTemplate::requestReservation(){
    this->management->requestReservation(this->this_to_shared(),this->DesiredSection);
}

void CustomerTemplate::addGuest(std::shared_ptr<CustomerTemplate> guest){
    this->guests.push_back(guest);
}

std::vector<std::shared_ptr<CustomerTemplate>> CustomerTemplate::getGuests(){
    return this->guests;
}

bool CustomerTemplate::getHasGuests(){
    return this->hasGuests;
}

void CustomerTemplate::setHasGuests(bool hasGuests){
    this->hasGuests = hasGuests;
}

bool CustomerTemplate::getIsMain(){
    return this->isMain;
}

void CustomerTemplate::setIsMain(bool isMain){
    this->isMain = isMain;
}

int CustomerTemplate::getNumGuests(){
    return this->numGuests;
}

void CustomerTemplate::setNumGuests(int numGuests){
    this->numGuests = numGuests;
}

std::string CustomerTemplate::getDesiredSection(){
    return this->DesiredSection;
}

void CustomerTemplate::setDesiredSection(std::string DesiredSection){
    this->DesiredSection = DesiredSection;
}

void CustomerTemplate::requestToBeSeated(){
    this->management->requestToBeSeated(this->this_to_shared());
}
