/**
 * @file CardBill.h
 * @brief Contains the declaration of the CardBill class, a concrete billing strategy.
 */

#ifndef CARDBILL_H
#define CARDBILL_H

#include "BillStrategy.h"
#include <string>

/**
 * @class CardBill
 * @brief Represents a concrete billing strategy for handling payments using a card.
 */
class CardBill : public BillStrategy {
public:
    /**
     * @brief Constructor for the CardBill class.
     * @param billAmount The total bill amount to be paid using a card.
     */
    CardBill(double billAmount);

    /**
     * @brief Perform a card payment for the bill.
     * @param amount The amount to be paid using a card.
     * @return A string indicating the result of the card payment.
     */
    std::string pay(double amount);
};

#endif
