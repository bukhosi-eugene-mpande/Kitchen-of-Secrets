/**
 * @file OverdueTab.h
 * @brief Contains the declaration of the OverdueTab class.
 */

#ifndef OVERDUETAB_H
#define OVERDUETAB_H

#include "TabState.h"

/**
 * @class OverdueTab
 * @brief Represents an overdue tab state with methods for managing the tab.
 */
class OverdueTab : public TabState {
public:
    /**
     * @brief Constructor for the OverdueTab class.
     * @param tab A pointer to the Tab associated with this state.
     */
    OverdueTab(Tab* tab);

    /**
     * @brief Close the tab and transition to a closed state.
     * @return A message indicating the result of closing the tab.
     */
    std::string closeTab();

    /**
     * @brief Get the total bill amount for the tab.
     * @return The total bill amount for the tab.
     */
    double getBillTotal();

    /**
     * @brief Add the cost of an order to the tab.
     * @param cost The cost of the order to be added.
     * @return A message indicating the result of adding the order cost.
     */
    std::string addOrderCost(double cost);
};

#endif
