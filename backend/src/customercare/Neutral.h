#ifndef Neutral_H
#define Neutral_H

#include <memory>
#include <string>
#include <algorithm>
#include "SatisfactionState.h"
/**
 * @brief The Neutral class represents the neutral satisfaction state of a customer.
 * 
 * This class inherits from the SatisfactionState class and implements the console() and anger() functions.
 */
class Neutral : public SatisfactionState{
    public:
        /**
         * @brief Constructs a new Neutral object.
         * 
         * @param customer A pointer to the customer object.
         */
        Neutral(CustomerTemplate* customer);

        /**
         * @brief Displays a console message for the neutral state.
         */
        void console();

        /**
         * @brief Changes the customer's state to Anger.
         */
        void anger();
};

#endif