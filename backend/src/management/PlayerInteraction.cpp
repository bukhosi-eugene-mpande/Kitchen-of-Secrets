#include "PlayerInteraction.h"

PlayerInteraction::PlayerInteraction(std::shared_ptr<Kitchen> kitchen, std::shared_ptr<Inventory> inventory, std::shared_ptr<ReservationSystem> reservationSystem, std::shared_ptr<Receptionist> receptionist, std::shared_ptr<Waiter> waiter)
{
    this->kitchen = kitchen;
    this->inventory = inventory;
    this->reservationSystem = reservationSystem;
    this->receptionist = receptionist;
    this->waiter = waiter;
}

PlayerInteraction::~PlayerInteraction() {}

void PlayerInteraction::sendOrderToKitchen(std::shared_ptr<Order> order) {
    this->kitchen->addOrder(order);
}

std::shared_ptr<Order> PlayerInteraction::getOrderFromKitchen(std::shared_ptr<Waiter> waiter) {
    return this->kitchen->getPreparedOrder(waiter);
}

std::shared_ptr<Order> PlayerInteraction::getCanceledOrderFromKitchen(std::shared_ptr<Waiter> waiter) {
    return this->kitchen->getCanceledOrder(waiter);
}

bool PlayerInteraction::requestIngredients(std::unordered_map<std::string,int> ingredients) {
    return this->inventory->requestIngredients(ingredients);
}

void PlayerInteraction::notifyWaiterOfCancellation(std::shared_ptr<Waiter> waiter) {
    waiter->getCanceledOrderFromKitchen();
}

void PlayerInteraction::notifyWaiterOfCompletion(std::shared_ptr<Waiter> waiter) {
    waiter->getOrderFromKitchen();
}

void PlayerInteraction::setKitchen(std::shared_ptr<Kitchen> kitchen) {
    this->kitchen = kitchen;
}

void PlayerInteraction::setInventory(std::shared_ptr<Inventory> inventory){
    this->inventory = inventory;
}

void PlayerInteraction::notifyPlayerOfChangeInMood() {
    // TODO - implement a function in the ui that will display a message to the player
}

void PlayerInteraction::clearOutTable(std::shared_ptr<Table> table) {
    this->reservationSystem->clearOutTable(table);
}

void PlayerInteraction::requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section) {
    this->receptionist->requestReservation(customer,section);
}

void PlayerInteraction::requestToBeSeated(std::shared_ptr<CustomerTemplate> customer) {
    this->receptionist->requestToBeSeated(customer);
}

std::shared_ptr<Section> PlayerInteraction::getGeneralSection() {
    return this->reservationSystem->getGeneralSection();
}

std::shared_ptr<Section> PlayerInteraction::getPrivateSection() {
    return this->reservationSystem->getPrivateSection();
}

std::vector<std::shared_ptr<CustomerTemplate>> PlayerInteraction::getCustomers() {
    return this->reservationSystem->getCustomers();
}


