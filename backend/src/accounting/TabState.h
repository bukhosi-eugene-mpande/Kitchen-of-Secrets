/**
 * @file TabState.h
 * @brief Contains the declaration of the TabState class and its derived classes.
 */

#ifndef TABSTATE_H
#define TABSTATE_H

#include <vector>
#include "../json.hpp"

using json = nlohmann::json;

class Tab;

/**
 * @class TabState
 * @brief Represents the state of a tab and provides methods to manipulate it.
 */
class TabState {
protected:
    Tab *tab; /**< Pointer to the tab associated with this state. */
    std::vector<double> orders; /**< A vector of order costs. */

public:
    /**
     * @brief Constructor for the TabState class.
     * @param tab Pointer to the tab associated with this state.
     */
    TabState(Tab *tab);

    /**
     * @brief Close the tab.
     * @return A message indicating the result of closing the tab.
     */
    virtual std::string closeTab() = 0;

    /**
     * @brief Get the total bill amount for the tab.
     * @return The total bill amount for the tab.
     */
    virtual double getBillTotal() = 0;

    /**
     * @brief Add the cost of an order to the tab.
     * @param cost The cost of the order to be added.
     * @return A message indicating the result of adding the order cost.
     */
    virtual std::string addOrderCost(double cost) = 0;
};

#endif
