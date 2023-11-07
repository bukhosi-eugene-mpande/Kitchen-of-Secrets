#ifndef VeryUnhappy_H
#define VeryUnhappy_H

#include <memory>
#include <string>
#include "SatisfactionState.h"

/**
 * @brief The VeryUnhappy class represents the state of a customer who is very unhappy with the service.
 * 
 * This class inherits from the SatisfactionState class and provides implementations for the console() and anger() functions.
 */
class VeryUnhappy : public SatisfactionState{
    public:
        /**
         * @brief Constructs a new VeryUnhappy object.
         * 
         * @param customer A pointer to the customer object associated with this state.
         */
        VeryUnhappy(CustomerTemplate* customer);

        /**
         * @brief Displays a console message to the customer.
         * 
         * This function overrides the console() function of the base class.
         */
        void console() override;

        /**
         * @brief Increases the customer's anger level.
         * 
         * This function overrides the anger() function of the base class.
         */
        void anger() override;
};
#endif