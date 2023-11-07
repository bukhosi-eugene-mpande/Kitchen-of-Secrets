#ifndef Order_H
#define Order_H

#include "AbstractOrder.h"
class Waiter;
class Table;

/**
 * @brief The Order class represents a customer's order at a restaurant.
 */
class Order : public AbstractOrder {
    private:
        std::shared_ptr<Table>  table; /**< The table where the order was placed. */
        Waiter* waiter; /**< The waiter who took the order. */
        bool isCancelled; /**< Whether the order has been cancelled. */

    public:

        /**
         * @brief Constructs an Order object.
         * 
         * @param table The table where the order was placed.
         * @param meals The list of meals ordered.
         * @param waiter The waiter who took the order.
         */
        Order(std::shared_ptr<Table> table, std::vector<std::shared_ptr<MenuItem>> meals, Waiter* waiter);

        /**
         * @brief Copy constructor for Order.
         * 
         * @param other The Order object to copy.
         */
        Order(const Order& other);

        /**
         * @brief Destructor for Order.
         */
        ~Order();

        /**
         * @brief Calculates the total price of the order.
         * 
         * @return The total price of the order.
         */
        double calculatePrice();

        /**
         * @brief Calculates the total amount of each ingredient used in the order.
         * 
         * @return A map of ingredient names to the total amount used.
         */
        std::unordered_map<std::string,int> calculateIngredients();

        /**
         * @brief Returns the waiter who took the order.
         * 
         * @return The waiter who took the order.
         */
        Waiter* getWaiter() const;

        /**
         * @brief Returns the table where the order was placed.
         * 
         * @return The table where the order was placed.
         */
        std::shared_ptr<Table> getTable() const;

        /**
         * @brief Returns whether the order has been cancelled.
         * 
         * @return Whether the order has been cancelled.
         */
        bool getIsCancelled() const;

        /**
         * @brief Sets whether the order has been cancelled.
         * 
         * @param isCancelled Whether the order has been cancelled.
         */
        void setIsCancelled(bool isCancelled);

        /**
         * @brief Sets the waiter who took the order.
         * 
         * @param waiter The waiter who took the order.
         */
        void setWaiter(Waiter* waiter);

        /**
         * @brief Sets the table where the order was placed.
         * 
         * @param table The table where the order was placed.
         */
        void setTable(std::shared_ptr<Table> table);

        /**
         * @brief Adds a meal to the order.
         * 
         * @param meal The meal to add.
         */
        void addMeal(std::shared_ptr<MenuItem> meal);

        /**
         * @brief Removes a meal from the order.
         * 
         * @param meal The meal to remove.
         * @return Whether the meal was successfully removed.
         */
        bool removeMeal(std::shared_ptr<MenuItem> meal);

        /**
         * @brief Returns a meal from the order by name.
         * 
         * @param name The name of the meal to return.
         * @return The meal with the given name, or nullptr if not found.
         */
        std::shared_ptr<MenuItem> getMeal(std::string name);

        /**
         * @brief Returns a vector of all meals in the order.
         * 
         * @return A vector of all meals in the order.
         */
        std::vector<std::shared_ptr<MenuItem>> getMeals() const;

};

#endif