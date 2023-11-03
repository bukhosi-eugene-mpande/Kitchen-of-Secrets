#ifndef CASHBILL_H
#define CASHBILL_H

#include "BillStrategy.h"

class CashBill : public BillStrategy {
    public:
        /**
         * @brief Construct a new Cash Bill object
         * 
         * @param billAmount 
         */
        CashBill(double billAmount);

        /**
         * @brief The customer(s) will pay depending on the customer's bill strategy. The customer(s)
         * strategy is to pay via cash.
         * 
         * @param amount 
         * @return json 
         */
        json pay(double amount);
};

#endif