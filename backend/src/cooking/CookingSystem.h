#ifndef COOKING_SYSTEM_H
#define COOKING_SYSTEM_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Waiter.h"
#include "Kitchen.h"
#include "Inventory.h"


class CookingSystem {
    private:
        std::shared_ptr<Kitchen> kitchen;
        std::shared_ptr<Inventory> inventory;

    public:
        CookingSystem();
        ~CookingSystem();
        std::shared_ptr<Kitchen> getKitchen();
        void setKitchen(std::shared_ptr<Kitchen> kitchen);
        std::shared_ptr<Inventory> getInventory();
        void setInventory(std::shared_ptr<Inventory> inventory);
        void sendOrderToKitchen(std::shared_ptr<Order> order);
        std::shared_ptr<Order> getOrderFromKitchen(std::shared_ptr<Waiter> waiter);
        std::shared_ptr<Order> getCanceledOrderFromKitchen(std::shared_ptr<Waiter> waiter);
        bool requestIngredients(std::unordered_map<std::string,int> ingredients);
        void notifyWaiterOfCancellation(std::shared_ptr<Waiter> waiter);
        void notifyWaiterOfCompletion(std::shared_ptr<Waiter> waiter);
};

#endif