#ifndef ORDERBUILDER_H
#define ORDERBUILDER_H

#include "Order.h"
#include <memory>
#include <vector>

class OrderBuilder{
    protected:
        std::shared_ptr<Order> order;

        std::vector<std::shared_ptr<MenuItem>> meals;

        Waiter* waiter;

        std::shared_ptr<Table>  table;

    public:
        OrderBuilder();

        ~OrderBuilder();

        void setTable(std::shared_ptr<Table> table);

        void setWaiter(Waiter* waiter);

        void addMeal(std::shared_ptr<MenuItem> meal);

        std::shared_ptr<Order> getOrder();
        
        void reset();

};
#endif