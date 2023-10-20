#ifndef Waiter_H
#define Waiter_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Order.h"
#include "Meal.h"

class Management;

class Waiter {
    private:
        std::shared_ptr<Management> management;
        std::vector<std::shared_ptr<Order>> finishedOrders;
        std::vector<std::shared_ptr<Order>> canceledOrders;

    public:

        Waiter();

        Waiter(const Waiter& other);

        ~Waiter();

        void sendOrderToKitchen(std::shared_ptr<Order> order);

        void getOrderFromKitchen();

        void getCanceledOrderFromKitchen();
};

#endif