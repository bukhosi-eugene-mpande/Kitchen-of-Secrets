#ifndef Waiter_H
#define Waiter_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include "Order.h"

class Waiter {
    private:
        std::string name;
        int id;
    public:
        Waiter(std::string name, int id);
        
        ~Waiter();

        std::shared_ptr<Order> getCanceledOrderFromKitchen();

        std::shared_ptr<Order> getOrderFromKitchen();
};

#endif