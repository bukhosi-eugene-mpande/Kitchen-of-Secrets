#ifndef ORDERBUILDER_H
#define ORDERBUILDER_H

#include "Order.h"
#include <memory>
#include <vector>

/**
 * @brief The OrderBuilder class is responsible for building an Order object.
 * 
 * It allows the user to set the table, waiter, and add meals to the order.
 * Once all the necessary information is set, the user can retrieve the Order object.
 */
class OrderBuilder{
    protected:
        std::shared_ptr<Order> order;

        std::vector<std::shared_ptr<MenuItem>> meals;

        Waiter* waiter;

        std::shared_ptr<Table>  table;

    public:
        /**
         * @brief Construct a new OrderBuilder object
         * 
         */
        OrderBuilder();

        /**
         * @brief Destroy the OrderBuilder object
         * 
         */
        ~OrderBuilder();

        /**
         * @brief Set the Table object
         * 
         * @param table The table to set
         */
        void setTable(std::shared_ptr<Table> table);

        /**
         * @brief Set the Waiter object
         * 
         * @param waiter The waiter to set
         */
        void setWaiter(Waiter* waiter);

        /**
         * @brief Add a meal to the order
         * 
         * @param meal The meal to add
         */
        void addMeal(std::shared_ptr<MenuItem> meal);

        /**
         * @brief Get the Order object
         * 
         * @return std::shared_ptr<Order> The Order object
         */
        std::shared_ptr<Order> getOrder();
        
        /**
         * @brief Reset the OrderBuilder object to its initial state
         * 
         */
        void reset();

};
#endif