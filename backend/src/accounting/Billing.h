#ifndef BILLING_H
#define BILLING_H

#include "BillStrategy.h"

/**
 * @brief The Billing class represents a billing system that uses a BillStrategy to calculate the amount to be paid.
 */
class Billing{
    private:
        BillStrategy *billStrategy;

    public:
        /**
         * @brief Constructs a new Billing object with the given BillStrategy.
         * 
         * @param billStrategy The BillStrategy to use for calculating the amount to be paid.
         */
        Billing(BillStrategy *billStrategy);

        /**
         * @brief Calculates the amount to be paid using the BillStrategy and returns a string representation of the payment.
         * 
         * @param amount The amount to be paid.
         * @return A string representation of the payment.
         */
        std::string pay(double amount);
};

#endif