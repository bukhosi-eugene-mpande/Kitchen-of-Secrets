#include "PlayerInteraction.h"

PlayerInteraction::PlayerInteraction(std::shared_ptr<Engine> engine, std::shared_ptr<AccountingSystem> accountingSystem, std::shared_ptr<CookingSystem> cookingSystem, std::shared_ptr<CustomerCareSystem> customerCareSystem, std::shared_ptr<Kitchen> kitchen, std::shared_ptr<Inventory> inventory, std::shared_ptr<ReservationSystem> reservationSystem, std::shared_ptr<Order> order) : GameComponent(engine) {
    this->accountingSystem = accountingSystem;
    this->cookingSystem = cookingSystem;
    this->customerCareSystem = customerCareSystem;
    this->kitchen = kitchen;
    this->inventory = inventory;
    this->reservationSystem = reservationSystem;
    this->order = order;
}

PlayerInteraction::~PlayerInteraction() {}

void PlayerInteraction::payment(std::vector<std::shared_ptr<Customer>> customers) {
    std::vector<std::shared_ptr<Customer>>::iterator index = customers.begin();
    for (index; index < customers.end(); index++) {
        (*index)->makePayment();
        accountingSystem->setBalance(accountingSystem->getBalance() + (*index)->getTotalBill());
    }
}

void PlayerInteraction::addToTab(std::vector<std::shared_ptr<Customer>> customers) {
    std::vector<std::shared_ptr<Customer>>::iterator index = customers.begin();
    for (index; index < customers.end(); index++) {
       (*index)->setTotalTab((*index)->getTotalBill());
    }
}

void PlayerInteraction::closeTab(std::vector<std::shared_ptr<Customer>> customers) {
    std::vector<std::shared_ptr<Customer>>::iterator index = customers.begin();
    for (index; index < customers.end(); index++) {
        accountingSystem->setBalance((*index)->getTotalTab());
        (*index)->closeTab();
    }
}

void PlayerInteraction::sendOrderToKitchen(std::shared_ptr<Order> order) {
    kitchen->addOrder(order);
}

std::shared_ptr<Order> PlayerInteraction::getOrderFromKitchen(std::shared_ptr<Waiter> waiter) {
    return kitchen->getPreparedOrder(waiter);
}

std::shared_ptr<Order> PlayerInteraction::getCanceledOrderFromKitchen(std::shared_ptr<Waiter> waiter) {
    return kitchen->getCanceledOrder(waiter);
}

bool PlayerInteraction::requestIngredients(std::unordered_map<std::string, int> ingredients) {
    return inventory->requestIngredients(ingredients);
}

void PlayerInteraction::notifyWaiterOfCancellation(std::shared_ptr<Waiter> waiter) {
    waiter->getCanceledOrderFromKitchen();
}

void PlayerInteraction::notifyWaiterOfCompletion(std::shared_ptr<Waiter> waiter) {
    waiter->getOrderFromKitchen();
}

void PlayerInteraction::purchaseInventory(std::unordered_map<std::string, int> ingredients) {
    bool success = requestIngredients(ingredients);
    if (success && accountingSystem->getBalance() > inventory->getTotalCost()) {
        accountingSystem->setBalance(accountingSystem->getBalance() - inventory->getTotalCost());
    }
}

void PlayerInteraction::seatCustomers(std::vector<std::shared_ptr<Customer>> customers) {
    reservationSystem->setNumberOfCustomers(customers.size());
}