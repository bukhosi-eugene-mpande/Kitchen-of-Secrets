#ifndef ABSTRACT_ORDER_H
#define ABSTRACT_ORDER_H

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

class MenuItem;

/**
 * @brief The AbstractOrder class represents an abstract order that can be placed in a restaurant.
 * 
 * This class defines the basic structure of an order, including its ingredients, price, and meals.
 * It also provides methods for calculating the price and ingredients of the order.
 */
class AbstractOrder{
    protected:
        std::unordered_map<std::string,int> ingredients; ///< A map of the ingredients in the order and their quantities.
        double price; ///< The total price of the order.
        std::vector<std::shared_ptr<MenuItem>> meals; ///< A vector of the meals in the order.

    public:
        /**
         * @brief Constructs a new AbstractOrder object.
         * 
         * This constructor initializes the ingredients map and price to zero.
         */
        AbstractOrder();

        /**
         * @brief Destroys the AbstractOrder object.
         * 
         * This destructor is virtual to ensure that the object is properly destroyed when deleted.
         */
        virtual ~AbstractOrder();

        /**
         * @brief Calculates the total price of the order.
         * 
         * This method calculates the total price of the order based on the prices of its meals.
         * 
         * @return The total price of the order.
         */
        virtual double calculatePrice() = 0;

        /**
         * @brief Calculates the ingredients in the order.
         * 
         * This method calculates the ingredients in the order based on the ingredients of its meals.
         * 
         * @return A map of the ingredients in the order and their quantities.
         */
        virtual std::unordered_map<std::string,int> calculateIngredients() = 0;

        /**
         * @brief Gets the ingredients in the order.
         * 
         * This method returns the ingredients map of the order.
         * 
         * @return A map of the ingredients in the order and their quantities.
         */
        std::unordered_map<std::string,int> getIngredients() const;

        /**
         * @brief Gets the total price of the order.
         * 
         * This method returns the total price of the order.
         * 
         * @return The total price of the order.
         */
        double getPrice() const;

        /**
         * @brief Checks if the order is finished.
         * 
         * This method checks if the order is finished, i.e., if all its meals have been prepared.
         * 
         * @return True if the order is finished, false otherwise.
         */
        bool IsFinished();
};

#endif