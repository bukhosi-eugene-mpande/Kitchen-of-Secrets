#ifndef OVERDUETAB_H
#define OVERDUETAB_H

#include <vector>
#include "TabState.h"

/**
 * @brief The OverdueTab class represents a tab that is currently overdue.
 * 
 * This class inherits from the TabState class and provides functionality for closing the tab, 
 * getting the total bill amount, and adding the cost of an order to the tab.
 */
class OverdueTab : public TabState {
    public:
        /**
         * @brief Constructs a new OverdueTab object.
         * 
         * @param tab A pointer to the Tab object that this OverdueTab object belongs to.
         */
        OverdueTab(Tab *tab);

        /**
         * @brief Closes the tab and returns a string representation of the total bill amount.
         * 
         * @return A string representation of the total bill amount.
         */
        std::string closeTab();

        /**
         * @brief Gets the total bill amount for the tab.
         * 
         * @return The total bill amount for the tab.
         */
        double getBillTotal();

        /**
         * @brief Adds the cost of an order to the tab.
         * 
         * @param cost The cost of the order to add to the tab.
         * @return A string representation of the updated total bill amount.
         */
        std::string addOrderCost(double cost);
};

#endif