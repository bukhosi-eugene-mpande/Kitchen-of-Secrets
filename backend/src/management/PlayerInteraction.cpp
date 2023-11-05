#include "PlayerInteraction.h"

PlayerInteraction::PlayerInteraction(std::shared_ptr<Kitchen> kitchen, std::shared_ptr<Inventory> inventory, std::shared_ptr<ReservationSystem> reservationSystem, std::shared_ptr<Receptionist> receptionist, std::shared_ptr<Waiter> waiter, std::shared_ptr<Customer> customer, std::shared_ptr<Engine> engine) {
    kitchen = std::make_shared<Kitchen>(this);
    inventory = std::make_shared<Inventory>(this);
    reservationSystem = std::make_shared<ReservationSystem>(this);
    receptionist = std::make_shared<Receptionist>(this);
    engine = std::make_shared<Engine>();
    waiter = std::make_shared<Waiter>(engine);
    customer = std::make_shared<Customer>(engine, this);
}

PlayerInteraction::~PlayerInteraction() {}

void PlayerInteraction::sendOrderToKitchen() {
    int size = 10;
    std::vector<std::shared_ptr<MenuItem>> meals;
    for (int i = 0; i < size; i++) {
        std::unordered_map<std::string, int> ingredients;
        for (int j = 0; j < size; j++) {
            ingredients.at("");
        }
        meals[i] = std::make_shared<MenuItem>(engine, 0.00, "name", ingredients);
    }
    std::shared_ptr<Order> order = std::make_shared<Order>(engine, 1, meals, waiter);
    this->kitchen->addOrder(order);
}

std::shared_ptr<Order> PlayerInteraction::getOrderFromKitchen() {
    return this->kitchen->getPreparedOrder(waiter);
}

std::shared_ptr<Order> PlayerInteraction::getCanceledOrderFromKitchen() {
    return this->kitchen->getCanceledOrder(waiter);
}

bool PlayerInteraction::requestIngredients(std::unordered_map<std::string,int> ingredients) {
    return this->inventory->requestIngredients(ingredients);
}

void PlayerInteraction::notifyWaiterOfCancellation() {
    waiter->getCanceledOrderFromKitchen();
}

void PlayerInteraction::notifyWaiterOfCompletion() {
    waiter->getOrderFromKitchen();
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