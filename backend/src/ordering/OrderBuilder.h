#ifndef ORDERBUILDER_H
#define ORDERBUILDER_H

#include "Order.h"
#include <memory>
#include <vector>

class OrderBuilder{
    protected:
        std::shared_ptr<Order> order;
        std::vector<std::shared_ptr<MenuItem>> meals;
        std::shared_ptr<Waiter> waiter;
        int tableNumber;

    public:
        OrderBuilder();
        ~OrderBuilder();
        void setTableNumber(int tableNumber);
        void setWaiter(std::shared_ptr<Waiter> waiter);
        void addMeal(std::shared_ptr<MenuItem> meal);
        std::shared_ptr<Order> getOrder();
        void reset();

};
#endif