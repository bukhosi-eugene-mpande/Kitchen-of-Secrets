#include "Kitchen.h"
#include "DeputyHeadChef.h"
#include "Management.h"


Kitchen::Kitchen(std::shared_ptr<Management> management,std::shared_ptr<HeadChef> headChef,std::shared_ptr<DeputyHeadChef> deputyHeadChef,std::vector<std::shared_ptr<Meal>> meals)
{
    this->management = management;
    this->headChef = headChef;
    this->deputyHeadChef = deputyHeadChef;
    for (auto meal : meals) {
        this->AvailableMeals[meal->getName()] = meal;
    }
}

Kitchen::~Kitchen()
{
    
}

void Kitchen::addMeal(std::shared_ptr<Meal> meal)
{
    this->AvailableMeals[meal->getName()] = meal;
}

void Kitchen::addOrder(std::shared_ptr<Order> order)
{
    this->deputyHeadChef->prepareOrder(order);
}

void Kitchen::removeMeal(std::string name)
{
    this->AvailableMeals.erase(name);
}

std::shared_ptr<Order> Kitchen::getPreparedOrder(std::shared_ptr<Waiter> waiter)
{
    for (auto order : this->preparedOrders) {
        if (order->getWaiter() == waiter) {
            return order;
        }
    }
    return nullptr;
}

std::shared_ptr<Order> Kitchen::getCanceledOrder(std::shared_ptr<Waiter> waiter)
{
    for (auto order : this->canceledOrders) {
        if (order->getWaiter() == waiter) {
            return order;
        }
    }
    return nullptr;
}

std::unordered_map<std::string,int> Kitchen::getIngredients(std::string name)
{
    return this->AvailableMeals[name]->getIngredients();
}

double Kitchen::getPrice(std::string name)
{
    return this->AvailableMeals[name]->getPrice();
}

std::unordered_map<int,std::string> Kitchen::getMenu()
{
    std::unordered_map<int,std::string> menu;
    int i = 1;
    for (auto meal : this->AvailableMeals) {
        menu[i] = meal.first;
        i++;
    }
    return menu;
}

std::shared_ptr<Management> Kitchen::getManagement() const
{
    return this->management;
}

void Kitchen::cancelOrder(std::shared_ptr<Order> order)
{
    this->canceledOrders.push_back(order);
}

void Kitchen::finishOrder(std::shared_ptr<Order> order)
{
    this->preparedOrders.push_back(order);
}

