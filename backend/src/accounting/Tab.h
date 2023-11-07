#ifndef TAB_H
#define TAB_H

#include "TabState.h"

/**
 * @brief The Tab class represents a customer's tab at a restaurant.
 */
class Tab{
    private:
        TabState *state;

    public:
        /**
         * @brief Constructs a new Tab object.
         */
        Tab();

        /**
         * @brief Closes the tab and returns a string representation of the total cost.
         * @return A string representation of the total cost.
         */
        std::string closeTab();

        /**
         * @brief Gets the total cost of the tab.
         * @return The total cost of the tab.
         */
        double getBillTotal();

        /**
         * @brief Adds the cost of an order to the tab.
         * @param cost The cost of the order.
         * @return A string representation of the updated tab.
         */
        std::string addOrderCost(double cost);

        /**
         * @brief Sets the state of the tab.
         * @param state The new state of the tab.
         */
        void setState(TabState *state);
};

#endif