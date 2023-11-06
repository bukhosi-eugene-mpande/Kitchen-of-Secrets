/**
 * @file Tab.h
 * @brief Contains the declaration of the Tab class.
 */

#ifndef TAB_H
#define TAB_H

#include "TabState.h"

/**
 * @class Tab
 * @brief Represents a tab with various states and methods for managing it.
 */
class Tab {
private:
    TabState *state; /**< Pointer to the current state of the tab. */

public:
    /**
     * @brief Constructor for the Tab class.
     */
    Tab();

    /**
     * @brief Close the tab.
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

    /**
     * @brief Set the state of the tab.
     * @param state The new state to set for the tab.
     */
    void setState(TabState *state);
};

#endif
