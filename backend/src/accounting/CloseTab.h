/**
 * @file CloseTab.h
 * @brief Contains the declaration of the CloseTab class, a concrete tab state.
 */

#ifndef CLOSETAB_H
#define CLOSETAB_H

#include <vector>
#include "TabState.h"

/**
 * @class CloseTab
 * @brief Represents a concrete tab state for closing a tab and generating the final bill.
 */
class CloseTab : public TabState {
public:
    /**
     * @brief Constructor for the CloseTab class.
     * @param tab A pointer to the Tab associated with this tab state.
     */
    CloseTab(Tab* tab);

    /**
     * @brief Close the tab and generate the final bill.
     * @return A string indicating the result of closing the tab.
     */
    std::string closeTab();

    /**
     * @brief Get the total bill amount for the tab.
     * @return The total bill amount.
     */
    double getBillTotal();

    /**
     * @brief Add the cost of an order to the tab's total bill.
     * @param cost The cost of the order to be added.
     * @return A string indicating the result of adding the order cost.
     */
    std::string addOrderCost(double cost);
};

#endif
