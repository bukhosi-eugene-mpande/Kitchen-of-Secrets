#include "Kitchen.h"
#include "DeputyHeadChef.h"
#include "Management.h"
#include "Order.h"
#include "Meal.h"
#include "HeadChef.h"
#include <iostream>

Kitchen::Kitchen(std::shared_ptr<Engine> engine, std::shared_ptr<Management> management, std::vector<std::shared_ptr<Meal>> meals) : GameComponent(engine) {
    this->deputyHeadChef = nullptr;
    this->headChef = nullptr;
    this->management = management;

    for (auto meal : meals) {
        this->availableMeals[meal->getName()] = meal;
    }
}

Kitchen::~Kitchen() {}

void Kitchen::addMeal(std::shared_ptr<Meal> meal) {
    this->availableMeals[meal->getName()] = meal;
}

void Kitchen::addOrder(std::shared_ptr<Order> order) {
    if(this->deputyHeadChef != nullptr){
        this->deputyHeadChef->prepareOrder(order);
    }else{
        this->createDeputyHeadChef();
        this->deputyHeadChef->prepareOrder(order);
    }
}

void Kitchen::removeMeal(std::string name) {
    this->availableMeals.erase(name);
}

std::string Kitchen::getChefName(std::string meal) {
    return this->availableMeals[meal]->getChef();
}

std::shared_ptr<Order> Kitchen::getPreparedOrder(std::shared_ptr<Waiter> waiter) {
    for (auto order : this->preparedOrders) {
        if (order->getWaiter().get()->getId() == waiter.get()->getId()) {
            return order;
        }
    }
    return nullptr;
}

std::shared_ptr<Order> Kitchen::getCanceledOrder(std::shared_ptr<Waiter> waiter) {
    for (auto order : this->canceledOrders) {
        if (order->getWaiter() == waiter) {
            return order;
        }
    }
    return nullptr;
}

std::unordered_map<std::string,int> Kitchen::getIngredients(std::string name) {
    return this->availableMeals[name]->getIngredients();
}

double Kitchen::getPrice(std::string name) {
    return this->availableMeals[name]->getPrice();
}

std::unordered_map<int,std::string> Kitchen::getMenu() {
    std::unordered_map<int,std::string> menu;
    int i = 1;
    for (auto meal : this->availableMeals) {
        menu[i] = meal.first;
        i++;
    }
    return menu;
}

std::shared_ptr<Management> Kitchen::getManagement() const {
    return this->management;
}

void Kitchen::cancelOrder(std::shared_ptr<Order> order) {
    this->canceledOrders.push_back(order);
}

void Kitchen::finishOrder(std::shared_ptr<Order> order) {
    this->preparedOrders.push_back(order);
}

void Kitchen::createHeadChef() {
    if(this->headChef == nullptr){
        this->headChef = std::make_shared<HeadChef>(this, this->management);
    }
}

void Kitchen::createDeputyHeadChef() {
    if(this->deputyHeadChef == nullptr){
        this->deputyHeadChef = std::make_shared<DeputyHeadChef>(this);
    }
}

std::unordered_map<std::string,std::shared_ptr<Meal>> Kitchen::getAvailableMeals() const{
    return this->availableMeals;
}

std::shared_ptr<HeadChef> Kitchen::getHeadChef() const{
    return this->headChef;
}

std::shared_ptr<DeputyHeadChef> Kitchen::getDeputyHeadChef() const{
    return this->deputyHeadChef;
}

std::vector<std::shared_ptr<Order>> Kitchen::getPreparedOrders() const{
    return this->preparedOrders;
}

std::vector<std::shared_ptr<Order>> Kitchen::getCanceledOrders() const{
    return this->canceledOrders;
}

void Kitchen::sendEvent() {}

void Kitchen::receiveEvent(std::string event) {
    if (event == "Add Meal") {
        addMeal(getMeal());
    }
    if (event == "Add Order") {
        addOrder(getOrder());
    }
    if (event == "Remove Meal") {
        removeMeal(getMeal());
    }
    if (event == "Get Prepared Order") {
        getPreparedOrder();
    }
    if (event == "Get Cancelled Order") {
        getCanceledOrder();
    }
 }

std::vector<std::string> Kitchen::generateListOfResposibilties(std::string chefName){
    std::vector<std::string> responsibilities;

    for(auto meal : this->availableMeals){
        if(meal.second.get()->getChef() == chefName){
            responsibilities.push_back(meal.second.get()->getName());
        }
    }

    return responsibilities;
}