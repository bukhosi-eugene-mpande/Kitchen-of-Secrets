/**
 * @file Happy.h
 * @brief Contains the declaration of the Happy class.
 */

#ifndef HAPPY_H
#define HAPPY_H

#include <memory>
#include <string>
#include "SatisfactionState.h"

/**
 * @class Happy
 * @brief Represents a state of a happy customer.
 *
 * The Happy class is a derived state class representing the happy state of a customer. In this state, the customer is satisfied and content with their dining experience.
 */
class Happy : public SatisfactionState {
public:
    /**
     * @brief Constructor for the Happy class.
     * @param customer A pointer to the customer associated with this state.
     */
    Happy(CustomerTemplate* customer);

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
