/**
 * @file MultiBill.h
 * @brief Contains the declaration of the MultiBill class.
 */

#ifndef MULTIBILL_H
#define MULTIBILL_H

#include "BillStrategy.h"

/**
 * @class MultiBill
 * @brief Represents a billing strategy for multiple payment types.
 */
class MultiBill : public BillStrategy {
public:
    /**
     * @brief Constructor for the MultiBill class.
     * @param billAmount The total bill amount to be paid.
     */
    MultiBill(double billAmount);

    /**
     * @brief Pay a specified amount using the multi-payment strategy.
     * @param amount The amount to be paid.
     * @return A message indicating the result of the payment.
     */
    std::string pay(double amount);
};

#endif
