/**
 * @file Waiter.h
 * @brief Contains the declaration of the Waiter class.
 */

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

#include "../customercare/CustomerTemplate.h"
#include "../reservation/Section.h"
#include "../management/PlayerInteraction.h"

class Food;
class Beverage;

/**
 * @class Waiter
 * @brief Represents a waiter responsible for taking and managing customer orders.
 *
 * The Waiter class manages customer orders in a restaurant, including taking drink and food orders, creating and delivering orders, and interacting with the kitchen and customers.
 */
class Waiter {
private:
    PlayerInteraction* management; /**< A pointer used to communicate with classes outside of the ordering system. */
    Section* section; /**< The section to which the waiter is assigned. */
    std::shared_ptr<OrderBuilder> orderBuilder; /**< A builder for creating orders. */
    std::shared_ptr<Menu> BeverageMenu; /**< The menu for beverages. */
    std::shared_ptr<Menu> FoodMenu; /**< The menu for food. */
    std::vector<std::string> reciepts; /**< A vector of receipts for orders. */
    std::vector<std::shared_ptr<Order>> orders; /**< A vector of orders managed by the waiter. */
    static int nextId; /**< A static variable to keep track of the next available waiter ID. */
    int id; /**< The unique identifier for the waiter. */

public:
    /**
     * @brief Constructor for the Waiter class.
     * @param section A pointer to the section to which the waiter is assigned.
     * @param management A pointer used to communicate with classes outside of the ordering system.
     */
    Waiter(Section* section, PlayerInteraction* management);

    /**
     * @brief Destructor for the Waiter class.
     */
    ~Waiter();

    /**
     * @brief Take drink orders from a customer and add them to an order.
     * @param customer A shared pointer to the customer placing the order.
     * @param table A shared pointer to the table associated with the order.
     * @return A vector of shared pointers to the menu items included in the drink order.
     */
    std::vector<std::shared_ptr<MenuItem>> takeDrinksOrder(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);

    /**
     * @brief Take food orders from a customer and add them to an order.
     * @param customer A shared pointer to the customer placing the order.
     * @param table A shared pointer to the table associated with the order.
     * @return A vector of shared pointers to the menu items included in the food order.
     */
    std::vector<std::shared_ptr<MenuItem>> takeFoodOrder(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);

    /**
     * @brief Perform order rounds to manage customer orders and deliver them.
     */
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
        
        std::vector<std::string> getRecipts();
};
#endif