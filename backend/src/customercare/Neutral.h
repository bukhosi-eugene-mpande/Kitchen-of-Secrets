/**
 * @file Neutral.h
 * @brief Contains the declaration of the Neutral class.
 */

#ifndef NEUTRAL_H
#define NEUTRAL_H

#include <memory>
#include <string>
#include <algorithm>
#include "SatisfactionState.h"

/**
 * @class Neutral
 * @brief Represents a state of a customer in a neutral mood.
 *
 * The Neutral class is a derived state class representing the neutral mood of a customer. In this state, the customer's satisfaction is neither extremely positive nor negative.
 */
class Neutral : public SatisfactionState {
public:
    /**
     * @brief Constructor for the Neutral class.
     * @param customer A pointer to the customer associated with this state.
     */
    Neutral(CustomerTemplate* customer);

    /**
     * @brief Print a message to the console indicating the customer's mood.
     */
    void console();

    /**
     * @brief Transition the customer's mood to an angry state.
     */
    void anger();
};

#endif
