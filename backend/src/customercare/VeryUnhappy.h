/**
 * @file VeryUnhappy.h
 * @brief Contains the declaration of the VeryUnhappy class.
 */

#ifndef VERYUNHAPPY_H
#define VERYUNHAPPY_H

#include <memory>
#include <string>
#include "SatisfactionState.h"

/**
 * @class VeryUnhappy
 * @brief Represents the very unhappy satisfaction state of a customer.
 *
 * The VeryUnhappy class is a derived class of SatisfactionState and represents the very unhappy state of a customer. This state is associated with specific behaviors and interactions of a very unhappy customer.
 */
class VeryUnhappy : public SatisfactionState {
public:
    /**
     * @brief Constructor for the VeryUnhappy class.
     * @param customer A pointer to the customer associated with this state.
     */
    VeryUnhappy(CustomerTemplate* customer);

    /**
     * @brief Print a message or perform actions specific to a very unhappy customer.
     */
    void console();

    /**
     * @brief Transition the customer's mood to an angry state.
     */
    void anger();
};

#endif
