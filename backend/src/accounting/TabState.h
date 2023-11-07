#ifndef TABSTATE_H
#define TABSTATE_H

#include <vector>
#include "../json.hpp"

using json = nlohmann::json;

class Tab;

/**
 * @brief The TabState class represents the state of a tab in a restaurant accounting system.
 * 
 * This class is an abstract base class that defines the interface for all tab states.
 * A tab state is responsible for keeping track of the orders made by a customer, calculating the total bill,
 * and closing the tab when the customer is ready to pay.
 */
class TabState{
    protected:
        Tab *tab; /**< A pointer to the Tab object associated with this tab state. */
        std::vector<double> orders; /**< A vector of doubles representing the cost of each order made by the customer. */

    public:
        /**
         * @brief Constructs a new TabState object.
         * 
         * @param tab A pointer to the Tab object associated with this tab state.
         */
        TabState(Tab *tab);

        /**
         * @brief Closes the tab and returns a string representation of the bill.
         * 
         * This method is pure virtual and must be implemented by all derived classes.
         * 
         * @return A string representation of the bill.
         */
        virtual std::string closeTab() = 0;

        /**
         * @brief Calculates and returns the total bill for this tab.
         * 
         * This method is pure virtual and must be implemented by all derived classes.
         * 
         * @return The total bill for this tab.
         */
        virtual double getBillTotal() = 0;

        /**
         * @brief Adds the cost of a new order to this tab.
         * 
         * This method is pure virtual and must be implemented by all derived classes.
         * 
         * @param cost The cost of the new order.
         * @return A string representation of the updated tab state.
         */
        virtual std::string addOrderCost(double cost) = 0;
};

#endif