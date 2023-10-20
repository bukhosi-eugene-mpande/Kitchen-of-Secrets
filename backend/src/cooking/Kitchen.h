#ifndef Kitchen_H
#define Kitchen_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Order.h"
#include "Meal.h"

class Waiter;
class Management;

class Kitchen {
    private:
    std::unordered_map<std::string,std::shared_ptr<Meal>> AvailableMeals;
    std::vector<std::shared_ptr<Order>> unPreparedOrders;
    std::vector<std::shared_ptr<Order>> preparedOrders;
    std::vector<std::shared_ptr<Order>> canceledOrders; 
    int numMeals;
    std::shared_ptr<Management> management;

    public:

        Kitchen();

        Kitchen(const Kitchen& other);

        ~Kitchen();

        std::string getName() const;

        bool addMeal(std::shared_ptr<Meal> meal);

        void addOrder(std::shared_ptr<Order> order);

        bool removeMeal(std::string name);

        std::shared_ptr<Order> getPreparedOrder(std::shared_ptr<Waiter> waiter);

        std::shared_ptr<Order> getCanceledOrder(std::shared_ptr<Waiter> waiter);

        std::unordered_map<std::string,int> getIngredients(std::string name);

        double getPrice(std::string name);

        std::unordered_map<int,std::string> getMenu();

        void prepareOrder();

        std::shared_ptr<Management> getManagement() const;

        void cancelOrder(std::shared_ptr<Order> order);

        void finishOrder(std::shared_ptr<Order> order);

        void notifyWaiterOfPreparedOrder(std::shared_ptr<Order> order);

        void notifyWaiterOfCanceledOrder(std::shared_ptr<Order> order);

        std::unordered_map<std::string,std::shared_ptr<Meal>> getAvailableMeals() const;

};

#endif