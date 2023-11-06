/**
 * @file OpenTab.h
 * @brief Contains the declaration of the OpenTab class.
 */

#ifndef OPENTAB_H
#define OPENTAB_H

#include "TabState.h"

/**
 * @class OpenTab
 * @brief Represents an open tab state with methods for managing the tab.
 */
class OpenTab : public TabState {
public:
    /**
     * @brief Constructor for the OpenTab class.
     * @param tab A pointer to the Tab associated with this state.
     */
    OpenTab(Tab* tab);

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
