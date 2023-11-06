/**
 * @file CashBill.h
 * @brief Contains the declaration of the CashBill class, a concrete billing strategy.
 */

#ifndef CASHBILL_H
#define CASHBILL_H

#include "BillStrategy.h"

/**
 * @class CashBill
 * @brief Represents a concrete billing strategy for handling payments using cash.
 */
class CashBill : public BillStrategy {
public:
    /**
     * @brief Constructor for the CashBill class.
     * @param billAmount The total bill amount to be paid using cash.
     */
    CashBill(double billAmount);

    /**
     * @brief Perform a cash payment for the bill.
     * @param amount The amount to be paid using cash.
     * @return A string indicating the result of the cash payment.
     */
    std::string pay(double amount);
};

#endif
