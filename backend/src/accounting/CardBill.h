#ifndef CARDBILL_H
#define CARDBILL_H

#include "BillStrategy.h"
#include <string>

/**
 * @brief The CardBill class represents a billing strategy for credit card payments.
 */
class CardBill : public BillStrategy{
    public:
        /**
         * @brief Constructs a CardBill object with the specified bill amount.
         * 
         * @param billAmount The amount of the bill.
         */
        CardBill(double billAmount);

        /**
         * @brief Pays the specified amount using the credit card.
         * 
         * @param amount The amount to pay.
         * @return A string representing the payment status.
         */
        std::string pay(double amount);
};

#endif