#ifndef HAPPY_H
#define HAPPY_H

#include <memory>
#include <string>
#include "SatisfactionState.h"

/**
 * @brief The Happy class represents the state of a satisfied customer.
 * 
 * This class inherits from the SatisfactionState class and implements the behavior of a happy customer.
 */
class Happy : public SatisfactionState {
    public:
        /**
         * @brief Constructs a new Happy object.
         * 
         * @param customer A pointer to the customer object associated with this state.
         */
        Happy(CustomerTemplate* customer);

        /**
         * @brief Displays a message to the console indicating the customer is already happy.
         */
        void console() override;

        /**
         * @brief Changes the customer's state to Angry.
         */
        void anger() override;
};

#endif