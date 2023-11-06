/**
 * @file AbstractOrder.h
 * @brief Contains the declaration of the AbstractOrder class.
 */

#ifndef ABSTRACT_ORDER_H
#define ABSTRACT_ORDER_H

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

class MenuItem;

/**
 * @class AbstractOrder
 * @brief Represents an abstract order containing a list of menu items.
 *
 * The AbstractOrder class serves as a base class for different types of orders in the restaurant system. It contains a list of menu items, their ingredients, and provides methods for calculating the order's price and ingredients.
 */
class AbstractOrder {
protected:
    std::unordered_map<std::string, int> ingredients; ///< A list of ingredients in the order.
    double price; ///< The total price of the order.
    std::vector<std::shared_ptr<MenuItem>> meals; ///< A list of menu items in the order.

public:
    /**
     * @brief Constructor for the AbstractOrder class.
     */
    AbstractOrder();

    /**
     * @brief Virtual destructor for the AbstractOrder class.
     */
    virtual ~AbstractOrder();

    /**
     * @brief Calculate the total price of the order.
     * @return The calculated price of the order.
     */
    virtual double calculatePrice() = 0;

    /**
     * @brief Calculate the ingredients in the order.
     * @return An unordered map of ingredients and their quantities in the order.
     */
    virtual std::unordered_map<std::string, int> calculateIngredients() = 0;

    /**
     * @brief Get the list of ingredients in the order.
     * @return An unordered map of ingredients and their quantities.
     */
    std::unordered_map<std::string, int> getIngredients() const;

    /**
     * @brief Get the total price of the order.
     * @return The total price of the order.
     */
    double getPrice() const;

    /**
     * @brief Check if the order is finished.
     * @return True if the order is finished, false otherwise.
     */
    bool IsFinished();
};

#endif
