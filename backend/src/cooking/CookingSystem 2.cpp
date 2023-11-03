#include "CookingSystem.h"

CookingSystem::CookingSystem() {
    this->inventory = std::make_shared<Inventory>(std::unordered_map<std::string,int>({{"tomato", 10}, {"lettuce", 10}, {"cheese", 10}, {"patty", 10}}));
}

CookingSystem::~CookingSystem() {
}

std::shared_ptr<Kitchen> CookingSystem::getKitchen()
{
    return kitchen;
}

void CookingSystem::sendOrderToKitchen(std::shared_ptr<Order> order) {
    this->kitchen->addOrder(order);
}

std::shared_ptr<Order> CookingSystem::getOrderFromKitchen(std::shared_ptr<Waiter> waiter) {
    return this->kitchen->getPreparedOrder(waiter);
}

std::shared_ptr<Order> CookingSystem::getCanceledOrderFromKitchen(std::shared_ptr<Waiter> waiter) {
    return this->kitchen->getCanceledOrder(waiter);
}

bool CookingSystem::requestIngredients(std::unordered_map<std::string,int> ingredients) {
    return this->inventory->requestIngredients(ingredients);
}

void CookingSystem::notifyWaiterOfCancellation(std::shared_ptr<Waiter> waiter) {
    waiter->getCanceledOrderFromKitchen();
}

void CookingSystem::notifyWaiterOfCompletion(std::shared_ptr<Waiter> waiter) {
    waiter->getOrderFromKitchen();
}

void CookingSystem::setKitchen(std::shared_ptr<Kitchen> kitchen) {
    this->kitchen = kitchen;
}

std::shared_ptr<Inventory> CookingSystem::getInventory()
{
    return inventory;
}

void CookingSystem::setInventory(std::shared_ptr<Inventory> inventory){
    this->inventory = inventory;
}
