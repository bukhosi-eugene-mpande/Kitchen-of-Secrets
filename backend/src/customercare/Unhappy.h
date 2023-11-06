/**
 * @file Unhappy.h
 * @brief Contains the declaration of the Unhappy class.
 */

#ifndef UNHAPPY_H
#define UNHAPPY_H

#include <string>
#include <algorithm>
#include "SatisfactionState.h"

/**
 * @class Unhappy
 * @brief Represents the unhappy satisfaction state of a customer.
 *
 * The Unhappy class is a derived class of SatisfactionState and represents the unhappy state of a customer. This state is associated with specific behaviors and interactions of an unhappy customer.
 */
class Unhappy : public SatisfactionState {
public:
    /**
     * @brief Constructor for the Unhappy class.
     * @param customer A pointer to the customer associated with this state.
     */
    Unhappy(CustomerTemplate* customer);

    /**
     * @brief Print a message or perform actions specific to an unhappy customer.
     */
    void console();

    /**
     * @brief Transition the customer's mood to an angry state.
     */
    void anger();
};

#endif
