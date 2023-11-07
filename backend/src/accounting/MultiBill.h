#ifndef MULTIBILL_H
#define MULTIBILL_H

#include "BillStrategy.h"

/**
 * @brief The MultiBill class represents a billing strategy where the customer pays a fixed amount for multiple items.
 */
class MultiBill : public BillStrategy
{
    public:
        /**
         * @brief Constructs a MultiBill object with the specified bill amount.
         * 
         * @param billAmount The fixed amount to be paid for multiple items.
         */
        MultiBill(double billAmount);

        /**
         * @brief Calculates the payment amount based on the specified amount and the fixed bill amount.
         * 
         * @param amount The total amount to be paid.
         * @return A string representing the payment details.
         */
        std::string pay(double amount);
};

#endif