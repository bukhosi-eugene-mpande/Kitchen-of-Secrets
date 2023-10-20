#include "Waiter.h"
#include "Management.h"

Waiter::Waiter() {
}

Waiter::Waiter(const Waiter& other) {
    this->management = other.management;
    this->finishedOrders = other.finishedOrders;
    this->canceledOrders = other.canceledOrders;
}

Waiter::~Waiter() {
}

void Waiter::sendOrderToKitchen(std::shared_ptr<Order> order) {
    this->management->sendOrderToKitchen(order);
}

void Waiter::getOrderFromKitchen() {
    finishedOrders.push_back(this->management->getOrderFromKitchen(std::shared_ptr<Waiter>(this)));
}

void Waiter::getCanceledOrderFromKitchen() {
    canceledOrders.push_back(this->management->getCanceledOrderFromKitchen(std::shared_ptr<Waiter>(this)));
}
