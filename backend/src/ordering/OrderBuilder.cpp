#include "OrderBuilder.h"

OrderBuilder::OrderBuilder() {
    this->order = nullptr;
}

OrderBuilder::~OrderBuilder() {

}

void OrderBuilder::setTable(std::shared_ptr<Table> table) {
    this->table = table;
}

void OrderBuilder::setWaiter(Waiter* waiter) {
    this->waiter = waiter;
}

void OrderBuilder::addMeal(std::shared_ptr<MenuItem> meal) {
    this->meals.push_back(meal);
}

std::shared_ptr<Order> OrderBuilder::getOrder() {
    this->order = std::make_shared<Order>(this->table, this->meals, this->waiter);
    return this->order;
}

void OrderBuilder::reset()
{
    this->order=nullptr;
    this->meals.clear();
    this->table=nullptr;
}