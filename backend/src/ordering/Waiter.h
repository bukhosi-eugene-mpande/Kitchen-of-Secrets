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
 * @brief Represents a waiter in a restaurant management system.
 */
class Waiter {
private:
    /**
     * @brief Used to communicate with other classes outside of the ordering system.
     */
    PlayerInteraction* management;

    /**
     * @brief The section the waiter is assigned to.
     */
    Section* section;

    /**
     * @brief Builder for creating orders.
     */
    std::shared_ptr<OrderBuilder> orderBuilder;

    /**
     * @brief Menu for beverages.
     */
    std::shared_ptr<Menu> BeverageMenu;

    /**
     * @brief Menu for food items.
     */
    std::shared_ptr<Menu> FoodMenu;

    /**
     * @brief Stores receipts.
     */
    std::vector<std::string> reciepts;

    /**
     * @brief Stores orders made by customers.
     */
    std::vector<std::shared_ptr<Order>> orders;

    /**
     * @brief Static variable to keep track of the next waiter's ID.
     */
    static int nextId;

    /**
     * @brief ID assigned to the waiter.
     */
    int id;

public:
    /**
     * @brief Constructor for the Waiter class.
     * @param section The section to which the waiter is assigned.
     * @param management A pointer to the PlayerInteraction object for communication.
     */
    Waiter(Section* section, PlayerInteraction* management);

    /**
     * @brief Destructor for the Waiter class.
     */
    ~Waiter();

    /**
     * @brief Takes a drinks order from a customer.
     * @param customer The customer placing the order.
     * @param table The table where the customer is seated.
     * @return A vector of MenuItem objects representing the ordered drinks.
     */
    std::vector<std::shared_ptr<MenuItem>> takeDrinksOrder(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);

    /**
     * @brief Takes a food order from a customer.
     * @param customer The customer placing the order.
     * @param table The table where the customer is seated.
     * @return A vector of MenuItem objects representing the ordered food items.
     */
    std::vector<std::shared_ptr<MenuItem>> takeFoodOrder(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);

    /**
     * @brief Performs order rounds for taking and sending orders to the kitchen.
     */
    void doOrderRounds();

    /**
     * @brief Gets the payment type from the customer.
     * @param customer The customer making the payment.
     */
    void getPaymentTypeFromCustomer(std::shared_ptr<CustomerTemplate> customer);

    /**
     * @brief Serves an order to the customer.
     * @param order The order to be served.
     */
    void serveOrder(std::shared_ptr<Order> order);

    /**
     * @brief Bills the customer for an order.
     * @param order The order to be billed.
     * @return The total bill amount.
     */
    double billOrder(std::shared_ptr<Order> order);

    /**
     * @brief Sends the orders to the kitchen for preparation.
     */
    void sendOrdersToKitchen();

    /**
     * @brief Sends the bill amount to the accounting department.
     * @param billAmount The total bill amount.
     */
    void sendBillToAccounting(double billAmount);

    /**
     * @brief Sends the payment type to the accounting department.
     * @param paymentType The type of payment (e.g., cash, credit).
     */
    void sendTypeToAccounting(std::string paymentType);

    /**
     * @brief Creates a food item.
     * @param price The price of the food item.
     * @param name The name of the food item.
     * @param ingredients The list of ingredients and their quantities.
     * @return A shared pointer to the created Food object.
     */
    std::shared_ptr<Food> createFoodItem(double price, std::string name, std::unordered_map<std::string, int> ingredients);

    /**
     * @brief Creates a drink item.
     * @param isAlcoholic Indicates whether the drink is alcoholic.
     * @param price The price of the drink.
     * @param name The name of the drink.
     * @param ingredients The list of ingredients and their quantities.
     * @return A shared pointer to the created Beverage object.
     */
    std::shared_ptr<Beverage> createDrinkItem(bool isAlcoholic, double price, std::string name, std::unordered_map<std::string, int> ingredients);

    /**
     * @brief Creates the menus for beverages and food.
     */
    void createMenus();

    /**
     * @brief Retrieves a canceled order from the kitchen.
     */
    void getCanceledOrderFromKitchen();

    /**
     * @brief Retrieves an order from the kitchen.
     */
    void getOrderFromKitchen();

    /**
     * @brief Serves a bill to the customer for a specific order.
     * @param customer The customer to whom the bill is served.
     * @param order The order for which the bill is generated.
     */
    void serveBill(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Order> order);

    /**
     * @brief Gets the ID of the waiter.
     * @return The waiter's ID.
     */
    int getId();

    /**
     * @brief Serves a bill for an order.
     */
    void serveBill();

    /**
     * @brief Gets the receipts.
     * @return A vector of receipt strings.
     */
    std::vector<std::string> getRecipts();
};

#endif
