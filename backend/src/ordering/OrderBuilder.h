/**
 * @file OrderBuilder.h
 * @brief Contains the declaration of the OrderBuilder class.
 */

#ifndef ORDERBUILDER_H
#define ORDERBUILDER_H

#include "Order.h"
#include <memory>
#include <vector>

/**
 * @class OrderBuilder
 * @brief Represents a builder for creating an Order object.
 *
 * The OrderBuilder class provides a way to construct an Order object by specifying its components, including the table, waiter, and menu items.
 */
class OrderBuilder {
protected:
    std::shared_ptr<Order> order; /**< A shared pointer to the Order being constructed. */
    std::vector<std::shared_ptr<MenuItem>> meals; /**< A vector of shared pointers to menu items included in the order. */
    Waiter* waiter; /**< A pointer to the waiter who served the order. */
    std::shared_ptr<Table> table; /**< A shared pointer to the table associated with the order. */

public:
    /**
     * @brief Constructor for the OrderBuilder class.
     */
    OrderBuilder();

    /**
     * @brief Destructor for the OrderBuilder class.
     */
    ~OrderBuilder();

    /**
     * @brief Set the table associated with the order.
     * @param table A shared pointer to the table.
     */
    void setTable(std::shared_ptr<Table> table);

    /**
     * @brief Set the waiter associated with the order.
     * @param waiter A pointer to the waiter.
     */
    void setWaiter(Waiter* waiter);

    /**
     * @brief Add a menu item to the order.
     * @param meal A shared pointer to the menu item to be added.
     */
    void addMeal(std::shared_ptr<MenuItem> meal);

    /**
     * @brief Get the constructed Order object.
     * @return A shared pointer to the Order.
     */
    std::shared_ptr<Order> getOrder();

    /**
     * @brief Reset the OrderBuilder to its initial state.
     */
    void reset();
};

#endif
