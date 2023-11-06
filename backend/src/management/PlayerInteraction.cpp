#include "PlayerInteraction.h"
#include "../cooking/Kitchen.h"
#include "../reservation/ReservationSystem.h"
#include "../reservation/Receptionist.h"
#include "../customercare/Customer.h"
#include "../management/Engine.h"
#include "../ordering/MenuItem.h"
#include "../ordering/Waiter.h"
#include "../accounting/Inventory.h" 
#include "../accounting/Accounting.h"

PlayerInteraction::PlayerInteraction() {
    reservationSystem = std::make_shared<ReservationSystem>();

    receptionist = std::make_shared<Receptionist>(reservationSystem);

    inventory = std::make_shared<Inventory>();

    accounting = std::make_shared<Accounting>();

}

PlayerInteraction::~PlayerInteraction() {

}

//customer interaction with reservation system
void PlayerInteraction::clearOutTable(std::shared_ptr<Table> table) {
    this->reservationSystem->clearOutTable(table);
}

void PlayerInteraction::notifyPlayerOfChangeInMood() {
    // TODO - implement a function in the ui that will display a message to the player
}

void PlayerInteraction::requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section) {
    this->receptionist->requestReservation(customer,section);
}

void PlayerInteraction::requestToBeSeated(std::shared_ptr<CustomerTemplate> customer) {
    this->receptionist->requestToBeSeated(customer);
}

void PlayerInteraction::notifyWaiterOfCancellation(Waiter* waiter) {
    waiter->getCanceledOrderFromKitchen();
}

void PlayerInteraction::notifyWaiterOfCompletion(Waiter* waiter) {
    waiter->getOrderFromKitchen();
}

std::shared_ptr<Section> PlayerInteraction::getGeneralSection() {
    return this->reservationSystem->getGeneralSection();
}

std::shared_ptr<Section> PlayerInteraction::getPrivateSection() {
    return this->reservationSystem->getPrivateSection();
}

bool PlayerInteraction::requestIngredients(std::unordered_map<std::string,int> ingredients) {
    return this->inventory->requestIngredients(ingredients);
}

void PlayerInteraction::sendOrderToKitchen(std::shared_ptr<Order> order) {
    this->kitchen->addOrder(order);
}

std::shared_ptr<Order> PlayerInteraction::getOrderFromKitchen(Waiter* waiter) {
    return this->kitchen->getPreparedOrder(waiter);
}

std::shared_ptr<Order> PlayerInteraction::getCanceledOrderFromKitchen(Waiter* waiter) {
    return this->kitchen->getCanceledOrder(waiter);
}

void PlayerInteraction::setKitchen(std::shared_ptr<Kitchen> kitchen) {
    this->kitchen = kitchen;
}

void PlayerInteraction::setInventory(std::shared_ptr<Inventory> inventory){
    this->inventory = inventory;
}

std::vector<std::shared_ptr<CustomerTemplate>> PlayerInteraction::getCustomers() {
    return this->reservationSystem->getCustomers();
}

std::shared_ptr<Drink> PlayerInteraction::getDrink(std::string name) {
    return this->kitchen->getDrink(name);
}

std::shared_ptr<Cuisine> PlayerInteraction::getCusine(std::string name) {
    return this->kitchen->getCusine(name);
}

std::unordered_map<int,std::string> PlayerInteraction::getDrinksMenu(){
    return this->kitchen->getDrinksMenu();
}

std::unordered_map<int,std::string> PlayerInteraction::getCuisineMenu(){
    return this->kitchen->getCuisineMenu();
}

std::string PlayerInteraction::pay(std::string payment,double bill) {
    return this->accounting->pay(bill,payment);
}
