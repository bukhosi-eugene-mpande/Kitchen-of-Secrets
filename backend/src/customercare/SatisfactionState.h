/**
 * @file SatisfactionState.h
 * @brief Contains the declaration of the SatisfactionState class and its derived classes.
 */

#ifndef SATISFACTION_STATE_H
#define SATISFACTION_STATE_H

#include <memory>
#include <string>
#include "CustomerTemplate.h"

/**
 * @class SatisfactionState
 * @brief Represents the satisfaction state of a customer.
 *
 * The SatisfactionState class and its derived classes represent the various states of satisfaction of a customer. These states are used to model the customer's mood and interactions.
 */
class SatisfactionState {
protected:
    CustomerTemplate* customer; /**< A pointer to the customer associated with this state. */
    double discount; /**< The discount applied to the customer's bill based on their satisfaction state. */
    double tip; /**< The tip given by the customer based on their satisfaction state. */
    std::string stateName; /**< The name of the satisfaction state. */

public:
    /**
     * @brief Constructor for the SatisfactionState class.
     * @param stateName The name of the satisfaction state.
     * @param customer A pointer to the customer associated with this state.
     * @param discount The discount applied to the customer's bill based on their satisfaction state.
     * @param tip The tip given by the customer based on their satisfaction state.
     */
    SatisfactionState(std::string stateName, CustomerTemplate* customer, double discount, double tip);

    /**
     * @brief Set the customer associated with this satisfaction state.
     * @param customer A pointer to the customer.
     */
    void setCustomer(CustomerTemplate* customer);

    /**
     * @brief Get the customer associated with this satisfaction state.
     * @return A pointer to the customer.
     */
    CustomerTemplate* getCustomer();

    /**
     * @brief Print a message or perform actions specific to the customer's mood.
     */
    virtual void console() = 0;

    /**
     * @brief Transition the customer's mood to an angry state.
     */
    virtual void anger() = 0;

    /**
     * @brief Calculate the final bill amount for the customer based on their satisfaction state.
     * @param bill The original bill amount.
     * @return The modified bill amount.
     */
    double calculateBill(double bill);

    /**
     * @brief Get the tip amount based on the customer's satisfaction state.
     * @return The tip amount.
     */
    double getTip();

    /**
     * @brief Get the name of the satisfaction state.
     * @return The name of the state.
     */
    std::string getStateName();
};

#endif
