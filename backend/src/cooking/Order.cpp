#include "Order.h"
#include "MenuItem.h"
#include "Waiter.h"

Order::Order(int tableNumber, std::vector<std::shared_ptr<MenuItem>> meals, std::shared_ptr<Waiter> waiter) {
    this->tableNumber = tableNumber;
    this->meals = meals;
    this->waiter = waiter;
    this->isCancelled = false;
}

Order::Order(const Order& other) {
    this->tableNumber = other.tableNumber;
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

std::shared_ptr<Waiter> Order::getWaiter() const {
    return this->waiter;
}

int Order::getTableNumber() const {
    return this->tableNumber;
}

bool Order::getIsCancelled() const {
    return this->isCancelled;
}

void Order::setIsCancelled(bool isCancelled) {
    this->isCancelled = isCancelled;
}

void Order::setWaiter(std::shared_ptr<Waiter> waiter) {
    this->waiter = waiter;
}

void Order::setTableNumber(int tableNumber) {
    this->tableNumber = tableNumber;
}

void Order::addMeal(std::shared_ptr<MenuItem> meal) {
    this->meals.push_back(meal);
}

bool Order::removeMeal(std::shared_ptr<MenuItem> meal) {
    for (int i = 0; i < meals.size(); i++) {
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
