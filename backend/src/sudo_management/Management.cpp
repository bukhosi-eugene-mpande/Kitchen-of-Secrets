#include "Management.h"

#include "../ordering/Waiter.h"
#include "../cooking/Kitchen.h"
#include "../sudo_accounting/Inventory.h"
#include "../reservation/ReservationSystem.h"
#include "../reservation/Table.h"
#include "../reservation/Receptionist.h"

Management::Management() {
    this->inventory = std::make_shared<Inventory>(std::unordered_map<std::string,int>({{"tomato", 10}, {"lettuce", 10}, {"cheese", 10}, {"patty", 10}}));
    this->reservationSystem = std::make_shared<ReservationSystem>();
    this->receptionist = std::make_shared<Receptionist>(this->reservationSystem);

}

Management::~Management() {
}

void Management::sendOrderToKitchen(std::shared_ptr<Order> order) {
    this->kitchen->addOrder(order);
}

std::shared_ptr<Order> Management::getOrderFromKitchen(std::shared_ptr<Waiter> waiter) {
    return this->kitchen->getPreparedOrder(waiter);
}

std::shared_ptr<Order> Management::getCanceledOrderFromKitchen(std::shared_ptr<Waiter> waiter) {
    return this->kitchen->getCanceledOrder(waiter);
}

bool Management::requestIngredients(std::unordered_map<std::string,int> ingredients) {
    return this->inventory->requestIngredients(ingredients);
}

void Management::notifyWaiterOfCancellation(std::shared_ptr<Waiter> waiter) {
    waiter->getCanceledOrderFromKitchen();
}

void Management::notifyWaiterOfCompletion(std::shared_ptr<Waiter> waiter) {
    waiter->getOrderFromKitchen();
}

void Management::setKitchen(std::shared_ptr<Kitchen> kitchen) {
    this->kitchen = kitchen;
}

void Management::setInventory(std::shared_ptr<Inventory> inventory){
    this->inventory = inventory;
}

void Management::notifyPlayerOfChangeInMood() {
    // TODO - implement a function in the ui that will display a message to the player
}

void Management::clearOutTable(std::shared_ptr<Table> table) {
    this->reservationSystem->clearOutTable(table);
}

void Management::requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section) {
    this->receptionist->requestReservation(customer,section);
}

void Management::requestToBeSeated(std::shared_ptr<CustomerTemplate> customer) {
    this->receptionist->requestToBeSeated(customer);
}