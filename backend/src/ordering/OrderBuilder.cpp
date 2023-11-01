#include "OrderBuilder.h"

OrderBuilder::OrderBuilder() {
    this->order = nullptr;
}

OrderBuilder::~OrderBuilder() {

}

void OrderBuilder::setTableNumber(int tableNumber) {
    this->tableNumber = tableNumber;
}

void OrderBuilder::setWaiter(std::shared_ptr<Waiter> waiter) {
    this->waiter = waiter;
}

void OrderBuilder::addMeal(std::shared_ptr<MenuItem> meal) {
    this->meals.push_back(meal);
}

std::shared_ptr<Order> OrderBuilder::getOrder() {
    this->order = std::make_shared<Order>(this->tableNumber, this->meals, this->waiter);
    return this->order;
}