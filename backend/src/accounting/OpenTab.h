#ifndef OPENTAB_H
#define OPENTAB_H

#include "TabState.h"

/**
 * @class OpenTab
 * Represents the state of an open tab.
 * Inherits from TabState.
 */
class OpenTab : public TabState{
    public:
        /**
         * Constructs an OpenTab object.
         * @param tab A pointer to the Tab object associated with this OpenTab.
         */
        OpenTab(Tab *tab);

        /**
         * Closes the tab and returns a string representation of the bill.
         * @return A string representation of the bill.
         */
        std::string closeTab();

        /**
         * Calculates and returns the total cost of the bill.
         * @return The total cost of the bill.
         */
        double getBillTotal();

        /**
         * Adds the cost of an order to the bill.
         * @param cost The cost of the order.
         * @return A string representation of the updated bill.
         */
        std::string addOrderCost(double cost);
};

#endif