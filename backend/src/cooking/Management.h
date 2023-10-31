#ifndef Management_H
#define Management_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Waiter.h"
#include "Kitchen.h"
#include "Inventory.h"


class Management {
    private:
        std::shared_ptr<Kitchen> kitchen;
        std::shared_ptr<Inventory> inventory;

    public:
        Management();

        ~Management();

        void sendOrderToKitchen(std::shared_ptr<Order> order);

        std::shared_ptr<Order> getOrderFromKitchen(std::shared_ptr<Waiter> waiter);

        std::shared_ptr<Order> getCanceledOrderFromKitchen(std::shared_ptr<Waiter> waiter);

        void setKitchen(std::shared_ptr<Kitchen> kitchen);

        bool requestIngredients(std::unordered_map<std::string,int> ingredients);

        void notifyWaiterOfCancellation(std::shared_ptr<Waiter> waiter);

        void notifyWaiterOfCompletion(std::shared_ptr<Waiter> waiter);

        void setInventory(std::shared_ptr<Inventory> inventory);

};

#endif