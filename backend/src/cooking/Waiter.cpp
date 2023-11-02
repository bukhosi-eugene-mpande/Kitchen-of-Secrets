#include "Waiter.h"

Waiter::Waiter(std::string name, int id) {
    this->name = name;
    this->id = id;
}

Waiter::~Waiter() {}

std::shared_ptr<Order> Waiter::getCanceledOrderFromKitchen() {
    /**
     * @todo Implement this function
     * 
     */
    return nullptr;
}

std::shared_ptr<Order> Waiter::getOrderFromKitchen() {
    /**
     * @todo Implement this function
     * 
     */
    return nullptr;
}

int Waiter::getId() {
    return this->id;
}
