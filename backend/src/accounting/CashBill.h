#ifndef CASHBILL_H
#define CASHBILL_H

#include "BillStrategy.h"

/**
 * @brief The CashBill class represents a bill strategy for cash payments.
 */
class CashBill : public BillStrategy{
    public:
        /**
         * @brief Constructs a new CashBill object.
         * 
         * @param billAmount The amount of the bill.
         */
        CashBill(double billAmount);

        /**
         * @brief Pays the bill with the given amount.
         * 
         * @param amount The amount to pay.
         * @return std::string A message indicating the payment status.
         */
        std::string pay(double amount);
};

#endif