#include "backend/src/sudo_management/Management.h"

Management:Management() {
    kitchen = std::make_shared<Kitchen>(this);
    inventory = std::make_shared<Inventory>(this);
    reservationSystem = std::make_shared<ReservationSystem>(this);
    receptionist = std::make_shared<Receptionist>(this);
    engine = std::make_shared<Engine>();
    waiter = std::make_shared<Waiter>(engine);
    customer = std::make_shared<Customer>(engine, this);
}

Management::~Management() {}

json Management::sendOrderToKitchen(json order) {
    int size = order["size"];
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

std::shared_ptr<Order> Management::getOrderFromKitchen() {
    return this->kitchen->getPreparedOrder(waiter);
}

std::shared_ptr<Order> Management::getCanceledOrderFromKitchen() {
    return this->kitchen->getCanceledOrder(waiter);
}

bool Management::requestIngredients(std::unordered_map<std::string,int> ingredients) {
    return this->inventory->requestIngredients(ingredients);
}

void Management::notifyWaiterOfCancellation() {
    waiter->getCanceledOrderFromKitchen();
}

void Management::notifyWaiterOfCompletion() {
    waiter->getOrderFromKitchen();
}

void Management::notifyPlayerOfChangeInMood() {
    // TODO - implement a function in the ui that will display a message to the player
}

void Management::clearOutTable(std::shared_ptr<Table> table) {
    this->reservationSystem->clearOutTable(table);
}

json Management::requestReservation(json reservation) {
    this->receptionist->requestReservation(customer, reservation["section"]);
    return reservation;
}

void Management::requestToBeSeated(std::shared_ptr<CustomerTemplate> customer) {
    this->receptionist->requestToBeSeated(customer);
}

std::shared_ptr<Section> Management::getGeneralSection() {
    return this->reservationSystem->getGeneralSection();
}

std::shared_ptr<Section> Management::getPrivateSection() {
    return this->reservationSystem->getPrivateSection();
}

std::vector<std::shared_ptr<CustomerTemplate>> Management::getCustomers() {
    return this->reservationSystem->getCustomers();
}