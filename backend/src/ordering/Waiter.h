#ifndef WAITER_H
#define WAITER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>  
#include <unordered_map>
#include <memory>

#include "Order.h"
#include "MenuItem.h"
#include "Menu.h"
#include "OrderBuilder.h"

class Waiter{
    private:
        std::vector<std::shared_ptr<Order>> orders;
        std::shared_ptr<OrderBuilder> orderBuilder;
        std::shared_ptr<Menu> menu;
        std::string name;
        int id;

    public:
        Waiter();
        ~Waiter();
        void takeOrder();
        void serveOrder();
        double billOrder();
        void sendOrdersToKitchen();
        void giveOrderToCustomer();
        std::shared_ptr<MenuItem> createFoodItem();
        std::shared_ptr<MenuItem> createDrinkItem();
        std::shared_ptr<Menu> createMenu();
        std::shared_ptr<Order> getCanceledOrderFromKitchen();
        std::shared_ptr<Order> getOrderFromKitchen();
        void buildOrder();
        int getId();

};
#endif