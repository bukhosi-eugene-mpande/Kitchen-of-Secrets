#ifndef Unhappy_H
#define Unhappy_H

#include <string>
#include <algorithm>

#include "SatisfactionState.h"

/**
 * @brief The Unhappy class represents the state of a customer who is unhappy with the service.
 * 
 * This class inherits from the SatisfactionState class and provides implementations for the console() and anger() functions.
 */
class Unhappy : public SatisfactionState{
    public:
        /**
         * @brief Constructs a new Unhappy object.
         * 
         * @param customer A pointer to the customer object associated with this state.
         */
        Unhappy(CustomerTemplate* customer);

        /**
         * @brief Displays a console message to the customer.
         * 
         * This function overrides the console() function in the SatisfactionState class.
         */
        void console() override;

        /**
         * @brief Increases the customer's anger level.
         * 
         * This function overrides the anger() function in the SatisfactionState class.
         */
        void anger() override;

};

#endif