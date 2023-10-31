#include "Management.h"

Management::Management() {
    this->inventory = std::make_shared<Inventory>(std::unordered_map<std::string,int>({{"tomato", 10}, {"lettuce", 10}, {"cheese", 10}, {"patty", 10}}));
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
