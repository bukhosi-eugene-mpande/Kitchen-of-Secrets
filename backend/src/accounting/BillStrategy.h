#ifndef BILLSTRATEGY_H
#define BILLSTRATEGY_H

#include <string>

/**
 * @brief The BillStrategy class is an abstract base class that defines the interface for different billing strategies.
 */
class BillStrategy {
    protected:
        double billAmount; /**< The total amount of the bill. */

    public:
        /**
         * @brief Constructs a new BillStrategy object with the specified bill amount.
         * 
         * @param billAmount The total amount of the bill.
         */
        BillStrategy(double billAmount);

        /**
         * @brief Calculates the payment amount based on the billing strategy.
         * 
         * @param amount The amount to be paid.
         * @return std::string A message indicating the payment status.
         */
        virtual std::string pay(double amount) = 0;
};

#endif