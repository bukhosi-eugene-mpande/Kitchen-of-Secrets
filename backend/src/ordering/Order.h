/**
 * @file Order.h
 * @brief Contains the declaration of the Order class.
 */

#ifndef ORDER_H
#define ORDER_H

#include "AbstractOrder.h"
#include <vector>
#include <string>
#include <memory>

class Waiter;
class Table;

/**
 * @class Order
 * @brief Represents an order containing multiple menu items.
 *
 * The Order class stores information about a customer's order, including the associated table, waiter, and menu items.
 */
class Order : public AbstractOrder {
private:
    std::shared_ptr<Table> table; /**< A shared pointer to the table associated with the order. */
    Waiter* waiter; /**< A pointer to the waiter who served the order. */
    bool isCancelled; /**< A flag indicating whether the order is cancelled. */

public:
    /**
     * @brief Constructor for the Order class.
     * @param table A shared pointer to the table associated with the order.
     * @param meals A vector of shared pointers to menu items included in the order.
     * @param waiter A pointer to the waiter who served the order.
     */
    Order(std::shared_ptr<Table> table, std::vector<std::shared_ptr<MenuItem>> meals, Waiter* waiter);

    /**
     * @brief Copy constructor for the Order class.
     * @param other The Order object to be copied.
     */
    Order(const Order& other);

    /**
     * @brief Destructor for the Order class.
     */
    ~Order();

    /**
     * @brief Calculate the total price of the order.
     * @return The total price of the order.
     */
    double calculatePrice();

    /**
     * @brief Calculate the combined ingredients of all menu items in the order.
     * @return An unordered map of ingredients and their quantities.
     */
    std::unordered_map<std::string, int> calculateIngredients();

    /**
     * @brief Get the waiter associated with the order.
     * @return A pointer to the waiter.
     */
    Waiter* getWaiter() const;

        std::shared_ptr<Table> getTable() const;

        bool getIsCancelled() const;

        void setIsCancelled(bool isCancelled);

        void setWaiter(Waiter* waiter);

        void setTable(std::shared_ptr<Table> table);

        void addMeal(std::shared_ptr<MenuItem> meal);

        bool removeMeal(std::shared_ptr<MenuItem> meal);

        std::shared_ptr<MenuItem> getMeal(std::string name);

        std::vector<std::shared_ptr<MenuItem>> getMeals() const;

};

#endif