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

#include "../reservation/Section.h"
#include "../sudo_management/Management.h"
#include "../customercare/CustomerTemplate.h"
#include "../sudo_accounting/PaymentOption.h"

class Food;
class Beverage;

class Waiter{
    private:
        Section* section;
        Management* management;
        std::vector<std::shared_ptr<Order>> orders;
        std::shared_ptr<OrderBuilder> orderBuilder;
        std::shared_ptr<Menu> BeverageMenu;
        std::shared_ptr<Menu> FoodMenu;
        int id;
        static int nextId;
        std::string payType;

    public:
        Waiter(Section* section, Management* management);
        ~Waiter();
        std::vector<std::shared_ptr<MenuItem>> takeDrinksOrder(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);
        std::vector<std::shared_ptr<MenuItem>> takeFoodOrder(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);
        void doOrderRounds();
        void getPaymentTypeFromCustomer(std::shared_ptr<CustomerTemplate> customer);
        void serveOrder(std::shared_ptr<Order> order);
        double billOrder(std::shared_ptr<Order> order);
        void sendOrdersToKitchen();
        
        void sendBillToAccounting(double);
        void sendTypeToAccounting(std::string);
        std::shared_ptr<Food> createFoodItem(double price,std::string name, std::unordered_map<std::string,int> ingredients);
        std::shared_ptr<Beverage> createDrinkItem(bool isAlcoholic,double price,std::string name, std::unordered_map<std::string,int> ingredients);
        void createMenus();
        void getCanceledOrderFromKitchen();
        void getOrderFromKitchen();
        void serveBill(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Order> order);
        int getId();
        void serveBill();

};
#endif