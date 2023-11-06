/**
 * @file Billing.h
 * @brief Contains the declaration of the Billing class.
 */

#ifndef BILLING_H
#define BILLING_H

#include "BillStrategy.h"

/**
 * @class Billing
 * @brief Manages billing using a specified strategy.
 */
class Billing {
private:
    BillStrategy *billStrategy; ///< The billing strategy to be used.

public:
    /**
     * @brief Constructor for the Billing class.
     * @param billStrategy The billing strategy to be used.
     */
    Billing(BillStrategy *billStrategy);

    /**
     * @brief Make a payment for a bill.
     * @param amount The amount to be paid.
     * @return A string indicating the result of the payment.
     */
    std::string pay(double amount);
};

#endif
