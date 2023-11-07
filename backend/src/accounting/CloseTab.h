#ifndef CLOSETAB_H
#define CLOSETAB_H

#include <vector>
#include "TabState.h"

/**
 * @class CloseTab
 * @brief A class representing the state of a tab when it is closed.
 * 
 * This class inherits from the TabState class and provides implementations for the
 * closeTab(), getBillTotal(), and addOrderCost() methods.
 */
class CloseTab : public TabState{
    public:
        /**
         * @brief Constructor for CloseTab class.
         * @param tab A pointer to the Tab object associated with this state.
         */
        CloseTab(Tab *tab);

        /**
         * @brief Closes the tab and returns a string representation of the bill.
         * @return A string representation of the bill.
         */
        std::string closeTab();

        /**
         * @brief Gets the total cost of the bill.
         * @return The total cost of the bill.
         */
        double getBillTotal();

        /**
         * @brief Adds the cost of an order to the bill.
         * @param cost The cost of the order to be added.
         * @return A string representation of the updated bill.
         */
        std::string addOrderCost(double cost);
};

#endif