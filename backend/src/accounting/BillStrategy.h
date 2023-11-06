/**
 * @file BillStrategy.h
 * @brief Contains the declaration of the BillStrategy class.
 */

#ifndef BILLSTRATEGY_H
#define BILLSTRATEGY_H

#include <string>

/**
 * @class BillStrategy
 * @brief Represents a billing strategy for handling payments.
 */
class BillStrategy {
protected:
    double billAmount; ///< The total bill amount.

public:
    /**
     * @brief Constructor for the BillStrategy class.
     * @param billAmount The total bill amount to be paid.
     */
    BillStrategy(double billAmount);

    /**
     * @brief Perform a payment for the bill.
     * @param amount The amount to be paid.
     * @return A string indicating the result of the payment.
     */
    virtual std::string pay(double amount) = 0;
};

#endif
