#include "Order.h"
#include "MenuItem.h"
#include "Waiter.h"
#include "../reservation/Table.h"

Order::Order(std::shared_ptr<Table> table, std::vector<std::shared_ptr<MenuItem>> meals, Waiter* waiter) {
    this->table = table;
    this->meals = meals;
    this->waiter = waiter;
    this->isCancelled = false;
}

Order::Order(const Order& other) {
    this->table = other.table;
    this->meals = other.meals;
    this->waiter = other.waiter;
    this->isCancelled = other.isCancelled;
}

Order::~Order() {

}

double Order::calculatePrice() {
    double price = 0;
    for (auto meal : meals) {
        price += meal->getMealPrice();
    }
    return price;
}

std::unordered_map<std::string,int> Order::calculateIngredients() {
    std::unordered_map<std::string,int> ingredients;
    for (auto meal : meals) {
        for (auto ingredient : meal->getMealIngredients()) {
            if (ingredients.find(ingredient.first) == ingredients.end()) {
                ingredients[ingredient.first] = ingredient.second;
            } else {
                ingredients[ingredient.first] += ingredient.second;
            }
        }
    }
    return ingredients;
}

Waiter* Order::getWaiter() const {
    return this->waiter;
}

std::shared_ptr<Table> Order::getTable() const {
    return this->table;
}

bool Order::getIsCancelled() const {
    return this->isCancelled;
}

void Order::setIsCancelled(bool isCancelled) {
    this->isCancelled = isCancelled;
}

void Order::setWaiter(Waiter* waiter) {
    this->waiter = waiter;
}

void Order::setTable(std::shared_ptr<Table> table) {
    this->table = table;
}

void Order::addMeal(std::shared_ptr<MenuItem> meal) {
    this->meals.push_back(meal);
}

bool Order::removeMeal(std::shared_ptr<MenuItem> meal) {
    for (int i = 0; i < (int) meals.size(); i++) {
        if (meals[i]->getName() == meal->getName()) {
            meals.erase(meals.begin() + i);
            return true;
        }
    }
    return false;
}

std::shared_ptr<MenuItem> Order::getMeal(std::string name) {
    for (auto meal : meals) {
        if (meal->getName() == name) {
            return meal;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<MenuItem>> Order::getMeals() const {
    return this->meals;
}
